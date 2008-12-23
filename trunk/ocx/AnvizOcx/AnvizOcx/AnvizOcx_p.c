

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Dec 23 16:10:05 2008
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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "AnvizOcx_i.h"

#define TYPE_FORMAT_STRING_SIZE   1377                              
#define PROC_FORMAT_STRING_SIZE   2419                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _AnvizOcx_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } AnvizOcx_MIDL_TYPE_FORMAT_STRING;

typedef struct _AnvizOcx_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } AnvizOcx_MIDL_PROC_FORMAT_STRING;

typedef struct _AnvizOcx_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } AnvizOcx_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const AnvizOcx_MIDL_TYPE_FORMAT_STRING AnvizOcx__MIDL_TypeFormatString;
extern const AnvizOcx_MIDL_PROC_FORMAT_STRING AnvizOcx__MIDL_ProcFormatString;
extern const AnvizOcx_MIDL_EXPR_FORMAT_STRING AnvizOcx__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDevice_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDevice_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBus_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBus_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAnvizItems_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAnvizItems_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAnviz_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAnviz_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IComBus_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IComBus_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITimeList_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITimeList_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITimeLists_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITimeLists_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDoorGroup_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDoorGroup_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDoorGroups_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDoorGroups_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDoorState_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDoorState_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDoorStates_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDoorStates_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IUser_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IUser_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IUsers_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IUsers_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDeviceLog_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDeviceLog_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDeviceLogs_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDeviceLogs_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IAMJ03_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IAMJ03_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IBusPortData_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IBusPortData_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const AnvizOcx_MIDL_PROC_FORMAT_STRING AnvizOcx__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure LinkBus */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newValue */

/* 24 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UnlinkBus */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SendData */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x7 ),	/* 7 */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 82 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 84 */	NdrFcShort( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 90 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	NdrFcShort( 0x14 ),	/* Type Offset=20 */

	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x7 ),	/* 7 */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 118 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppUnk */

/* 126 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 146 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 152 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 154 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 156 */	NdrFcShort( 0xb4 ),	/* 180 */
/* 158 */	NdrFcShort( 0x9f ),	/* 159 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 162 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 166 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter pVal */

/* 168 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 170 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 172 */	NdrFcShort( 0x43a ),	/* Type Offset=1082 */

	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 176 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CardID */


	/* Procedure get_Count */


	/* Procedure get_Count */


	/* Procedure get_Count */


	/* Procedure get_Count */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x9 ),	/* 9 */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x24 ),	/* 36 */
/* 194 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 196 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 204 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 206 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 210 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 216 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 218 */	NdrFcLong( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0xa ),	/* 10 */
/* 224 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x8 ),	/* 8 */
/* 230 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 232 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x3af ),	/* 943 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Key */

/* 240 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 242 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 244 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Value */

/* 246 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 248 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 250 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 254 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */

/* 258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0xb ),	/* 11 */
/* 266 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 274 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x2e5 ),	/* 741 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 282 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 286 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 290 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Download */


	/* Procedure Clear */

/* 294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0xc ),	/* 12 */
/* 302 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 308 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 318 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MachineItem */


	/* Procedure get_BusItems */

/* 324 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 326 */	NdrFcLong( 0x0 ),	/* 0 */
/* 330 */	NdrFcShort( 0x7 ),	/* 7 */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x8 ),	/* 8 */
/* 338 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 340 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 348 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 350 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 352 */	NdrFcShort( 0x448 ),	/* Type Offset=1096 */

	/* Return value */


	/* Return value */

/* 354 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 356 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Hour */

/* 360 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 362 */	NdrFcLong( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x7 ),	/* 7 */
/* 368 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 370 */	NdrFcShort( 0x6 ),	/* 6 */
/* 372 */	NdrFcShort( 0x24 ),	/* 36 */
/* 374 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 376 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Attrib */

/* 384 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 388 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 390 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 392 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 398 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Hour */

/* 402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 410 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 412 */	NdrFcShort( 0xe ),	/* 14 */
/* 414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 416 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 418 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Attrib */

/* 426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 428 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 430 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 432 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Minute */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0x9 ),	/* 9 */
/* 452 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 454 */	NdrFcShort( 0x6 ),	/* 6 */
/* 456 */	NdrFcShort( 0x24 ),	/* 36 */
/* 458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Attrib */

/* 468 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 474 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 476 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Minute */

/* 486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0xa ),	/* 10 */
/* 494 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 496 */	NdrFcShort( 0xe ),	/* 14 */
/* 498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 500 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 502 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Attrib */

/* 510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 514 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 516 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 524 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Other */

/* 528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0xb ),	/* 11 */
/* 536 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x24 ),	/* 36 */
/* 542 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 544 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 552 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Other */

/* 564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0xc ),	/* 12 */
/* 572 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 578 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 580 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 588 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 590 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 596 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsDay */

/* 600 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0xd ),	/* 13 */
/* 608 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 610 */	NdrFcShort( 0x6 ),	/* 6 */
/* 612 */	NdrFcShort( 0x22 ),	/* 34 */
/* 614 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 616 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter WeekofDay */

/* 624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 626 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 628 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter pRetVal */

/* 630 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 632 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 634 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 638 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDay */

/* 642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0xe ),	/* 14 */
/* 650 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 652 */	NdrFcShort( 0x6 ),	/* 6 */
/* 654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 656 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 658 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter WeekofDay */

/* 666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 670 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Return value */

/* 672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 674 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UserID */


	/* Procedure get_ID */

/* 678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0xf ),	/* 15 */
/* 686 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x24 ),	/* 36 */
/* 692 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 702 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 704 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 710 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x7 ),	/* 7 */
/* 722 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 724 */	NdrFcShort( 0x8 ),	/* 8 */
/* 726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 728 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 730 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 744 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 746 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 748 */	NdrFcShort( 0x462 ),	/* Type Offset=1122 */

	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */


	/* Procedure get__NewEnum */


	/* Procedure get__NewEnum */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 764 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 772 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 780 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	NdrFcShort( 0x478 ),	/* Type Offset=1144 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Buffer */


	/* Procedure get_LogID */


	/* Procedure get_Power */

/* 792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x7 ),	/* 7 */
/* 800 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x24 ),	/* 36 */
/* 806 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 808 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 816 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 822 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 826 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Power */

/* 828 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 830 */	NdrFcLong( 0x0 ),	/* 0 */
/* 834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 840 */	NdrFcShort( 0x8 ),	/* 8 */
/* 842 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 844 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 852 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 854 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Updata */

/* 864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x9 ),	/* 9 */
/* 872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 880 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 888 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 890 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Updata */


	/* Procedure Download */

/* 894 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 896 */	NdrFcLong( 0x0 ),	/* 0 */
/* 900 */	NdrFcShort( 0xa ),	/* 10 */
/* 902 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 908 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 910 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 920 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TimeLists */

/* 924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0xb ),	/* 11 */
/* 932 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 938 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 940 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 948 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 950 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 952 */	NdrFcShort( 0x48e ),	/* Type Offset=1166 */

	/* Return value */

/* 954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 956 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Node */


	/* Procedure get_ID */


	/* Procedure get_ID */

/* 960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0xc ),	/* 12 */
/* 968 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x24 ),	/* 36 */
/* 974 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 976 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 984 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get__NewEnum */


	/* Procedure get__NewEnum */

