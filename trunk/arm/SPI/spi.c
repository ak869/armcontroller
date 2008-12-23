/****************************************Copyright (c)**************************************************
**                               广州周立功单片机发展有限公司
**                                     研    究    所
**                                        产品一部 
**
**                                 http://www.zlgmcu.com
**
**--------------文件信息--------------------------------------------------------------------------------
**文   件   名: uart0.c
**创   建   人: 陈明计
**最后修改日期: 2003年7月5日
**描        述: μCOS-II下LPC210x的SPI主模式底层驱动 
**              
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人: 陈明计
** 版  本: v1.0
** 日　期: 2003年7月4日
** 描　述: 原始版本
**
**--------------当前版本修订------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月11日
** 描　述: 更正注释
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

#define IN_SPI
#include "config.h"

#ifndef  SPI_MOD
#define SPI_MOD     0
#endif 

uint8 	*SSP_SendBuf;
uint8	*SSP_RecvBuf;


static uint16  SSP_RecvBufPos;
static uint16	SSP_SendBufPos;
static int SSP_Opertion;
static uint16 	SSP_SendSize;
static uint16 SSP_SendCount;
static uint16 SSP_RecvCount;
static OS_EVENT *SSPReviceMbox;
static uint16 SSP_ClearFifo;
static OS_EVENT *SSPSem;
static uint8 UseSPITaskPro;
static uint8 dev_type;
/*********************************************************************************************************
** 函数名称: SPIInit
** 功能描述: 初始化SPI总线为主模式
** 输　入: Fdiv：用于设定总线频率（总线频率=Fpclk/Fdiv)
**
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: UseSPITaskPro
** 调用模块: OSMboxCreate，OSSemCreate
**
** 作　者: 陈明计
** 日　期: 2003年7月4日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月11日
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/


#define SSP_RXFIFO				0x6
#define SSP_TXFIFO				0x8
void SSPClearfifo(void);
uint8 SSPInit(uint8 Fdiv)
{
	PINSEL1 = (PINSEL1 & (~(0xFF << 2))) | (0x2A << 2);	
	IOSET = PIN_MCS;
	IODIR |= PIN_MCS;
	SSPIMSC = 0x0;	
    SSPCR0 = (0x00 << 8) |              // SCR  设置SSI时钟分频
             (0x01 << 7) |              // CPHA 时钟输出相位,仅SPI模式有效 
             (0x01 << 6) |              // CPOL 时钟输出极性,仅SPI模式有效
             (0x00 << 4) |              // FRF  帧/格式 00=SPI,01=SSI,10=Microwire,11=保留
             (0x07 << 0);               // DSS  数据长度,0000-0010=保留,0011=4位,0111=8位,1111=16位
	
    SSPCR1 = (0x00 << 3) |              // SOD  从机输出禁能,1=禁止,0=允许
             (0x00 << 2) |              // MS   主从选择,0=主机,1=从机
             (0x01 << 1) |              // SSE  SSP使能,1=允许SSP与其它设备通信
             (0x00 << 0);               // LBM  回写模式 	
	
	SSPCPSR = Fdiv;                    /* 分频值 */


	SSPICR  = 0x03;                     // 中断清除寄存器
	

	SSPClearfifo();

	

    UseSPITaskPro = OS_PRIO_SELF;               /* 避免任务不按照规范编写程序而使访问SPI混乱 */
    SSPReviceMbox = OSMboxCreate(NULL);         /* 用于中断返回收到的数据 */
    if (SSPReviceMbox == NULL)
    {
        return FALSE;
    }
    SSPSem = OSSemCreate(1);                    /* 用于互斥访问SPI总线 */
    if (SSPSem != NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*********************************************************************************************************
** 函数名称: GetSPIFlag
** 功能描述: 获取SPI状态 
** 输　入: 无
**
** 输　出:0  :空闲
**        1 :忙
** 全局变量: 无
** 调用模块: 无
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 GetSPIFlag(void)
{
    OS_SEM_DATA SemData;
    
    if (OSSemQuery(SSPSem, &SemData) == OS_NO_ERR)
    {
        if (SemData.OSCnt != 0)
        {
            return 0;
        }
    }
    return 1;
}


/*********************************************************************************************************
** 函数名称: SPIStart
** 功能描述: 开始访问SPI 
** 输　入: 无
**
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: 无
** 调用模块: 无
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 SSPStart(void)
{
    uint8 err;

    OSSemPend(SSPSem, 0, &err);
    UseSPITaskPro = GetOSPrioCur();

    SSPIMSC = 0;
    return TRUE;
}

/*********************************************************************************************************
** 函数名称: SPIRW
** 功能描述: 读写SPI 
** 输　入: Rt  ：指向返回值存储位置
**        Data：发送的数据 
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: UseSPITaskPro
** 调用模块: OSMboxPend,GetOSPrioCur
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 SSPRW(uint8 *Rt, uint8 Data)
{
    uint8 temp;
    
    temp = GetOSPrioCur();
    if (temp == UseSPITaskPro)
    {
    	SSPIMSC = 0;
    	SSPDR = Data;
    	while( (SSPSR & 0x01) == 0 );	    // 等待TFE置位，即发送FIFO空
        *Rt = SSPDR;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

uint8 SSPWait(uint16 fifo_count, uint16 sendflag, uint16 nSize)
{
    uint8 temp,err;
    temp = GetOSPrioCur();
    if (temp == UseSPITaskPro)
    {	
    	SSP_Opertion = 0;
    	SSP_SendCount = fifo_count;
    	SSP_ClearFifo = sendflag;
    	SSP_RecvCount = 0;
    	SSP_RecvBufPos = 0;
    	SSP_SendBufPos = 0;
    	SSP_SendSize = nSize;
    	if( sendflag > fifo_count )
    		SSPIMSC = 0x08;
    	else if( nSize < 8)
    		SSPIMSC = 0x02;
    		else SSPIMSC = 0x04;
    	
		OSMboxPend(SSPReviceMbox, 0, &err);
        return TRUE;
    }
    return FALSE;
}

uint16 SSPCompWait(uint32 compvalue,uint16 nSize)
{
    uint8 temp;
    uint32 err;
    temp = GetOSPrioCur();
    if (temp == UseSPITaskPro)
    {	
    	SSP_Opertion = 1;
    	SSP_SendCount = 8;
		SSP_ClearFifo = 4;
    	SSP_RecvCount = 0;
    	SSP_RecvBufPos = 0;
    	SSP_SendBufPos = 0;
    	SSP_SendSize = nSize;
   		SSPIMSC = 0x06;
    	
		OSMboxPend(SSPReviceMbox, 0, (void *)err);
        return (uint16)err;
    }
    return (uint16)err;
}

void SSPClearfifo(void)
{
	uint8 temp;
	
	temp = SSPSR;
	while( !(temp & 0x1) )
		temp = SSPSR;
	
	temp = SSPSR;
	while( temp & 0x4 )
	{
		temp = SSPDR;
		temp = SSPSR;
	}	
}

/*
uint8 SPIRW2(void)
{
    uint8 temp,err;

    temp = GetOSPrioCur();
    if (temp == UseSPITaskPro)
    {

	CmdCount = 0;
	SendCount = 0;
	RecvCount = 0;
	
	SPI_CmdSize--;
	CmdCount++;
	SPI_SPDR = SPI_CMD[0];
	OSMboxPend(SPIReviceMbox, 0, &err);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
*/

/*********************************************************************************************************
** 函数名称: SPIEnd
** 功能描述: 访问SPI结束
** 输　入: 无
**        
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: UseSPITaskPro
** 调用模块: OSSemPost,GetOSPrioCur
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 SSPEnd(void)
{
    uint8 temp;
    
    temp = GetOSPrioCur();
    if (temp == UseSPITaskPro)
    {
        UseSPITaskPro = OS_PRIO_SELF;
        OSSemPost(SSPSem);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*
	SSP_SendCount
	
	SSP_RecvFlag = SSP_SendSize
	SSP_RecvSize
	SSP_RecvCount
	
	status = send
	
	status = recv

*/


/*********************************************************************************************************
** 函数名称: SPI_Exception
** 功能描述: SPI中断服务程序
** 输　入: 无
**
** 输　出: 无
**         
** 全局变量: 无
** 调用模块: OSMboxPost
**
** 作　者: 陈明计
** 日　期: 2003年7月5日
**-------------------------------------------------------------------------------------------------------
** 修改人: 
** 日　期: 
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/



/*
	clear fifo
	
	switch(isr)
	{
		case Sendfifo_empty_half:
			i = SSP_SendSize - SSP_SendCount;
			if( i == 0 )
			{
				SSP_nStatus = SSP_END;
				SSPIMSC = 0x2;
				break;
			}
			else if( i > 4 )
				i = 4;
		 	goto SendFifo_2;
		 	break;
		 case RecvTimeOut:
		 	if( SSP_ClearFifo > 0 )
		 	{
		 		i = SSP_ClearFifo;
		 		goto ClearFifo;	 		
		 	}
		 	i = SSP_SendSize - SSP_RecvCount;
		 	if( i > 0 )
		 	{
		 		goto RecvFifo;	
		 	}
		 	OSMboxPost(SSPReviceMbox, SSP_RecvBuf);
		 	break;
		 case Recvfifo_full_half:
				n = i = SSP_ClearFifo;
				if( SSP_ClearFifo > 4 )
				{
					n = i = 4;
				}
				goto ClearFifo_2;
				i = 4;
				goto RecvFifo;
				i = SSP_SendSize - SSP_RecvCount;
				if( i == 0 )
					OSMboxPost(
				else
				{
					if( i < 4 )
					SSPIMSC = 0x2;
					
					i = SSP_SendSize - SSP_SendCount;
					if( i > 4 )
						i = 4;
					goto SendFifo;
	
				}
		 	break;
		 
	}
	
	SendFifo_2:
			SSP_SendCount += i;
			SSP_RecvCount += i;
			SSP_ClearFifo -= i;			
			while(i)
			{
		 		temp = SSPDR;
		 		SSPDR = SSP_SendBuf[SSP_SendBufPos];
		 		SSP_SendBufPos++;
		 		i--;
		 	}
	
 	ClearFifo_2:
		SSP_RecvCount += i;
		SSP_ClearFifo -= i;
		while( i )
		{
			temp = SSPDR;
			i--;
		}
				
	RecvFifo_2:
		SSP_RecvCount += i;
		while( i )
		{
			SSP_RecvBuf[SSP_RecvBufPos++] = SSPDR;
			SSP_RecvBufPos++;
			i--;
		}		
	
	ClearFifo:
		SSP_RecvCount += i;
		SSP_ClearFifo -= i;
		temp = SSPSR;
		while( (temp & 0x4) && i )
		{
			temp = SSPDR;
			temp = SSPSR;
			i--;
		}		
		SSP_RecvCount -= i;
		SSP_ClearFifo += i;
		
	RecvFifo:
		SSP_RecvCount += i;
		temp = SSPSR;
		while( (temp & 0x4) && i )
		{
			SSP_RecvBuf[SSP_RecvBufPos++] = SSPDR;
			SSP_RecvBufPos++;
			temp = SSPSR;
			i--;
		}		
		SSP_RecvCount -= i;
	
	SendFifo:
		SSP_SendCount +=i;
		while( i )
		{
			SSPDR = 0xff;
			i--;
		}

*/

void SSP_Exception(void)
{
    uint8 temp,isr;
    uint32 id;
    int i;
    
 //   OS_ENTER_CRITICAL();
    isr = SSPMIS;
    SSPICR  = 0x03;    
	if( isr & 0x8 )
	{	
		i = SSP_SendSize - SSP_SendCount;
		if( i == 0 )
		{
			SSPIMSC = 0x2;
			goto Exit_SSP_Exception;
		}
		else if( i > 4 )
			i = 4;
		SSP_SendCount += i;
		SSP_RecvCount += i;
		SSP_ClearFifo -= i;			
		while(i)
		{
			temp = SSPDR;
			SSPDR = SSP_SendBuf[SSP_SendBufPos];
			SSP_SendBufPos++;
			i--;
		}
	}else if( isr & 0x2 )
    {
		if( SSP_ClearFifo > 0 )
		{
			i = SSP_ClearFifo;

			SSP_RecvCount += i;
			SSP_ClearFifo -= i;
			temp = SSPSR;
			while( (temp & 0x4) && i )
			{
				temp = SSPDR;
				temp = SSPSR;
				i--;
			}		
			SSP_RecvCount -= i;
			SSP_ClearFifo += i; 		
		}
		i = SSP_SendSize - SSP_RecvCount;
		if( i > 0 )
		{
			SSP_RecvCount += i;
			temp = SSPSR;
			while( (temp & 0x4) && i )
			{
				SSP_RecvBuf[SSP_RecvBufPos] = SSPDR;//SSP_RecvBufPos

				SSP_RecvBufPos++;
				temp = SSPSR;
				i--;
			}		
			SSP_RecvCount -= i;	
		}
		SSPICR = 0x2;
		SSPIMSC = 0;
		OSMboxPost(SSPReviceMbox, SSP_RecvBuf);    	
    }else if( isr & 0x4 )
    {
    	if( SSP_ClearFifo )
    	{
			i = SSP_ClearFifo;
			if( i > 4 )
			{
				i = 4;
			}
			//ClearFifo_2
			SSP_RecvCount += i;
			SSP_ClearFifo -= i;
			while( i )
			{
				temp = SSPDR;
				i--;
			}
		}else
		{
			i = 4;
			SSP_RecvCount += i;
			while( i )
			{
				SSP_RecvBuf[SSP_RecvBufPos] = SSPDR;
				SSP_RecvBufPos++;
				i--;
			}		
			SSP_RecvCount -= i;

		}
		i = SSP_SendSize - SSP_RecvCount;
		if( i == 0 )
		{
			SSPIMSC = 0;
			OSMboxPost(SSPReviceMbox, SSP_RecvBuf);
		} 
		else
		{
			if( i < 4 )
				SSPIMSC = 0x2;
					
			i = SSP_SendSize - SSP_SendCount;
			if( i > 4 )
				i = 4;
			SSP_SendCount +=i;
			while( i )
			{
				SSPDR = 0xff;
				i--;
			}
		}   
    
    }

/*		    	temp = SSPSR;
		    	t = (uint8 *)&id;
		    	t += 3;
			    while( i && SSP_RecvCount < SSP_SendSize )
			    {    	
			    	*t = SSPDR;
			    	id >>= 8;
			    	SSP_CompCount++;
			    	if( SSP_CompCount == 4 )
			    	{
			    		if( id == SSP_CompVaule )
			    		{
			    			OSMboxPost(SSPReviceMbox,  (void *)(SSP_RecvBufPos + 1) );
			    			SSPIMSC = 0;
			    			goto Exit_SSP_Exception;
			    		}
			    		SSP_CompCount = 0;
			    	}
			    	SSP_RecvBufPos++;
			    	SSP_RecvCount++;
			    	i--;
			    }
*/			    

Exit_SSP_Exception:
    VICVectAddr = 0;            // 通知中断控制器中断结束
//    OS_EXIT_CRITICAL();
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
