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
**最后修改日期: 2003年7月4日
**描        述: μCOS-II下LPC210x的UART0底层驱动 
**              
**--------------历史版本信息----------------------------------------------------------------------------
** 创建人: 陈明计
** 版  本: v1.0
** 日　期: 2003年7月4日
** 描　述: 原始版本
**
**------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 版  本: v1.1
** 日　期: 2003年7月21日
** 描　述: 根据正式文档更改寄存器名
**
**--------------当前版本修订------------------------------------------------------------------------------
** 修改人: 
** 日　期: 
** 描　述: 
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

#define IN_UART1
#include "config.h"

static int32 UART1SendBuf[UART1_SEND_QUEUE_LENGTH/sizeof(int32)]; // 9600 - 20

static OS_EVENT *Uart1Sem;

/*********************************************************************************************************
** 函数名称: Uart0WriteFull
** 功能描述: 数据队列写满处理程序 
** 输　入: Buf:指向数据队列
**        Data:将要入队的数据
**        Mod: 入队方式
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: 无
** 调用模块: 无
**
** 作　者: 陈明计
** 日　期: 2003年7月4日
**-------------------------------------------------------------------------------------------------------
** 修改人:
** 日　期:
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
    uint8 Uart1WriteFull(DataQueue *Buf, QUEUE_DATA_TYPE Data, uint8 Mod)
{
    uint16 temp;
    
    Mod = Mod;
    
    temp = QueueSize((void *)Buf);
    while (temp <= QueueNData((void *)Buf))         /* 等待数据队列不满 */
    {
        OSTimeDly(2);
    }
    return QueueWrite((void *)Buf, Data);           /* 数据重新入队 */
}

/*********************************************************************************************************
** 函数名称: UART0Init
** 功能描述: 初始化UART0 
** 输　入: bps：波特率
**
** 输　出:TRUE  :成功
**        FALSE:失败
** 全局变量: Uart0Sem
** 调用模块: QueueCreate,OSSemCreate
**
** 作　者: 陈明计
** 日　期: 2003年7月4日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月8日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月21日
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        uint8 UART1Init(uint32 bps)
{
    uint16 Fdiv;
    
    PINSEL0 = (PINSEL0 & 0xfffffff0) | 0x05;    /* 选择管脚为UART1 */

    U1LCR = 0x80;                               /* 允许访问分频因子寄存器 */
    Fdiv = (Fpclk / 16) / bps;                  /* 设置波特率 */
    U1DLM = Fdiv / 256;							
	U1DLL = Fdiv % 256;						
    U1LCR = 0x03;                               /* 禁止访问分频因子寄存器 */
                                                /* 且设置为8,1,n */
	U1IER = 0x05;                               /* 允许接收和发送中断 */
    U1FCR = 0x87;                               /* 初始化FIFO */
    
    
    if (QueueCreate((void *)UART1SendBuf,
                     sizeof(UART1SendBuf),
                     NULL,
                     (uint8 (*)())Uart1WriteFull)
                     == NOT_OK)
    {
        return FALSE;
    }
    Uart1Sem = OSSemCreate(0);
    if (Uart1Sem != NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

} 

/*********************************************************************************************************
** 函数名称: UART0Putch
** 功能描述: 发送一个字节数据
** 输　入: Data：发送的数据数据
** 输　出:无
** 全局变量: 无
** 调用模块: 无
**
** 作　者: 陈明计
** 日　期: 2003年7月4日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月8日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月21日
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
        void UART1Putch(uint8 Data)
{
    uint8 temp;
    
    OS_ENTER_CRITICAL();
    QueueWrite((void *)UART1SendBuf, Data);         /* 数据入队 */
    if ((U1LSR & 0x00000020) != 0)
    {                                               /* UART0发送保持寄存器空 */
        QueueRead(&temp, UART1SendBuf);             /* 发送最初入队的数据 */
        U1THR = temp;
        U1IER = U1IER | 0x02;                       /* 允许发送中断 */
    }
    OS_EXIT_CRITICAL();
} 