/* 996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1004 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1012 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1020 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1024 */	NdrFcShort( 0x478 ),	/* Type Offset=1144 */

	/* Return value */


	/* Return value */

/* 1026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1040 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1046 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1048 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 1056 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1058 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1062 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1064 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1066 */	NdrFcShort( 0x4a4 ),	/* Type Offset=1188 */

	/* Return value */

/* 1068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1070 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TimeList */

/* 1074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1082 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1088 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1090 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1098 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1100 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1102 */	NdrFcShort( 0x462 ),	/* Type Offset=1122 */

	/* Return value */

/* 1104 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1106 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Size */


	/* Procedure get_AreaID */


	/* Procedure get_State */

/* 1110 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1112 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1118 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1122 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1124 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1126 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 1134 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveGroup */


	/* Procedure put_State */

/* 1146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1160 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1162 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter GroupIndex */


	/* Parameter newVal */

/* 1170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Updata */


	/* Procedure Download */

/* 1182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0xb ),	/* 11 */
/* 1190 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1194 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1196 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1198 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1206 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1208 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1212 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1214 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1220 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1226 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1228 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1236 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1238 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1240 */	NdrFcShort( 0x4ba ),	/* Type Offset=1210 */

	/* Return value */

/* 1242 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1244 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddGroup */

/* 1248 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1250 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1256 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1262 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1264 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter GroupIndex */

/* 1272 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Groups */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1292 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1300 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1308 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1312 */	NdrFcShort( 0x4d0 ),	/* Type Offset=1232 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAttrib */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0xa ),	/* 10 */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1334 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1336 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 1344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClearAttrib */

/* 1356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0xb ),	/* 11 */
/* 1364 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1370 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1372 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 1380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1382 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAttrib */

/* 1392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0xc ),	/* 12 */
/* 1400 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1404 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1406 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1408 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 1416 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1422 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1424 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1430 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_EventID */


	/* Procedure get_Count */


	/* Procedure get_CardID */

/* 1434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0xd ),	/* 13 */
/* 1442 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1448 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1450 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1456 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 1458 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1460 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1466 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_AreaID */

/* 1470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1476 */	NdrFcShort( 0xe ),	/* 14 */
/* 1478 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1484 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1486 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1494 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1496 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1502 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Updata */

/* 1506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1514 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1520 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1522 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1528 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1532 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Download */

/* 1536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1542 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1544 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1550 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1552 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1562 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1572 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1574 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1580 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1582 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1586 */	NdrFcShort( 0x2e5 ),	/* 741 */
/* 1588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 1590 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1594 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter pVal */

/* 1596 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1598 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1600 */	NdrFcShort( 0x4e6 ),	/* Type Offset=1254 */

	/* Return value */

/* 1602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1604 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 1608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1616 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1618 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1622 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1624 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Area */

/* 1632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1634 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ID */

/* 1638 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1640 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter LongID */

/* 1644 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1646 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1650 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1652 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1654 */	NdrFcShort( 0x4e6 ),	/* Type Offset=1254 */

	/* Return value */

/* 1656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1658 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */

/* 1662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0xa ),	/* 10 */
/* 1670 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1672 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1676 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 1678 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Area */

/* 1686 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1688 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ID */

/* 1692 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1694 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter LongID */

/* 1698 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1700 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1704 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1706 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Count */


	/* Procedure get_UserID */

/* 1710 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1712 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0xa ),	/* 10 */
/* 1718 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1724 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1726 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1734 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1736 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1742 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DateTime */

/* 1746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0xb ),	/* 11 */
/* 1754 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1760 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1762 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1770 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1772 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1774 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 1776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1778 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Item */

/* 1782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1790 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1796 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1798 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Index */

/* 1806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1808 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1812 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1816 */	NdrFcShort( 0x500 ),	/* Type Offset=1280 */

	/* Return value */

/* 1818 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1820 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Download */

/* 1824 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1832 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1836 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1838 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1840 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ID */

/* 1848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1850 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRetVal */

/* 1854 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1856 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1858 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1860 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DoorGroups */

/* 1866 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1868 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1874 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1880 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1882 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1890 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1892 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1894 */	NdrFcShort( 0x4d0 ),	/* Type Offset=1232 */

	/* Return value */

/* 1896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1898 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Attrib */

/* 1902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1910 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1914 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1916 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1918 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Node */

/* 1926 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1928 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1932 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1934 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1940 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Attrib */

/* 1944 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1952 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1954 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1958 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1960 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Node */

/* 1968 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1970 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1972 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1974 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1976 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1982 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Param */


	/* Procedure get_Status */

/* 1986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0xa ),	/* 10 */
/* 1994 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1998 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2000 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2002 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */


	/* Parameter Node */

/* 2010 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2012 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 2016 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2022 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2024 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Param */


	/* Procedure put_Status */

/* 2028 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0xb ),	/* 11 */
/* 2036 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2038 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2040 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2042 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2044 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */


	/* Parameter Node */

/* 2052 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2054 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 2058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2060 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2064 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2066 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DoorStates */

/* 2070 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0xc ),	/* 12 */
/* 2078 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2084 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2086 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2094 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2096 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2098 */	NdrFcShort( 0x516 ),	/* Type Offset=1302 */

	/* Return value */

/* 2100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2102 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Users */

/* 2106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0xd ),	/* 13 */
/* 2114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2120 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2122 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2130 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2132 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2134 */	NdrFcShort( 0x52c ),	/* Type Offset=1324 */

	/* Return value */

/* 2136 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2138 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRTCTime */

/* 2142 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0xe ),	/* 14 */
/* 2150 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2152 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2154 */	NdrFcShort( 0x46 ),	/* 70 */
/* 2156 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2158 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2164 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pValue */

/* 2166 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2168 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2170 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pRetVal */

/* 2172 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2174 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2176 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2178 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2180 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRTCTime */

/* 2184 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2186 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2190 */	NdrFcShort( 0xf ),	/* 15 */
/* 2192 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2194 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2196 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2198 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2200 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Value */

/* 2208 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2210 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2212 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter pRetVal */

/* 2214 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2216 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2218 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2222 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MachineAddr */

/* 2226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2240 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2242 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2248 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2250 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2252 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2256 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2258 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MachineAddr */

/* 2262 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2264 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2270 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2274 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2276 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2278 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2284 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2286 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2288 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2292 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2294 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDevVersion */

/* 2298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2306 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2308 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2310 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2312 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2314 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 2322 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 2324 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pRetVal */

/* 2328 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2330 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2332 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Logs */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2348 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2354 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2356 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2364 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2366 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2368 */	NdrFcShort( 0x54a ),	/* Type Offset=1354 */

	/* Return value */

/* 2370 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2372 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetBuffer */

/* 2376 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2378 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2384 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2386 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2390 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2392 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Buf */

/* 2400 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2402 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nSize */

/* 2406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2408 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2414 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const AnvizOcx_MIDL_TYPE_FORMAT_STRING AnvizOcx__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  4 */	NdrFcLong( 0xf35c0b16 ),	/* -212071658 */
/*  8 */	NdrFcShort( 0xbec1 ),	/* -16703 */
/* 10 */	NdrFcShort( 0x4c01 ),	/* 19457 */
/* 12 */	0x9b,		/* 155 */
			0x78,		/* 120 */
/* 14 */	0xa6,		/* 166 */
			0x62,		/* 98 */
