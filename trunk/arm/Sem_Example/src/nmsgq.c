#include "config.h"


typedef struct {
    uint8     *Out;                   /* 指向数据输出位置         */
    uint8     *In;                    /* 指向数据输入位置         */
    uint8     *End;                   /* 指向Buf的结束位置        */
    uint16    NData;                  /* 队列中数据个数           */
    uint16    MaxData;                /* 队列中允许存储的数据个数 */
    
    OS_EVENT	* ReadNoEmpty;        /* 读空处理函数             */
//    OS_EVENT	* WriteNoFull;        /* 写满处理函数             */
    uint8     Buf[1];                 /* 存储数据的空间           */
} NMsgDataQueue;

uint8 NMsgQCreate(void *Buf, 
					uint32 SizeOfBuf
					)
{
	NMsgDataQueue *Queue;
	
	if( Buf != NULL && SizeOfBuf >= (sizeof(DataQueue)) )
	{
		Queue = ( NMsgDataQueue *)Buf;
		
		OS_ENTER_CRITICAL();		
		
		Queue->MaxData = ( SizeOfBuf - (uint32)(((DataQueue *)0)->Buf));
		
		Queue->End = Queue->Buf + Queue->MaxData;
		Queue->Out = Queue->Buf;
		Queue->In = Queue->Buf;
		Queue->NData = 0;

		Queue->ReadNoEmpty = OSSemCreate(0);
		
		OS_EXIT_CRITICAL();
		
		return QUEUE_OK;	
	}
	else
	{
		return NOT_OK;
	}
}

uint8 NMsgQRead( struct tag_nodemsg *Ret, void *Buf)
{
	uint8 err;
	NMsgDataQueue *Queue;
	uint8 nodeSize,*bRet;
	struct tag_nodemsg *t;
	int i;
	
	err = NOT_OK;
	
	if (Buf != NULL )
	{
		Queue = (NMsgDataQueue *) Buf;
		OSSemPend (Queue->ReadNoEmpty, 0, &err);
		OS_ENTER_CRITICAL();
		if( Queue->NData > 0 )
		{
			t = (struct tag_nodemsg *)Queue->Out;
			nodeSize = t->size;
			if( Ret->size < nodeSize )
			{
//				err = 
				goto ExitQueueRead;
			}
			bRet = (uint8 *)Ret;
			for( i = 0; i < nodeSize; i++ )
			{
				bRet[i] = Queue->Out[0];
				Queue->Out++;
	            if (Queue->Out >= Queue->End)
	            {
	                Queue->Out = Queue->Buf;
	            }
	            Queue->NData--;				
				
			}
//			OSSemPost(WriteNoFull);			
			err = QUEUE_OK;
			
		}else
		{
            err = QUEUE_EMPTY;		
		}
ExitQueueRead:	
		OS_EXIT_CRITICAL();
	}
}

uint8 NMsgQWrite(void *Buf, struct tag_nodemsg *Data)
{
	uint8 err;
	NMsgDataQueue *Queue;
	uint8 *tmp,nodeSize;
	int i;
	
	err = NOT_OK;
	if( Buf != NULL )
	{
		Queue = ( NMsgDataQueue * )Buf;
		nodeSize = Data->size;
		
		OS_ENTER_CRITICAL();
		if( Queue->NData + nodeSize < Queue->MaxData )
		{
			tmp = (uint8*)Data;

			for( i = 0; i < nodeSize; i++ )
			{
				Queue->In[0] = tmp[i];
				Queue->In++;
				Queue->NData++;				
			}
			OSSemPost(Queue->ReadNoEmpty);
			err = QUEUE_OK;
		}
		else
		{
			err = QUEUE_FULL;
		}
		OS_EXIT_CRITICAL();
	}
	return err;
} 
