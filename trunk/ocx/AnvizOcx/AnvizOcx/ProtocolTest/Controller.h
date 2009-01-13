// Protocol.h: interface for the CProtocol class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROTOCOL_H__DD188480_CAAA_471C_ABD2_196F4AA5319F__INCLUDED_)
#define AFX_PROTOCOL_H__DD188480_CAAA_471C_ABD2_196F4AA5319F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PortThread.h"

#define OTHER_PAGE			0
#define OTHER_SIZE			48
#define OTHER_NUMBER		7

/*
	0 - 63		PAGE(1)
	64 - 127	PAGE(2)

*/

#define DOOR_STATE_PAGE		1
#define DOOR_STATE_SIZE		8
#define DOOR_STATE_NUMBER	128

/*
	0 - 13			PAGE(3)		ba:504 attrib
	14 - 27 		PAGE(4)		ba:504 attrib
	28 - 41			PAGE(5)		ba:504 attrib
	42 - 55			PAGE(6)		ba:504 attrib
	56 - 69			PAGE(7)		ba:504 attrib
	70 - 83			PAGE(8)		ba:504 attrib
	84 - 97			PAGE(9)		ba:504 attrib
	98 - 111		PAGE(10)	ba:504 attrib
	112 - 125		PAGE(11)	ba:504 attrib
	126 - 139		PAGE(12)	ba:504 attrib
	140 - 153		PAGE(13)	ba:504 attrib
	154 - 167		PAGE(14)	ba:504 attrib
	168 - 181		PAGE(15)	ba:504 attrib
	182 - 195		PAGE(16)	ba:504 attrib
	196 - 209		PAGE(17)	ba:504 attrib
	210 - 223		PAGE(18)	ba:504 attrib
*/

#define GROUP_PAGE			3
#define GROUP_SIZE			36
#define GROUP_NUMBER		(16 * 14)
#define GROUP_TIMELIST_NUM	8


// 4000 * 4 / 528 = 30.30 ~ 31
#define USER_ID_PAGE		19
#define USER_ID_SIZE		4
#define USER_ID_NUMBER		4000

// 60.60 ~ 61
#define USER_GROUP_PAGE		50
#define USER_GROUP_SIZE		8

// 15.15 ~ 16
#define USER_INFO_PAGE		121
#define USER_INFO_SIZE		2

#define LOG_PAGE			137
#define LOG_SIZE			16


#define uint32	unsigned int
#define uint16	unsigned short
#define uint8	unsigned char
#pragma pack(push,1)
struct tag_timelist{
	uint32 hour_start 		: 5;
	uint32 minute_start 	: 6;
	uint32 hour_end 	: 5;
	uint32 minute_end 	: 6;
	uint32 weeks	  	: 7;
	uint32 other		: 3;
};//4

struct tag_userlist{
	uint32 userid;
};//4

struct tag_userinfo
{
	uint8 doorgroup1;
	uint8 doorgroup2;
	uint8 doorgroup3;
	uint8 doorgroup4;
	uint8 doorgroup5;
	uint8 doorgroup6;		//8*6
	uint8 param; //fan qian
	uint8 crc;
};//8



struct log_tag{	
	uint32 id;
	uint32 userid;	
	struct
	{
		uint32 year:6;
		uint32 month:4;
		uint32 day:5;
		uint32 hour:5;
		uint32 minute:6;
		uint32 second:6;
	}time;
	uint8 node;//门磁,拆机,门,卡,主机
	uint8 type;//开门:0x10，门磁报警:0x20，Sensor报警:0x30 有效id:0x40，无效id(M):0x50, 1/2(L) 断电
};//14



struct tag_attrib{
	uint16	megnet		:1;		//0
	uint16   button		:1;		//1
	uint16	feedback	:1;
	uint16  alarm		:1;
	uint16	other		:1;
	uint16	link		:1;
	uint16  door_submarine	:1;	
	uint8	door_delay;
	uint8	megnet_alarm;
	uint8	card;
};//5

struct tag_doorstatus{
	struct tag_timelist t;
	uint16 param;
	uint8 type;//safe, open, close, none
	uint8 crc;
};//8


struct tag_group
{
	struct tag_timelist t[8]; //32
	uint16 param;
	uint8 power;
	uint8 crc;
};//36

#define GROUP_SIZE		36
#define GROUP_NUBMER	48

#define MEGNET_BIT		0
#define BUTTON_BIT		1
#define FEEDBACK_BIT	2	//反馈
#define ALARM_BIT		3
#define OTHER_BIT		4
#define LINK_BIT		5
#define DOORSM_BIT		6	//反潜

#define DOOR_DELAY		2
#define MEGNET_ALARM	3
#define CARD_SIZE		4
#define WIEGAND_SELECT	5

#define DOOR1_ATTRIB_SIZE	8

#pragma pack(pop)


/*
class CMachinePool
{
private:
	LONG	m_nextID;
	LONG	m_nSize
	CMachine *m_machine;
public:
	CMachinePool(void);
	{
		m_nSize = 0;
		m_machine = NULL;
	}
	~CMachinePool(void)
	{	
	}
	int LoopNext(void);
	int AddMachine(CMachine * value);
	int RemoveMachine(CMachine * value);
	int LoopMachine(void)
	{
		m_machine[m_nextID].LoopFunc();
		m_nextID ++;
		m_nextID %= m_nSize;
	}
};
*/

#define	ERR_BUFFER_SMALL	(ERR_DEVICE + 0x1)

class CController:public CDevice
{
private:
	BYTE m_addr;
	DWORD m_ErrCode;
	CBusProtocol * m_port;
public:
	BOOL DownloadLog(DWORD id, struct log_tag * t, DWORD *nSize);
	DWORD GetErrCode(VOID);
	BOOL User_Del(DWORD nID);
	BOOL User_Add(DWORD nID, BYTE *nGroup, int nSize, BYTE attrib);
	virtual void LinkBusPort(CBusProtocol *port);
	virtual void UlinkBusPort(void);
	BYTE GetMachineAddr(VOID);
	VOID SetMachineAddr(BYTE dn);
	BOOL GetStatus(BYTE node, BYTE *state);
	BOOL SetStatus(BYTE node, BYTE opertion);
	BOOL EsareFlash(WORD pa);
	BOOL SetLongData(WORD pa, WORD ba, BYTE *Buf, DWORD nSize);
	BOOL SetBitData(WORD pa, WORD ba, BYTE Bit, BYTE nBits );
	BOOL SetByteData( WORD pa, WORD ba, BYTE Buf);
	BOOL GetLongData( WORD pa, WORD ba, BYTE *Buf, DWORD nSize);
	BOOL Test(void);
	CController(CBusProtocol *p,BYTE dn);
	CController();
	virtual ~CController();
	DWORD GetMaxGroupNum(void);
	DWORD GetGroupMaxTimeListNum(void);
	virtual ULONG InRelease(void);
	virtual ULONG InAddRef(void);
	};

#endif // !defined(AFX_PROTOCOL_H__DD188480_CAAA_471C_ABD2_196F4AA5319F__INCLUDED_)