/* 16 */	0x90,		/* 144 */
			0x38,		/* 56 */
/* 18 */	0xdc,		/* 220 */
			0x92,		/* 146 */
/* 20 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 22 */	NdrFcLong( 0x14ba2c5 ),	/* 21734085 */
/* 26 */	NdrFcShort( 0x63d4 ),	/* 25556 */
/* 28 */	NdrFcShort( 0x469f ),	/* 18079 */
/* 30 */	0x8a,		/* 138 */
			0xfd,		/* 253 */
/* 32 */	0xec,		/* 236 */
			0xde,		/* 222 */
/* 34 */	0xf4,		/* 244 */
			0x2b,		/* 43 */
/* 36 */	0x8b,		/* 139 */
			0x63,		/* 99 */
/* 38 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 40 */	NdrFcShort( 0x2 ),	/* Offset= 2 (42) */
/* 42 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 54 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 56 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 58 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 60 */	
			0x12, 0x0,	/* FC_UP */
/* 62 */	NdrFcShort( 0x3d6 ),	/* Offset= 982 (1044) */
/* 64 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 66 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 68 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 70 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 72 */	NdrFcShort( 0x2 ),	/* Offset= 2 (74) */
/* 74 */	NdrFcShort( 0x10 ),	/* 16 */
/* 76 */	NdrFcShort( 0x2f ),	/* 47 */
/* 78 */	NdrFcLong( 0x14 ),	/* 20 */
/* 82 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 84 */	NdrFcLong( 0x3 ),	/* 3 */
/* 88 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 90 */	NdrFcLong( 0x11 ),	/* 17 */
/* 94 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 96 */	NdrFcLong( 0x2 ),	/* 2 */
/* 100 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 102 */	NdrFcLong( 0x4 ),	/* 4 */
/* 106 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 108 */	NdrFcLong( 0x5 ),	/* 5 */
/* 112 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 114 */	NdrFcLong( 0xb ),	/* 11 */
/* 118 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 120 */	NdrFcLong( 0xa ),	/* 10 */
/* 124 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 126 */	NdrFcLong( 0x6 ),	/* 6 */
/* 130 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (362) */
/* 132 */	NdrFcLong( 0x7 ),	/* 7 */
/* 136 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 138 */	NdrFcLong( 0x8 ),	/* 8 */
/* 142 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (368) */
/* 144 */	NdrFcLong( 0xd ),	/* 13 */
/* 148 */	NdrFcShort( 0xff96 ),	/* Offset= -106 (42) */
/* 150 */	NdrFcLong( 0x9 ),	/* 9 */
/* 154 */	NdrFcShort( 0xf0 ),	/* Offset= 240 (394) */
/* 156 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 160 */	NdrFcShort( 0xfc ),	/* Offset= 252 (412) */
/* 162 */	NdrFcLong( 0x24 ),	/* 36 */
/* 166 */	NdrFcShort( 0x324 ),	/* Offset= 804 (970) */
/* 168 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 172 */	NdrFcShort( 0x31e ),	/* Offset= 798 (970) */
/* 174 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 178 */	NdrFcShort( 0x31c ),	/* Offset= 796 (974) */
/* 180 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 184 */	NdrFcShort( 0x31a ),	/* Offset= 794 (978) */
/* 186 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 190 */	NdrFcShort( 0x318 ),	/* Offset= 792 (982) */
/* 192 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 196 */	NdrFcShort( 0x316 ),	/* Offset= 790 (986) */
/* 198 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 202 */	NdrFcShort( 0x314 ),	/* Offset= 788 (990) */
/* 204 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 208 */	NdrFcShort( 0x312 ),	/* Offset= 786 (994) */
/* 210 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 214 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (978) */
/* 216 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 220 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (982) */
/* 222 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 226 */	NdrFcShort( 0x304 ),	/* Offset= 772 (998) */
/* 228 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 232 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (994) */
/* 234 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 238 */	NdrFcShort( 0x2fc ),	/* Offset= 764 (1002) */
/* 240 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 244 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (1006) */
/* 246 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 250 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (1010) */
/* 252 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 256 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (1014) */
/* 258 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 262 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (1018) */
/* 264 */	NdrFcLong( 0x10 ),	/* 16 */
/* 268 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 270 */	NdrFcLong( 0x12 ),	/* 18 */
/* 274 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 276 */	NdrFcLong( 0x13 ),	/* 19 */
/* 280 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 282 */	NdrFcLong( 0x15 ),	/* 21 */
/* 286 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 288 */	NdrFcLong( 0x16 ),	/* 22 */
/* 292 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 294 */	NdrFcLong( 0x17 ),	/* 23 */
/* 298 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 300 */	NdrFcLong( 0xe ),	/* 14 */
/* 304 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (1026) */
/* 306 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 310 */	NdrFcShort( 0x2d6 ),	/* Offset= 726 (1036) */
/* 312 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 316 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (1040) */
/* 318 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 322 */	NdrFcShort( 0x290 ),	/* Offset= 656 (978) */
/* 324 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 328 */	NdrFcShort( 0x28e ),	/* Offset= 654 (982) */
/* 330 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 334 */	NdrFcShort( 0x28c ),	/* Offset= 652 (986) */
/* 336 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 340 */	NdrFcShort( 0x282 ),	/* Offset= 642 (982) */
/* 342 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 346 */	NdrFcShort( 0x27c ),	/* Offset= 636 (982) */
/* 348 */	NdrFcLong( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* Offset= 0 (352) */
/* 354 */	NdrFcLong( 0x1 ),	/* 1 */
/* 358 */	NdrFcShort( 0x0 ),	/* Offset= 0 (358) */
/* 360 */	NdrFcShort( 0xffff ),	/* Offset= -1 (359) */
/* 362 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 366 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 368 */	
			0x12, 0x0,	/* FC_UP */
/* 370 */	NdrFcShort( 0xe ),	/* Offset= 14 (384) */
/* 372 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 374 */	NdrFcShort( 0x2 ),	/* 2 */
/* 376 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 378 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 380 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 382 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 384 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 388 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (372) */
/* 390 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 392 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 394 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 396 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 406 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 408 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 410 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 412 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 414 */	NdrFcShort( 0x2 ),	/* Offset= 2 (416) */
/* 416 */	
			0x12, 0x0,	/* FC_UP */
/* 418 */	NdrFcShort( 0x216 ),	/* Offset= 534 (952) */
/* 420 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 422 */	NdrFcShort( 0x18 ),	/* 24 */
/* 424 */	NdrFcShort( 0xa ),	/* 10 */
/* 426 */	NdrFcLong( 0x8 ),	/* 8 */
/* 430 */	NdrFcShort( 0x5a ),	/* Offset= 90 (520) */
/* 432 */	NdrFcLong( 0xd ),	/* 13 */
/* 436 */	NdrFcShort( 0x7e ),	/* Offset= 126 (562) */
/* 438 */	NdrFcLong( 0x9 ),	/* 9 */
/* 442 */	NdrFcShort( 0x9e ),	/* Offset= 158 (600) */
/* 444 */	NdrFcLong( 0xc ),	/* 12 */
/* 448 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (648) */
/* 450 */	NdrFcLong( 0x24 ),	/* 36 */
/* 454 */	NdrFcShort( 0x124 ),	/* Offset= 292 (746) */
/* 456 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 460 */	NdrFcShort( 0x140 ),	/* Offset= 320 (780) */
/* 462 */	NdrFcLong( 0x10 ),	/* 16 */
/* 466 */	NdrFcShort( 0x15a ),	/* Offset= 346 (812) */
/* 468 */	NdrFcLong( 0x2 ),	/* 2 */
/* 472 */	NdrFcShort( 0x174 ),	/* Offset= 372 (844) */
/* 474 */	NdrFcLong( 0x3 ),	/* 3 */
/* 478 */	NdrFcShort( 0x18e ),	/* Offset= 398 (876) */
/* 480 */	NdrFcLong( 0x14 ),	/* 20 */
/* 484 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (908) */
/* 486 */	NdrFcShort( 0xffff ),	/* Offset= -1 (485) */
/* 488 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 490 */	NdrFcShort( 0x4 ),	/* 4 */
/* 492 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 498 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 500 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 502 */	NdrFcShort( 0x4 ),	/* 4 */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x1 ),	/* 1 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	0x12, 0x0,	/* FC_UP */
/* 514 */	NdrFcShort( 0xff7e ),	/* Offset= -130 (384) */
/* 516 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 518 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 520 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 524 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 526 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 528 */	NdrFcShort( 0x4 ),	/* 4 */
/* 530 */	NdrFcShort( 0x4 ),	/* 4 */
/* 532 */	0x11, 0x0,	/* FC_RP */
/* 534 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (488) */
/* 536 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 538 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 540 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 550 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 554 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 556 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 558 */	NdrFcShort( 0xfdfc ),	/* Offset= -516 (42) */
/* 560 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 562 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x6 ),	/* Offset= 6 (574) */
/* 570 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 572 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 574 */	
			0x11, 0x0,	/* FC_RP */
