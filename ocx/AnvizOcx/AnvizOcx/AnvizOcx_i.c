

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Fri Jan 09 13:49:16 2009
 */
/* Compiler settings for .\AnvizOcx.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IDevice,0xDB384A48,0x1CD4,0x40ac,0xB2,0x47,0xDB,0x60,0x6B,0x35,0x0A,0xC3);


MIDL_DEFINE_GUID(IID, IID_IBus,0xF35C0B16,0xBEC1,0x4c01,0x9B,0x78,0xA6,0x62,0x90,0x38,0xDC,0x92);


MIDL_DEFINE_GUID(IID, IID_IAnvizItems,0xB3DD10E9,0x0000,0x4DC1,0x83,0xB6,0x2C,0xA5,0xBB,0xFE,0x22,0xC4);


MIDL_DEFINE_GUID(IID, IID_IAnviz,0x678E6AB5,0xE9FF,0x44BD,0x90,0xF9,0xC8,0xBD,0xDE,0xF1,0x87,0x14);


MIDL_DEFINE_GUID(IID, IID_IComBus,0xDC441879,0x14CB,0x4C26,0x83,0xED,0x87,0xE7,0x7E,0xE5,0x18,0xDD);


MIDL_DEFINE_GUID(IID, IID_ITimeList,0x3A6AD31A,0xAC74,0x4FBD,0x93,0x67,0x44,0xDB,0x39,0x69,0x75,0x5D);


MIDL_DEFINE_GUID(IID, IID_ITimeLists,0x48842D72,0x2D00,0x42FB,0x86,0x06,0x52,0x19,0x15,0x11,0x9D,0xF6);


MIDL_DEFINE_GUID(IID, IID_IDoorGroup,0x06A05261,0x2B86,0x4E72,0xBB,0x3F,0x0B,0x00,0xC9,0xEE,0x3E,0x38);


MIDL_DEFINE_GUID(IID, IID_IDoorGroups,0x40FD88E4,0x9EF2,0x4E2C,0x83,0x9E,0x2C,0x6B,0x7E,0x68,0x37,0xAF);


MIDL_DEFINE_GUID(IID, IID_IDoorState,0x095E596A,0x7292,0x4A46,0x84,0xEA,0x83,0xB3,0xB6,0x03,0x6C,0x17);


MIDL_DEFINE_GUID(IID, IID_IDoorStates,0x4506665A,0x662B,0x4067,0xAB,0xC2,0xB9,0xE2,0x7B,0x50,0xD0,0x92);


MIDL_DEFINE_GUID(IID, IID_IUser,0x64FD3185,0x9E5A,0x41D9,0xBD,0x2B,0xD4,0xF8,0xFD,0xED,0xD6,0x66);


MIDL_DEFINE_GUID(IID, IID_IUsers,0xF691BF16,0x41C6,0x433C,0xAE,0x22,0x88,0x1A,0xF0,0x33,0x47,0xF8);


MIDL_DEFINE_GUID(IID, IID_IDeviceLog,0x11D2320E,0xE03A,0x4827,0xBA,0x16,0x9B,0x69,0x55,0xC9,0x90,0xA8);


MIDL_DEFINE_GUID(IID, IID_IDeviceLogs,0x05874CFC,0x144F,0x4812,0xB7,0xAE,0x12,0x04,0x7F,0xEA,0x26,0x99);


MIDL_DEFINE_GUID(IID, IID_IAMJ03,0x77342A19,0x4433,0x489D,0x85,0x4B,0xAC,0xBA,0xC3,0x4D,0xF4,0x7A);


MIDL_DEFINE_GUID(IID, IID_IBusPortData,0x1010BD04,0xDDD8,0x44A8,0x8A,0x5D,0xFE,0x5D,0xD9,0xCF,0x26,0x34);


MIDL_DEFINE_GUID(IID, LIBID_AnvizOcxLib,0x1C19F271,0x4C93,0x4F4B,0x84,0x22,0x30,0x81,0x03,0xED,0x38,0x87);


MIDL_DEFINE_GUID(IID, DIID__IAnvizEvents,0xD762747D,0x6811,0x4C08,0xB6,0x40,0xBB,0x5F,0xBC,0xCC,0x2E,0x08);


MIDL_DEFINE_GUID(CLSID, CLSID_Anviz,0x68361EBD,0x63AA,0x48A4,0x87,0xFB,0x86,0xC5,0x58,0x51,0x81,0xF9);


MIDL_DEFINE_GUID(CLSID, CLSID_AnvizItems,0x2AEDEFE7,0xA906,0x4CF2,0xA8,0xC8,0x06,0x28,0xE0,0x9C,0xD3,0xF7);


MIDL_DEFINE_GUID(CLSID, CLSID_ComBus,0x216CF6DA,0x4F04,0x40E9,0xB4,0xD2,0xC7,0x09,0x1E,0xAB,0x4C,0x1B);


MIDL_DEFINE_GUID(CLSID, CLSID_AMJ03,0x8A899939,0xDE76,0x4D15,0x9B,0xCB,0xF8,0x9B,0x6B,0xC9,0x8A,0xA2);


MIDL_DEFINE_GUID(CLSID, CLSID_DoorGroup,0xE0E81ECE,0x8D5D,0x4D20,0xA6,0xD1,0x44,0x9E,0xE5,0xCE,0x8D,0x48);


MIDL_DEFINE_GUID(CLSID, CLSID_TimeList,0x316F4420,0xDBD2,0x40E2,0x9F,0xB8,0x9F,0xB9,0x5D,0x04,0xEC,0x3C);


MIDL_DEFINE_GUID(CLSID, CLSID_TimeLists,0xC3A3F6EF,0x1DF6,0x4715,0xA4,0x14,0x62,0x10,0x7C,0x72,0xBF,0x6D);


MIDL_DEFINE_GUID(CLSID, CLSID_DoorGroups,0xDD841611,0x6898,0x4947,0x8A,0xCF,0x21,0x5B,0x16,0x44,0x04,0x22);


MIDL_DEFINE_GUID(CLSID, CLSID_DoorStates,0x647138DF,0x9C97,0x45FF,0x93,0x94,0xA1,0x0C,0x42,0xFA,0x1F,0x37);


MIDL_DEFINE_GUID(CLSID, CLSID_DoorState,0x99DC8D84,0x86FD,0x43DC,0xA6,0x01,0x13,0xCF,0xEA,0xA0,0xDC,0x1A);


MIDL_DEFINE_GUID(CLSID, CLSID_User,0xD2FBB274,0x0F67,0x42BC,0xA6,0x0D,0x71,0x2C,0xD7,0x68,0xA5,0xA1);


MIDL_DEFINE_GUID(CLSID, CLSID_Users,0x4449BC37,0x8370,0x4103,0xBC,0x19,0xA0,0x51,0xE5,0x9F,0xDC,0x1C);


MIDL_DEFINE_GUID(CLSID, CLSID_DeviceLog,0x198594D8,0x4EDA,0x4905,0x88,0x29,0x32,0xE0,0x34,0xA2,0x4C,0x29);


MIDL_DEFINE_GUID(CLSID, CLSID_DeviceLogs,0xD4239CB7,0x86BF,0x47B8,0x8E,0x20,0x38,0xD4,0x3A,0x23,0x3F,0x23);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



