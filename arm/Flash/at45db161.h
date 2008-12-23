#ifndef _AT45DB161_H
#define _AT45DB161_H

#define MAX_PAGE_COUNT	4096
#define MAX_PAGE_SIZE	528
union tag_flashaddr
{
	struct
	{
		uint32 ba : 10;
		uint32 pa : 12;
		uint32 reserved : 10;
	}bits;
	uint32 addr;
	uint8 value[4];
};
void at45db_ChipErase(void);
void at45db_BlockErase(uint16 pa);
void at45db_PageErase(uint16 pa);
void at45db_BufferWrite_PageProg(int id, uint16 pa,uint16 ba,uint8* buf, int nSize);
void at45db_BuffertoPageNoErase(int id, uint16 pa);
void at45db_BuffertoPage(int id, uint16 pa);
void at45db_PagetoBuffer(int id, uint16 pa);
void at45db_Page_Read(uint16 pa,uint16 ba, uint8* buf, int nSize);
void at45db_Buffer_Read(int id, uint16 ba, uint8 *buf,int nSize);
void at45db_Buffer_Write( int id,uint16 ba, uint8 *buf, int nSize);
void at45db_Comp_uint32(uint16 pa,uint16 ba, uint32 id, int nSize, uint16 *empty_p, uint16 *exist_p );
uint8 at45db_Status_reg_read(void);
uint8 FlashInit(void);
//uint8 MSPI_SendData(uint8 data);
//void SpiIO_init(void);
#endif