/* 576 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (540) */
/* 578 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 588 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 592 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 594 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 596 */	NdrFcShort( 0xff36 ),	/* Offset= -202 (394) */
/* 598 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 600 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x6 ),	/* Offset= 6 (612) */
/* 608 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 610 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 612 */	
			0x11, 0x0,	/* FC_RP */
/* 614 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (578) */
/* 616 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 618 */	NdrFcShort( 0x4 ),	/* 4 */
/* 620 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 626 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 628 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 630 */	NdrFcShort( 0x4 ),	/* 4 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x1 ),	/* 1 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	0x12, 0x0,	/* FC_UP */
/* 642 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1044) */
/* 644 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 646 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 648 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x6 ),	/* Offset= 6 (660) */
/* 656 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 658 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 660 */	
			0x11, 0x0,	/* FC_RP */
/* 662 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (616) */
/* 664 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 666 */	NdrFcLong( 0x2f ),	/* 47 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 676 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 678 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 680 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 682 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 684 */	NdrFcShort( 0x1 ),	/* 1 */
/* 686 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 688 */	NdrFcShort( 0x4 ),	/* 4 */
/* 690 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 692 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 694 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 696 */	NdrFcShort( 0x10 ),	/* 16 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0xa ),	/* Offset= 10 (710) */
/* 702 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 704 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 706 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (664) */
/* 708 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 710 */	
			0x12, 0x0,	/* FC_UP */
/* 712 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (682) */
/* 714 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 716 */	NdrFcShort( 0x4 ),	/* 4 */
/* 718 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 724 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 726 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 728 */	NdrFcShort( 0x4 ),	/* 4 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x1 ),	/* 1 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	0x12, 0x0,	/* FC_UP */
/* 740 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (694) */
/* 742 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 744 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 746 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x6 ),	/* Offset= 6 (758) */
/* 754 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 756 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 758 */	
			0x11, 0x0,	/* FC_RP */
/* 760 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (714) */
/* 762 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 766 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 768 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 770 */	NdrFcShort( 0x10 ),	/* 16 */
/* 772 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 774 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 776 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (762) */
			0x5b,		/* FC_END */
/* 780 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 782 */	NdrFcShort( 0x18 ),	/* 24 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0xa ),	/* Offset= 10 (796) */
/* 788 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 790 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 792 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (768) */
/* 794 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 796 */	
			0x11, 0x0,	/* FC_RP */
/* 798 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (540) */
/* 800 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 802 */	NdrFcShort( 0x1 ),	/* 1 */
/* 804 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 810 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 812 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 814 */	NdrFcShort( 0x8 ),	/* 8 */
/* 816 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 818 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 820 */	NdrFcShort( 0x4 ),	/* 4 */
/* 822 */	NdrFcShort( 0x4 ),	/* 4 */
/* 824 */	0x12, 0x0,	/* FC_UP */
/* 826 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (800) */
/* 828 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 830 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 832 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 834 */	NdrFcShort( 0x2 ),	/* 2 */
/* 836 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 842 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 844 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 850 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 852 */	NdrFcShort( 0x4 ),	/* 4 */
/* 854 */	NdrFcShort( 0x4 ),	/* 4 */
/* 856 */	0x12, 0x0,	/* FC_UP */
/* 858 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (832) */
/* 860 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 862 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 864 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 866 */	NdrFcShort( 0x4 ),	/* 4 */
/* 868 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 874 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 876 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 880 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 882 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 884 */	NdrFcShort( 0x4 ),	/* 4 */
/* 886 */	NdrFcShort( 0x4 ),	/* 4 */
/* 888 */	0x12, 0x0,	/* FC_UP */
/* 890 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (864) */
/* 892 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 894 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 896 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 906 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 908 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 912 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 914 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 916 */	NdrFcShort( 0x4 ),	/* 4 */
/* 918 */	NdrFcShort( 0x4 ),	/* 4 */
/* 920 */	0x12, 0x0,	/* FC_UP */
/* 922 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (896) */
/* 924 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 926 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 928 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 934 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 936 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 942 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 944 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 946 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 948 */	NdrFcShort( 0xffec ),	/* Offset= -20 (928) */
/* 950 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 952 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 954 */	NdrFcShort( 0x28 ),	/* 40 */
/* 956 */	NdrFcShort( 0xffec ),	/* Offset= -20 (936) */
/* 958 */	NdrFcShort( 0x0 ),	/* Offset= 0 (958) */
/* 960 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 962 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 964 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 966 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (420) */
/* 968 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 970 */	
			0x12, 0x0,	/* FC_UP */
/* 972 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (694) */
/* 974 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 976 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 978 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 980 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 982 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 984 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 986 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 988 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 990 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 992 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 994 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 996 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 998 */	
			0x12, 0x0,	/* FC_UP */
/* 1000 */	NdrFcShort( 0xfd82 ),	/* Offset= -638 (362) */
/* 1002 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1004 */	NdrFcShort( 0xfd84 ),	/* Offset= -636 (368) */
/* 1006 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1008 */	NdrFcShort( 0xfc3a ),	/* Offset= -966 (42) */
/* 1010 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1012 */	NdrFcShort( 0xfd96 ),	/* Offset= -618 (394) */
/* 1014 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1016 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (412) */
/* 1018 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 1020 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1022) */
/* 1022 */	
			0x12, 0x0,	/* FC_UP */
/* 1024 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1044) */
/* 1026 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1028 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1030 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1032 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1034 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1036 */	
			0x12, 0x0,	/* FC_UP */
/* 1038 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1026) */
/* 1040 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 1042 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1044 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1046 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1050) */
/* 1052 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1054 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1056 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1058 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1060 */	NdrFcShort( 0xfc1c ),	/* Offset= -996 (64) */
/* 1062 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1064 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0xfc0c ),	/* Offset= -1012 (60) */
/* 1074 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1076 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1082) */
/* 1078 */	
			0x13, 0x0,	/* FC_OP */
