#ifndef _NMSGQUEUE_H
#define _NMSGQUEUE_H

typedef union tag_nodemsg
{
	struct{
		uint32	size : 4;
		uint32	node : 8;
		uint32  msg	 : 4;
		uint32	task : 6;
		uint32  next : 10;
		uint32  data[1];
	}bits;
	uint32 value[1];	
}NODEMSG,*PNODEMSG;

#define MSG_PARENT_NODE_BIT			3
#define MSG_PARENT_NODE_MASK		0x78
#define MSG_CHILDREN_NODE_BIT		0
#define MSG_CHILDREN_NODE_MASK		0x7


void NMsgQCreate( void );
uint8 NMsgQWrite( PNODEMSG Val );
uint8 NMsgQRead( PNODEMSG Ret,uint8 node, uint8 node_mask );
#endif