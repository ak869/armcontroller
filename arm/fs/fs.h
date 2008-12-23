#ifndef _FS_H
#define _FS_H

/*

						reader1------door1   		
user	group						
						reader2------door2

*/

/*
	0			:	other
	1			:	Attrib
	2 - 7			: 	door_state
	8 - 13			:	groupt:60
	14				: 	door_groupt
	15 - 74			: 	user_id
	75 - 194		: 	user_info
	

*/

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

 

#define ATTRIB_BA			504

#define GROUP_PAGE			3
#define GROUP_SIZE			36
#define GROUP_NUMBER		(16 * 14)
#define GROUP_TIMELIST_NUM	8


// 4000 * 4 / 528 = 30.30 ~ 31
#define USER_ID_PAGE		19
#define USER_ID_SIZE		4
#define USER_ID_NUMBER		4000

// 60.60 ~ 61
// 242.4 ~ 243
#define USER_GROUP_PAGE		50
#define USER_GROUP_SIZE		8

// 15.15 ~ 16
#define USER_INFO_PAGE		293
#define USER_INFO_SIZE		2

#define	USER_TEMP_PAGE		309
#define USER_TEMP_SIZE		1


#define LOG_PAGE			384
#define LOG_SIZE			16



struct tag_timelist{
	uint32 hour_start 		: 5;
	uint32 minute_start 	: 6;
	uint32 hour_end 		: 5;
	uint32 minute_end 		: 6;
	uint32 weeks	  	: 7;
	uint32 other		: 3;
};//4
/*
	other
	pageSize:1
	Size: 4 * 12 * 8 = 48 * 8 = 384
	List:8
*/
/*
	pageSize:4
	Size:2048
	List:16 * 16
*/
struct tag_doorstatus{
	struct tag_timelist t;
	uint16 param;
	uint8 type;//safe, open, close, none
	uint8 crc;
};//8

/*

	pageSize:	6
	Size: 60 * 50 = 3000
	List: 60
*/
struct tag_doorgroup
{
	struct tag_timelist t[8]; //32
	uint16 param;
	uint8 power;
	uint8 crc;
};//36
/*
	page 0 - 59
	pageSize:60
	Size:31680
	List:7920
*/
struct tag_userlist{
	uint32 userid;
};//4
/*
	page 60 - 179
	pageSize:120
	Size:63360
	List:7920
*/
struct tag_userinfo
{
	uint8 group[6];		//8*6
	uint8 param; //fan qian
	uint8 crc;
};//8
typedef	union tag_time{
		struct 
		{
			uint32 hour:5;
			uint32 minute:6;
			uint32 second:6;					
			uint32 day:5;
			uint32 month:4;
			uint32 year:6;
			uint8  weeks;	
		}timelong;
		struct 
		{
			uint32 hour:5;
			uint32 minute:6;
			uint32 second:6;					
			uint32 day:5;
			uint32 month:4;
			uint32 year:6;
		}time;		
		uint32 value;
	}DATETIME ;
struct tag_log{	
	uint32 id;
	uint32 userid;	
	uint32 ntime;
	uint8 node;//门磁,拆机,门,卡,主机
	uint8 type;//开门:0x10，门磁报警:0x20，Sensor报警:0x30 有效id:0x40，无效id(M):0x50, 1/2(L) 断电
	uint8 reserved;
	uint8 crc;
};//14

struct tag_attrib{
	uint8	megnet			:1;		//0
	uint8   button			:1;		//1
	uint8	feedback		:1;
	uint8  	alarm			:1;
	uint8	other			:1;
	uint8  	door_submarine	:1;
	uint8	reserved;	
	uint8	link;
	uint8	door_delay;
	uint8	megnet_delay;
	uint8	card_delay;
	uint8	card;

};//5
void LogInit(void);
void LogWrite(uint8 node, uint8 type, uint32 userid, uint32 ntime);
void FsInit(void);
#endif