/* 1080 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (1044) */
/* 1082 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1086 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1078) */
/* 1092 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1094 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1096 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1098 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1100) */
/* 1100 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1102 */	NdrFcLong( 0xb3dd10e9 ),	/* -1277357847 */
/* 1106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1108 */	NdrFcShort( 0x4dc1 ),	/* 19905 */
/* 1110 */	0x83,		/* 131 */
			0xb6,		/* 182 */
/* 1112 */	0x2c,		/* 44 */
			0xa5,		/* 165 */
/* 1114 */	0xbb,		/* 187 */
			0xfe,		/* 254 */
/* 1116 */	0x22,		/* 34 */
			0xc4,		/* 196 */
/* 1118 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1120 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1122 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1124 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1126) */
/* 1126 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1128 */	NdrFcLong( 0x3a6ad31a ),	/* 980079386 */
/* 1132 */	NdrFcShort( 0xac74 ),	/* -21388 */
/* 1134 */	NdrFcShort( 0x4fbd ),	/* 20413 */
/* 1136 */	0x93,		/* 147 */
			0x67,		/* 103 */
/* 1138 */	0x44,		/* 68 */
			0xdb,		/* 219 */
/* 1140 */	0x39,		/* 57 */
			0x69,		/* 105 */
/* 1142 */	0x75,		/* 117 */
			0x5d,		/* 93 */
/* 1144 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1146 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1148) */
/* 1148 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1158 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1160 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1162 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1164 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1166 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1168 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1170) */
/* 1170 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1172 */	NdrFcLong( 0x48842d72 ),	/* 1216621938 */
/* 1176 */	NdrFcShort( 0x2d00 ),	/* 11520 */
/* 1178 */	NdrFcShort( 0x42fb ),	/* 17147 */
/* 1180 */	0x86,		/* 134 */
			0x6,		/* 6 */
/* 1182 */	0x52,		/* 82 */
			0x19,		/* 25 */
/* 1184 */	0x15,		/* 21 */
			0x11,		/* 17 */
/* 1186 */	0x9d,		/* 157 */
			0xf6,		/* 246 */
/* 1188 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1190 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1192) */
/* 1192 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1194 */	NdrFcLong( 0x6a05261 ),	/* 111170145 */
/* 1198 */	NdrFcShort( 0x2b86 ),	/* 11142 */
/* 1200 */	NdrFcShort( 0x4e72 ),	/* 20082 */
/* 1202 */	0xbb,		/* 187 */
			0x3f,		/* 63 */
/* 1204 */	0xb,		/* 11 */
			0x0,		/* 0 */
/* 1206 */	0xc9,		/* 201 */
			0xee,		/* 238 */
/* 1208 */	0x3e,		/* 62 */
			0x38,		/* 56 */
/* 1210 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1212 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1214) */
/* 1214 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1216 */	NdrFcLong( 0x95e596a ),	/* 157178218 */
/* 1220 */	NdrFcShort( 0x7292 ),	/* 29330 */
/* 1222 */	NdrFcShort( 0x4a46 ),	/* 19014 */
/* 1224 */	0x84,		/* 132 */
			0xea,		/* 234 */
/* 1226 */	0x83,		/* 131 */
			0xb3,		/* 179 */
/* 1228 */	0xb6,		/* 182 */
			0x3,		/* 3 */
/* 1230 */	0x6c,		/* 108 */
			0x17,		/* 23 */
/* 1232 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1234 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1236) */
/* 1236 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1238 */	NdrFcLong( 0x40fd88e4 ),	/* 1090357476 */
/* 1242 */	NdrFcShort( 0x9ef2 ),	/* -24846 */
/* 1244 */	NdrFcShort( 0x4e2c ),	/* 20012 */
/* 1246 */	0x83,		/* 131 */
			0x9e,		/* 158 */
/* 1248 */	0x2c,		/* 44 */
			0x6b,		/* 107 */
/* 1250 */	0x7e,		/* 126 */
			0x68,		/* 104 */
/* 1252 */	0x37,		/* 55 */
			0xaf,		/* 175 */
/* 1254 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1256 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1258) */
/* 1258 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1260 */	NdrFcLong( 0x64fd3185 ),	/* 1694314885 */
/* 1264 */	NdrFcShort( 0x9e5a ),	/* -24998 */
/* 1266 */	NdrFcShort( 0x41d9 ),	/* 16857 */
/* 1268 */	0xbd,		/* 189 */
			0x2b,		/* 43 */
/* 1270 */	0xd4,		/* 212 */
			0xf8,		/* 248 */
/* 1272 */	0xfd,		/* 253 */
			0xed,		/* 237 */
/* 1274 */	0xd6,		/* 214 */
			0x66,		/* 102 */
/* 1276 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1278 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1280 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1282 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1284) */
/* 1284 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1286 */	NdrFcLong( 0x11d2320e ),	/* 298988046 */
/* 1290 */	NdrFcShort( 0xe03a ),	/* -8134 */
/* 1292 */	NdrFcShort( 0x4827 ),	/* 18471 */
/* 1294 */	0xba,		/* 186 */
			0x16,		/* 22 */
/* 1296 */	0x9b,		/* 155 */
			0x69,		/* 105 */
/* 1298 */	0x55,		/* 85 */
			0xc9,		/* 201 */
/* 1300 */	0x90,		/* 144 */
			0xa8,		/* 168 */
/* 1302 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1304 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1306) */
/* 1306 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1308 */	NdrFcLong( 0x4506665a ),	/* 1158047322 */
/* 1312 */	NdrFcShort( 0x662b ),	/* 26155 */
/* 1314 */	NdrFcShort( 0x4067 ),	/* 16487 */
/* 1316 */	0xab,		/* 171 */
			0xc2,		/* 194 */
/* 1318 */	0xb9,		/* 185 */
			0xe2,		/* 226 */
/* 1320 */	0x7b,		/* 123 */
			0x50,		/* 80 */
/* 1322 */	0xd0,		/* 208 */
			0x92,		/* 146 */
/* 1324 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1326 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1328) */
/* 1328 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1330 */	NdrFcLong( 0xf691bf16 ),	/* -158220522 */
/* 1334 */	NdrFcShort( 0x41c6 ),	/* 16838 */
/* 1336 */	NdrFcShort( 0x433c ),	/* 17212 */
/* 1338 */	0xae,		/* 174 */
			0x22,		/* 34 */
/* 1340 */	0x88,		/* 136 */
			0x1a,		/* 26 */
/* 1342 */	0xf0,		/* 240 */
			0x33,		/* 51 */
/* 1344 */	0x47,		/* 71 */
			0xf8,		/* 248 */
/* 1346 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1348 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1350 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1352 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1354 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 1356 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1358) */
/* 1358 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1360 */	NdrFcLong( 0x5874cfc ),	/* 92753148 */
/* 1364 */	NdrFcShort( 0x144f ),	/* 5199 */
/* 1366 */	NdrFcShort( 0x4812 ),	/* 18450 */
/* 1368 */	0xb7,		/* 183 */
			0xae,		/* 174 */
/* 1370 */	0x12,		/* 18 */
			0x4,		/* 4 */
/* 1372 */	0x7f,		/* 127 */
			0xea,		/* 234 */
