/****************************************Copyright (c)**************************************************
**                               ������������Ƭ����չ���޹�˾
**                                     ��    ��    ��
**                                        ��Ʒһ�� 
**
**                                 http://www.zlgmcu.com
**
**--------------�ļ���Ϣ--------------------------------------------------------------------------------
**��   ��   ��: uart0.c
**��   ��   ��: ������
**����޸�����: 2003��7��5��
**��        ��: ��COS-II��LPC210x��SPI��ģʽ�ײ����� 
**              
**--------------��ʷ�汾��Ϣ----------------------------------------------------------------------------
** ������: ������
** ��  ��: v1.0
** �ա���: 2003��7��4��
** �衡��: ԭʼ�汾
**
**--------------��ǰ�汾�޶�------------------------------------------------------------------------------
** �޸���: ������
** �ա���: 2003��7��11��
** �衡��: ����ע��
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
** ��������: SPIInit
** ��������: ��ʼ��SPI����Ϊ��ģʽ
** �䡡��: Fdiv�������趨����Ƶ�ʣ�����Ƶ��=Fpclk/Fdiv)
**
** �䡡��:TRUE  :�ɹ�
**        FALSE:ʧ��
** ȫ�ֱ���: UseSPITaskPro
** ����ģ��: OSMboxCreate��OSSemCreate
**
** ������: ������
** �ա���: 2003��7��4��
**-------------------------------------------------------------------------------------------------------
** �޸���: ������
** �ա���: 2003��7��11��
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
    SSPCR0 = (0x00 << 8) |              // SCR  ����SSIʱ�ӷ�Ƶ
             (0x01 << 7) |              // CPHA ʱ�������λ,��SPIģʽ��Ч 
             (0x01 << 6) |              // CPOL ʱ���������,��SPIģʽ��Ч
             (0x00 << 4) |              // FRF  ֡/��ʽ 00=SPI,01=SSI,10=Microwire,11=����
             (0x07 << 0);               // DSS  ���ݳ���,0000-0010=����,0011=4λ,0111=8λ,1111=16λ
	
    SSPCR1 = (0x00 << 3) |              // SOD  �ӻ��������,1=��ֹ,0=����
             (0x00 << 2) |              // MS   ����ѡ��,0=����,1=�ӻ�
             (0x01 << 1) |              // SSE  SSPʹ��,1=����SSP�������豸ͨ��
             (0x00 << 0);               // LBM  ��дģʽ 	
	
	SSPCPSR = Fdiv;                    /* ��Ƶֵ */


	SSPICR  = 0x03;                     // �ж�����Ĵ���
	

	SSPClearfifo();

	

    UseSPITaskPro = OS_PRIO_SELF;               /* �������񲻰��չ淶��д�����ʹ����SPI���� */
    SSPReviceMbox = OSMboxCreate(NULL);         /* �����жϷ����յ������� */
    if (SSPReviceMbox == NULL)
    {
        return FALSE;
    }
    SSPSem = OSSemCreate(1);                    /* ���ڻ������SPI���� */
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
** ��������: GetSPIFlag
** ��������: ��ȡSPI״̬ 
** �䡡��: ��
**
** �䡡��:0  :����
**        1 :æ
** ȫ�ֱ���: ��
** ����ģ��: ��
**
** ������: ������
** �ա���: 2003��7��5��
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
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
** ��������: SPIStart
** ��������: ��ʼ����SPI 
** �䡡��: ��
**
** �䡡��:TRUE  :�ɹ�
**        FALSE:ʧ��
** ȫ�ֱ���: ��
** ����ģ��: ��
**
** ������: ������
** �ա���: 2003��7��5��
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
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
** ��������: SPIRW
** ��������: ��дSPI 
** �䡡��: Rt  ��ָ�򷵻�ֵ�洢λ��
**        Data�����͵����� 
** �䡡��:TRUE  :�ɹ�
**        FALSE:ʧ��
** ȫ�ֱ���: UseSPITaskPro
** ����ģ��: OSMboxPend,GetOSPrioCur
**
** ������: ������
** �ա���: 2003��7��5��
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
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
    	while( (SSPSR & 0x01) == 0 );	    // �ȴ�TFE��λ��������FIFO��
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
** ��������: SPIEnd
** ��������: ����SPI����
** �䡡��: ��
**        
** �䡡��:TRUE  :�ɹ�
**        FALSE:ʧ��
** ȫ�ֱ���: UseSPITaskPro
** ����ģ��: OSSemPost,GetOSPrioCur
**
** ������: ������
** �ա���: 2003��7��5��
**-------------------------------------------------------------------------------------------------------
** �޸���:
** �ա���:
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
** ��������: SPI_Exception
** ��������: SPI�жϷ������
** �䡡��: ��
**
** �䡡��: ��
**         
** ȫ�ֱ���: ��
** ����ģ��: OSMboxPost
**
** ������: ������
** �ա���: 2003��7��5��
**-------------------------------------------------------------------------------------------------------
** �޸���: 
** �ա���: 
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
    VICVectAddr = 0;            // ֪ͨ�жϿ������жϽ���
//    OS_EXIT_CRITICAL();
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
