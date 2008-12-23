#ifndef _NMSGQ_H
#define _NMSGQ_H



struct tag_nodemsg
{
	short	size	: 3; 
	short node	: 8;
	short  msg		: 5;	
	uint8	data[1];
};

uint8 NMsgQCreate(void *Buf, 
					uint32 SizeOfBuf
					);
uint8 NMsgQRead( struct tag_nodemsg *Ret, void *Buf);
uint8 NMsgQWrite(void *Buf, struct tag_nodemsg *Ret);

#endif