/* 1374 */	0x26,		/* 38 */
			0x99,		/* 153 */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Standard interface: __MIDL_itf_AnvizOcx_0000_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDevice, ver. 0.0,
   GUID={0xDB384A48,0x1CD4,0x40ac,{0xB2,0x47,0xDB,0x60,0x6B,0x35,0x0A,0xC3}} */

#pragma code_seg(".orpc")
static const unsigned short IDevice_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36
    };

static const MIDL_STUBLESS_PROXY_INFO IDevice_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDevice_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDevice_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDevice_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IDeviceProxyVtbl = 
{
    &IDevice_ProxyInfo,
    &IID_IDevice,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDevice::LinkBus */ ,
    (void *) (INT_PTR) -1 /* IDevice::UnlinkBus */
};


static const PRPC_STUB_FUNCTION IDevice_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDeviceStubVtbl =
{
    &IID_IDevice,
    &IDevice_ServerInfo,
    9,
    &IDevice_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IBus, ver. 0.0,
   GUID={0xF35C0B16,0xBEC1,0x4c01,{0x9B,0x78,0xA6,0x62,0x90,0x38,0xDC,0x92}} */

#pragma code_seg(".orpc")
static const unsigned short IBus_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    66
    };

static const MIDL_STUBLESS_PROXY_INFO IBus_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IBus_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBus_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IBus_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IBusProxyVtbl = 
{
    &IBus_ProxyInfo,
    &IID_IBus,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IBus::SendData */
};


static const PRPC_STUB_FUNCTION IBus_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IBusStubVtbl =
{
    &IID_IBus,
    &IBus_ServerInfo,
    8,
    &IBus_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAnvizItems, ver. 0.0,
   GUID={0xB3DD10E9,0x0000,0x4DC1,{0x83,0xB6,0x2C,0xA5,0xBB,0xFE,0x22,0xC4}} */

#pragma code_seg(".orpc")
static const unsigned short IAnvizItems_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    102,
    138,
    180,
    216,
    258,
    294
    };

static const MIDL_STUBLESS_PROXY_INFO IAnvizItems_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IAnvizItems_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAnvizItems_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IAnvizItems_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IAnvizItemsProxyVtbl = 
{
    &IAnvizItems_ProxyInfo,
    &IID_IAnvizItems,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IAnvizItems::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IAnvizItems::get_Item */ ,
    (void *) (INT_PTR) -1 /* IAnvizItems::get_Count */ ,
    (void *) (INT_PTR) -1 /* IAnvizItems::Add */ ,
    (void *) (INT_PTR) -1 /* IAnvizItems::Remove */ ,
    (void *) (INT_PTR) -1 /* IAnvizItems::Clear */
};


static const PRPC_STUB_FUNCTION IAnvizItems_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IAnvizItemsStubVtbl =
{
    &IID_IAnvizItems,
    &IAnvizItems_ServerInfo,
    13,
    &IAnvizItems_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAnviz, ver. 0.0,
   GUID={0x678E6AB5,0xE9FF,0x44BD,{0x90,0xF9,0xC8,0xBD,0xDE,0xF1,0x87,0x14}} */

#pragma code_seg(".orpc")
static const unsigned short IAnviz_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    324
    };

static const MIDL_STUBLESS_PROXY_INFO IAnviz_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IAnviz_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAnviz_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IAnviz_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IAnvizProxyVtbl = 
{
    &IAnviz_ProxyInfo,
    &IID_IAnviz,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IAnviz::get_BusItems */
};


static const PRPC_STUB_FUNCTION IAnviz_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IAnvizStubVtbl =
{
    &IID_IAnviz,
    &IAnviz_ServerInfo,
    8,
    &IAnviz_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IComBus, ver. 0.0,
   GUID={0xDC441879,0x14CB,0x4C26,{0x83,0xED,0x87,0xE7,0x7E,0xE5,0x18,0xDD}} */

#pragma code_seg(".orpc")
static const unsigned short IComBus_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    324
    };

static const MIDL_STUBLESS_PROXY_INFO IComBus_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IComBus_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IComBus_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IComBus_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IComBusProxyVtbl = 
{
    &IComBus_ProxyInfo,
    &IID_IComBus,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IComBus::get_MachineItem */
};


static const PRPC_STUB_FUNCTION IComBus_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IComBusStubVtbl =
{
    &IID_IComBus,
    &IComBus_ServerInfo,
    8,
    &IComBus_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ITimeList, ver. 0.0,
   GUID={0x3A6AD31A,0xAC74,0x4FBD,{0x93,0x67,0x44,0xDB,0x39,0x69,0x75,0x5D}} */

#pragma code_seg(".orpc")
static const unsigned short ITimeList_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    360,
    402,
    444,
    486,
    528,
    564,
    600,
    642,
    678
    };

static const MIDL_STUBLESS_PROXY_INFO ITimeList_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &ITimeList_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITimeList_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &ITimeList_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _ITimeListProxyVtbl = 
{
    &ITimeList_ProxyInfo,
    &IID_ITimeList,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ITimeList::get_Hour */ ,
    (void *) (INT_PTR) -1 /* ITimeList::put_Hour */ ,
    (void *) (INT_PTR) -1 /* ITimeList::get_Minute */ ,
    (void *) (INT_PTR) -1 /* ITimeList::put_Minute */ ,
    (void *) (INT_PTR) -1 /* ITimeList::get_Other */ ,
    (void *) (INT_PTR) -1 /* ITimeList::put_Other */ ,
    (void *) (INT_PTR) -1 /* ITimeList::IsDay */ ,
    (void *) (INT_PTR) -1 /* ITimeList::SetDay */ ,
    (void *) (INT_PTR) -1 /* ITimeList::get_ID */
};