/*********************************************************************************************************
** 函数名称: UART0Write
** 功能描述: 发送多个字节数据
** 输　入: Data:发送数据存储位置
**        NByte:发送数据个数
** 输　出:无
** 全局变量: 无
** 调用模块: UART0Putch
**
** 作　者: 陈明计
** 日　期: 2003年7月4日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月8日
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void UART1Write(uint8 *Data, uint16 NByte)
{
    OS_ENTER_CRITICAL();
    while (NByte-- > 0)
    {
        UART0Putch(*Data++);
    }
    OS_EXIT_CRITICAL();
} 

/*********************************************************************************************************
** 函数名称: UART0Getch
** 功能描述: 接收一个字节
** 输　入: 无
** 输　出: 接收到的数据
** 全局变量: 无
** 调用模块: 无
**
** 作　者: 陈明计
** 日　期: 2003年7月4日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月8日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月21日
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
uint8 UART1Getch(void)
{
    uint8 err;

    OS_ENTER_CRITICAL();
    while ((U1LSR & 0x00000001) == 0)
    {                                           /* 没有收到数据 */
        U1IER = U1IER | 0x01;                   /* 允许接收中断 */
        OSSemPend(Uart1Sem, 0, &err);           /* 等待接收数据 */
    }
    err = U1RBR;                                /* 读取收到的数据 */
    OS_EXIT_CRITICAL();
    return err;
}
uint8 UART1GetchForWait(uint8 time, uint8 *err)
{
	uint8 dat;
    OS_ENTER_CRITICAL();
    *err = 0;
    if ((U1LSR & 0x00000001) == 0)
    {                                           /* 没有收到数据 */
        U1IER = U1IER | 0x01;                   /* 允许接收中断 */
        OSSemPend(Uart1Sem, time, err);           /* 等待接收数据 */
    }
    dat = U1RBR;                                /* 读取收到的数据 */
    OS_EXIT_CRITICAL();
    return dat;
}
/*
void UART1RXLineClear(void)
{
	uint8 err;
	OS_ENTER_CRITICAL();

	while(1)
	{
		if( (U0LSR & 0x00000001) == 0 )
		{
        	U0FCR |= 0x2; 
    		OSTimeDly(2);
        }else
        	break;
//        err = U0RBR;
	}
	OS_ENTER_CRITICAL();	
} 
*/
/*********************************************************************************************************
** 函数名称: UART0_Exception
** 功能描述: UART0中断服务程序
** 输　入: 无
**
** 输　出: 无
**         
** 全局变量: 无
** 调用模块: QueueRead,OSSemPost
**
** 作　者: 陈明计
** 日　期: 2003年7月4日
**-------------------------------------------------------------------------------------------------------
** 修改人: 陈明计
** 日　期: 2003年7月21日
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
void UART1_Exception(void)
{
    uint8 IIR, temp, i;
    
    OS_ENTER_CRITICAL();
    while(((IIR = U1IIR) & 0x01) == 0)
    {                                                   /* 有中断未处理完 */
        switch (IIR & 0x0e)
        {
            case 0x02:                                  /* THRE中断    */
                for (i = 0; i < UART1_FIFO_LENGTH; i++) /* 向发送FIFO填充数据 */
                {
                    if (QueueRead(&temp, UART1SendBuf) == QUEUE_OK)
                    {
                        U1THR = temp;
                    }
                    else
                    {
                        U1IER = U1IER & (~0x02);        /* 队列空，则禁止发送中断 */
                    }
                }
                break;
            case 0x04:                                  /* 接收数据可用 */
                OSSemPost(Uart1Sem);                    /* 通知接收任务 */
                U1IER = U1IER & (~0x01);                /* 禁止接收及字符超时中断 */
                break;
            case 0x06:                                  /* 接收线状态   */
                temp = U1LSR;
                break;
            case 0x0c:                                  /* 字符超时指示 */
                OSSemPost(Uart1Sem);                    /* 通知接收任务 */
                U1IER = U1IER & (~0x01);                /* 禁止接收及字符超时中断 */
                break;
            default :
                break;
        }
    } 
    VICVectAddr = 0;            // 通知中断控制器中断结束
    OS_EXIT_CRITICAL();
}

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