static const PRPC_STUB_FUNCTION ITimeList_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ITimeListStubVtbl =
{
    &IID_ITimeList,
    &ITimeList_ServerInfo,
    16,
    &ITimeList_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ITimeLists, ver. 0.0,
   GUID={0x48842D72,0x2D00,0x42FB,{0x86,0x06,0x52,0x19,0x15,0x11,0x9D,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short ITimeLists_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    714,
    756,
    180
    };

static const MIDL_STUBLESS_PROXY_INFO ITimeLists_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &ITimeLists_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITimeLists_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &ITimeLists_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _ITimeListsProxyVtbl = 
{
    &ITimeLists_ProxyInfo,
    &IID_ITimeLists,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ITimeLists::get_Item */ ,
    (void *) (INT_PTR) -1 /* ITimeLists::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* ITimeLists::get_Count */
};


static const PRPC_STUB_FUNCTION ITimeLists_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ITimeListsStubVtbl =
{
    &IID_ITimeLists,
    &ITimeLists_ServerInfo,
    10,
    &ITimeLists_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDoorGroup, ver. 0.0,
   GUID={0x06A05261,0x2B86,0x4E72,{0xBB,0x3F,0x0B,0x00,0xC9,0xEE,0x3E,0x38}} */

#pragma code_seg(".orpc")
static const unsigned short IDoorGroup_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    792,
    828,
    864,
    894,
    924,
    960
    };

static const MIDL_STUBLESS_PROXY_INFO IDoorGroup_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDoorGroup_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDoorGroup_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDoorGroup_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IDoorGroupProxyVtbl = 
{
    &IDoorGroup_ProxyInfo,
    &IID_IDoorGroup,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDoorGroup::get_Power */ ,
    (void *) (INT_PTR) -1 /* IDoorGroup::put_Power */ ,
    (void *) (INT_PTR) -1 /* IDoorGroup::Updata */ ,
    (void *) (INT_PTR) -1 /* IDoorGroup::Download */ ,
    (void *) (INT_PTR) -1 /* IDoorGroup::get_TimeLists */ ,
    (void *) (INT_PTR) -1 /* IDoorGroup::get_ID */
};


static const PRPC_STUB_FUNCTION IDoorGroup_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDoorGroupStubVtbl =
{
    &IID_IDoorGroup,
    &IDoorGroup_ServerInfo,
    13,
    &IDoorGroup_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDoorGroups, ver. 0.0,
   GUID={0x40FD88E4,0x9EF2,0x4E2C,{0x83,0x9E,0x2C,0x6B,0x7E,0x68,0x37,0xAF}} */

#pragma code_seg(".orpc")
static const unsigned short IDoorGroups_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    996,
    1032,
    180
    };

static const MIDL_STUBLESS_PROXY_INFO IDoorGroups_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDoorGroups_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDoorGroups_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDoorGroups_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IDoorGroupsProxyVtbl = 
{
    &IDoorGroups_ProxyInfo,
    &IID_IDoorGroups,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDoorGroups::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IDoorGroups::get_Item */ ,
    (void *) (INT_PTR) -1 /* IDoorGroups::get_Count */
};


static const PRPC_STUB_FUNCTION IDoorGroups_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDoorGroupsStubVtbl =
{
    &IID_IDoorGroups,
    &IDoorGroups_ServerInfo,
    10,
    &IDoorGroups_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDoorState, ver. 0.0,
   GUID={0x095E596A,0x7292,0x4A46,{0x84,0xEA,0x83,0xB3,0xB6,0x03,0x6C,0x17}} */

#pragma code_seg(".orpc")
static const unsigned short IDoorState_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1074,
    1110,
    1146,
    894,
    1182,
    960
    };

static const MIDL_STUBLESS_PROXY_INFO IDoorState_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDoorState_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDoorState_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDoorState_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IDoorStateProxyVtbl = 
{
    &IDoorState_ProxyInfo,
    &IID_IDoorState,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDoorState::get_TimeList */ ,
    (void *) (INT_PTR) -1 /* IDoorState::get_State */ ,
    (void *) (INT_PTR) -1 /* IDoorState::put_State */ ,
    (void *) (INT_PTR) -1 /* IDoorState::Updata */ ,
    (void *) (INT_PTR) -1 /* IDoorState::Download */ ,
    (void *) (INT_PTR) -1 /* IDoorState::get_ID */
};


static const PRPC_STUB_FUNCTION IDoorState_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDoorStateStubVtbl =
{
    &IID_IDoorState,
    &IDoorState_ServerInfo,
    13,
    &IDoorState_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDoorStates, ver. 0.0,
   GUID={0x4506665A,0x662B,0x4067,{0xAB,0xC2,0xB9,0xE2,0x7B,0x50,0xD0,0x92}} */

#pragma code_seg(".orpc")
static const unsigned short IDoorStates_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1212,
    756,
    180
    };

static const MIDL_STUBLESS_PROXY_INFO IDoorStates_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDoorStates_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDoorStates_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDoorStates_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IDoorStatesProxyVtbl = 
{
    &IDoorStates_ProxyInfo,
    &IID_IDoorStates,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDoorStates::get_Item */ ,
    (void *) (INT_PTR) -1 /* IDoorStates::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IDoorStates::get_Count */
};


static const PRPC_STUB_FUNCTION IDoorStates_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDoorStatesStubVtbl =
{
    &IID_IDoorStates,
    &IDoorStates_ServerInfo,
    10,
    &IDoorStates_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IUser, ver. 0.0,
   GUID={0x64FD3185,0x9E5A,0x41D9,{0xBD,0x2B,0xD4,0xF8,0xFD,0xED,0xD6,0x66}} */

#pragma code_seg(".orpc")
static const unsigned short IUser_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1248,
    1284,
    1146,
    1320,
    1356,
    1392,
    1434,
    1470,
    678,
    1506,
    1536
    };

static const MIDL_STUBLESS_PROXY_INFO IUser_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IUser_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IUser_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IUser_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IUserProxyVtbl = 
{
    &IUser_ProxyInfo,
    &IID_IUser,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IUser::AddGroup */ ,
    (void *) (INT_PTR) -1 /* IUser::get_Groups */ ,
    (void *) (INT_PTR) -1 /* IUser::RemoveGroup */ ,
    (void *) (INT_PTR) -1 /* IUser::SetAttrib */ ,
    (void *) (INT_PTR) -1 /* IUser::ClearAttrib */ ,
    (void *) (INT_PTR) -1 /* IUser::GetAttrib */ ,
    (void *) (INT_PTR) -1 /* IUser::get_CardID */ ,
    (void *) (INT_PTR) -1 /* IUser::get_AreaID */ ,
    (void *) (INT_PTR) -1 /* IUser::get_UserID */ ,
    (void *) (INT_PTR) -1 /* IUser::Updata */ ,
    (void *) (INT_PTR) -1 /* IUser::Download */
};


static const PRPC_STUB_FUNCTION IUser_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IUserStubVtbl =
{
    &IID_IUser,
    &IUser_ServerInfo,
    18,
    &IUser_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IUsers, ver. 0.0,
   GUID={0xF691BF16,0x41C6,0x433C,{0xAE,0x22,0x88,0x1A,0xF0,0x33,0x47,0xF8}} */

#pragma code_seg(".orpc")
static const unsigned short IUsers_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1566,
    756,
    1608,
    1662,
    1182,
    294,
    1434
    };

static const MIDL_STUBLESS_PROXY_INFO IUsers_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IUsers_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IUsers_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IUsers_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IUsersProxyVtbl = 
{
    &IUsers_ProxyInfo,
    &IID_IUsers,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IUsers::get_Item */ ,
    (void *) (INT_PTR) -1 /* IUsers::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IUsers::Add */ ,
    (void *) (INT_PTR) -1 /* IUsers::Remove */ ,
    (void *) (INT_PTR) -1 /* IUsers::Updata */ ,
    (void *) (INT_PTR) -1 /* IUsers::Download */ ,
    (void *) (INT_PTR) -1 /* IUsers::get_Count */
};


static const PRPC_STUB_FUNCTION IUsers_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IUsersStubVtbl =
{
    &IID_IUsers,
    &IUsers_ServerInfo,
    14,
    &IUsers_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDeviceLog, ver. 0.0,
   GUID={0x11D2320E,0xE03A,0x4827,{0xBA,0x16,0x9B,0x69,0x55,0xC9,0x90,0xA8}} */

#pragma code_seg(".orpc")
static const unsigned short IDeviceLog_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    792,
    1110,
    180,
    1710,
    1746,
    960,
    1434
    };

static const MIDL_STUBLESS_PROXY_INFO IDeviceLog_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDeviceLog_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDeviceLog_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDeviceLog_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IDeviceLogProxyVtbl = 
{
    &IDeviceLog_ProxyInfo,
    &IID_IDeviceLog,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDeviceLog::get_LogID */ ,
    (void *) (INT_PTR) -1 /* IDeviceLog::get_AreaID */ ,
    (void *) (INT_PTR) -1 /* IDeviceLog::get_CardID */ ,
    (void *) (INT_PTR) -1 /* IDeviceLog::get_UserID */ ,
    (void *) (INT_PTR) -1 /* IDeviceLog::get_DateTime */ ,
    (void *) (INT_PTR) -1 /* IDeviceLog::get_Node */ ,
    (void *) (INT_PTR) -1 /* IDeviceLog::get_EventID */
};


static const PRPC_STUB_FUNCTION IDeviceLog_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDeviceLogStubVtbl =
{
    &IID_IDeviceLog,
    &IDeviceLog_ServerInfo,
    14,
    &IDeviceLog_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IDeviceLogs, ver. 0.0,
   GUID={0x05874CFC,0x144F,0x4812,{0xB7,0xAE,0x12,0x04,0x7F,0xEA,0x26,0x99}} */

#pragma code_seg(".orpc")
static const unsigned short IDeviceLogs_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    996,
    1782,
    1824,
    1710
    };

static const MIDL_STUBLESS_PROXY_INFO IDeviceLogs_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDeviceLogs_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDeviceLogs_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IDeviceLogs_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IDeviceLogsProxyVtbl = 
{
    &IDeviceLogs_ProxyInfo,
    &IID_IDeviceLogs,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDeviceLogs::get__NewEnum */ ,
    (void *) (INT_PTR) -1 /* IDeviceLogs::get_Item */ ,
    (void *) (INT_PTR) -1 /* IDeviceLogs::Download */ ,
    (void *) (INT_PTR) -1 /* IDeviceLogs::get_Count */
};


static const PRPC_STUB_FUNCTION IDeviceLogs_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDeviceLogsStubVtbl =
{
    &IID_IDeviceLogs,
    &IDeviceLogs_ServerInfo,
    11,
    &IDeviceLogs_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IAMJ03, ver. 0.0,
   GUID={0x77342A19,0x4433,0x489D,{0x85,0x4B,0xAC,0xBA,0xC3,0x4D,0xF4,0x7A}} */

#pragma code_seg(".orpc")
static const unsigned short IAMJ03_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1866,
    1902,
    1944,
    1986,
    2028,
    2070,
    2106,
    2142,
    2184,
    2226,
    2262,
    2298,
    2340
    };

static const MIDL_STUBLESS_PROXY_INFO IAMJ03_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IAMJ03_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IAMJ03_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IAMJ03_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(20) _IAMJ03ProxyVtbl = 
{
    &IAMJ03_ProxyInfo,
    &IID_IAMJ03,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::get_DoorGroups */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::get_Attrib */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::put_Attrib */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::get_Status */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::put_Status */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::get_DoorStates */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::get_Users */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::GetRTCTime */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::SetRTCTime */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::get_MachineAddr */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::put_MachineAddr */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::GetDevVersion */ ,
    (void *) (INT_PTR) -1 /* IAMJ03::get_Logs */
};


static const PRPC_STUB_FUNCTION IAMJ03_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IAMJ03StubVtbl =
{
    &IID_IAMJ03,
    &IAMJ03_ServerInfo,
    20,
    &IAMJ03_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IBusPortData, ver. 0.0,
   GUID={0x014BA2C5,0x63D4,0x469F,{0x8A,0xFD,0xEC,0xDE,0xF4,0x2B,0x8B,0x63}} */

#pragma code_seg(".orpc")
static const unsigned short IBusPortData_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    792,
    1110,
    2376,
    1986,
    2028
    };

static const MIDL_STUBLESS_PROXY_INFO IBusPortData_ProxyInfo =
    {
    &Object_StubDesc,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IBusPortData_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IBusPortData_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    AnvizOcx__MIDL_ProcFormatString.Format,
    &IBusPortData_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IBusPortDataProxyVtbl = 
{
    &IBusPortData_ProxyInfo,
    &IID_IBusPortData,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IBusPortData::get_Buffer */ ,
    (void *) (INT_PTR) -1 /* IBusPortData::get_Size */ ,
    (void *) (INT_PTR) -1 /* IBusPortData::SetBuffer */ ,
    (void *) (INT_PTR) -1 /* IBusPortData::get_Param */ ,
    (void *) (INT_PTR) -1 /* IBusPortData::put_Param */
};


static const PRPC_STUB_FUNCTION IBusPortData_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IBusPortDataStubVtbl =
{
    &IID_IBusPortData,
    &IBusPortData_ServerInfo,
    12,
    &IBusPortData_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    AnvizOcx__MIDL_TypeFormatString.Format,
    0, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _AnvizOcx_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IDeviceLogProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBusProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IUsersProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAMJ03ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITimeListProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDeviceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDoorStatesProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDoorGroupProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDoorStateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITimeListsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IComBusProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IUserProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAnvizProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IBusPortDataProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDoorGroupsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IAnvizItemsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDeviceLogsProxyVtbl,
    0
};

const CInterfaceStubVtbl * _AnvizOcx_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IDeviceLogStubVtbl,
    ( CInterfaceStubVtbl *) &_IBusStubVtbl,
    ( CInterfaceStubVtbl *) &_IUsersStubVtbl,
    ( CInterfaceStubVtbl *) &_IAMJ03StubVtbl,
    ( CInterfaceStubVtbl *) &_ITimeListStubVtbl,
    ( CInterfaceStubVtbl *) &_IDeviceStubVtbl,
    ( CInterfaceStubVtbl *) &_IDoorStatesStubVtbl,
    ( CInterfaceStubVtbl *) &_IDoorGroupStubVtbl,
    ( CInterfaceStubVtbl *) &_IDoorStateStubVtbl,
    ( CInterfaceStubVtbl *) &_ITimeListsStubVtbl,
    ( CInterfaceStubVtbl *) &_IComBusStubVtbl,
    ( CInterfaceStubVtbl *) &_IUserStubVtbl,
    ( CInterfaceStubVtbl *) &_IAnvizStubVtbl,
    ( CInterfaceStubVtbl *) &_IBusPortDataStubVtbl,
    ( CInterfaceStubVtbl *) &_IDoorGroupsStubVtbl,
    ( CInterfaceStubVtbl *) &_IAnvizItemsStubVtbl,
    ( CInterfaceStubVtbl *) &_IDeviceLogsStubVtbl,
    0
};

PCInterfaceName const _AnvizOcx_InterfaceNamesList[] = 
{
    "IDeviceLog",
    "IBus",
    "IUsers",
    "IAMJ03",
    "ITimeList",
    "IDevice",
    "IDoorStates",
    "IDoorGroup",
    "IDoorState",
    "ITimeLists",
    "IComBus",
    "IUser",
    "IAnviz",
    "IBusPortData",
    "IDoorGroups",
    "IAnvizItems",
    "IDeviceLogs",
    0
};

const IID *  _AnvizOcx_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _AnvizOcx_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _AnvizOcx, pIID, n)

int __stdcall _AnvizOcx_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _AnvizOcx, 17, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _AnvizOcx, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _AnvizOcx, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _AnvizOcx, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _AnvizOcx, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _AnvizOcx, 17, *pIndex )
    
}

const ExtendedProxyFileInfo AnvizOcx_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _AnvizOcx_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _AnvizOcx_StubVtblList,
    (const PCInterfaceName * ) & _AnvizOcx_InterfaceNamesList,
    (const IID ** ) & _AnvizOcx_BaseIIDList,
    & _AnvizOcx_IID_Lookup, 
    17,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

