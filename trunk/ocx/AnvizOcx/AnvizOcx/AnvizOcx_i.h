

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AnvizOcx_i_h__
#define __AnvizOcx_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDevice_FWD_DEFINED__
#define __IDevice_FWD_DEFINED__
typedef interface IDevice IDevice;
#endif 	/* __IDevice_FWD_DEFINED__ */


#ifndef __IBus_FWD_DEFINED__
#define __IBus_FWD_DEFINED__
typedef interface IBus IBus;
#endif 	/* __IBus_FWD_DEFINED__ */


#ifndef __IAnvizItems_FWD_DEFINED__
#define __IAnvizItems_FWD_DEFINED__
typedef interface IAnvizItems IAnvizItems;
#endif 	/* __IAnvizItems_FWD_DEFINED__ */


#ifndef __IAnviz_FWD_DEFINED__
#define __IAnviz_FWD_DEFINED__
typedef interface IAnviz IAnviz;
#endif 	/* __IAnviz_FWD_DEFINED__ */


#ifndef __IComBus_FWD_DEFINED__
#define __IComBus_FWD_DEFINED__
typedef interface IComBus IComBus;
#endif 	/* __IComBus_FWD_DEFINED__ */


#ifndef __ITimeList_FWD_DEFINED__
#define __ITimeList_FWD_DEFINED__
typedef interface ITimeList ITimeList;
#endif 	/* __ITimeList_FWD_DEFINED__ */


#ifndef __ITimeLists_FWD_DEFINED__
#define __ITimeLists_FWD_DEFINED__
typedef interface ITimeLists ITimeLists;
#endif 	/* __ITimeLists_FWD_DEFINED__ */


#ifndef __IDoorGroup_FWD_DEFINED__
#define __IDoorGroup_FWD_DEFINED__
typedef interface IDoorGroup IDoorGroup;
#endif 	/* __IDoorGroup_FWD_DEFINED__ */


#ifndef __IDoorGroups_FWD_DEFINED__
#define __IDoorGroups_FWD_DEFINED__
typedef interface IDoorGroups IDoorGroups;
#endif 	/* __IDoorGroups_FWD_DEFINED__ */


#ifndef __IDoorState_FWD_DEFINED__
#define __IDoorState_FWD_DEFINED__
typedef interface IDoorState IDoorState;
#endif 	/* __IDoorState_FWD_DEFINED__ */


#ifndef __IDoorStates_FWD_DEFINED__
#define __IDoorStates_FWD_DEFINED__
typedef interface IDoorStates IDoorStates;
#endif 	/* __IDoorStates_FWD_DEFINED__ */


#ifndef __IUser_FWD_DEFINED__
#define __IUser_FWD_DEFINED__
typedef interface IUser IUser;
#endif 	/* __IUser_FWD_DEFINED__ */


#ifndef __IUsers_FWD_DEFINED__
#define __IUsers_FWD_DEFINED__
typedef interface IUsers IUsers;
#endif 	/* __IUsers_FWD_DEFINED__ */


#ifndef __IDeviceLog_FWD_DEFINED__
#define __IDeviceLog_FWD_DEFINED__
typedef interface IDeviceLog IDeviceLog;
#endif 	/* __IDeviceLog_FWD_DEFINED__ */


#ifndef __IDeviceLogs_FWD_DEFINED__
#define __IDeviceLogs_FWD_DEFINED__
typedef interface IDeviceLogs IDeviceLogs;
#endif 	/* __IDeviceLogs_FWD_DEFINED__ */


#ifndef __IAMJ03_FWD_DEFINED__
#define __IAMJ03_FWD_DEFINED__
typedef interface IAMJ03 IAMJ03;
#endif 	/* __IAMJ03_FWD_DEFINED__ */


#ifndef __IBusPortData_FWD_DEFINED__
#define __IBusPortData_FWD_DEFINED__
typedef interface IBusPortData IBusPortData;
#endif 	/* __IBusPortData_FWD_DEFINED__ */


#ifndef ___IAnvizEvents_FWD_DEFINED__
#define ___IAnvizEvents_FWD_DEFINED__
typedef interface _IAnvizEvents _IAnvizEvents;
#endif 	/* ___IAnvizEvents_FWD_DEFINED__ */


#ifndef __Anviz_FWD_DEFINED__
#define __Anviz_FWD_DEFINED__

#ifdef __cplusplus
typedef class Anviz Anviz;
#else
typedef struct Anviz Anviz;
#endif /* __cplusplus */

#endif 	/* __Anviz_FWD_DEFINED__ */


#ifndef __AnvizItems_FWD_DEFINED__
#define __AnvizItems_FWD_DEFINED__

#ifdef __cplusplus
typedef class AnvizItems AnvizItems;
#else
typedef struct AnvizItems AnvizItems;
#endif /* __cplusplus */

#endif 	/* __AnvizItems_FWD_DEFINED__ */


#ifndef __ComBus_FWD_DEFINED__
#define __ComBus_FWD_DEFINED__

#ifdef __cplusplus
typedef class ComBus ComBus;
#else
typedef struct ComBus ComBus;
#endif /* __cplusplus */

#endif 	/* __ComBus_FWD_DEFINED__ */


#ifndef __AMJ03_FWD_DEFINED__
#define __AMJ03_FWD_DEFINED__

#ifdef __cplusplus
typedef class AMJ03 AMJ03;
#else
typedef struct AMJ03 AMJ03;
#endif /* __cplusplus */

#endif 	/* __AMJ03_FWD_DEFINED__ */


#ifndef __DoorGroup_FWD_DEFINED__
#define __DoorGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class DoorGroup DoorGroup;
#else
typedef struct DoorGroup DoorGroup;
#endif /* __cplusplus */

#endif 	/* __DoorGroup_FWD_DEFINED__ */


#ifndef __TimeList_FWD_DEFINED__
#define __TimeList_FWD_DEFINED__

#ifdef __cplusplus
typedef class TimeList TimeList;
#else
typedef struct TimeList TimeList;
#endif /* __cplusplus */

#endif 	/* __TimeList_FWD_DEFINED__ */


#ifndef __TimeLists_FWD_DEFINED__
#define __TimeLists_FWD_DEFINED__

#ifdef __cplusplus
typedef class TimeLists TimeLists;
#else
typedef struct TimeLists TimeLists;
#endif /* __cplusplus */

#endif 	/* __TimeLists_FWD_DEFINED__ */


#ifndef __DoorGroups_FWD_DEFINED__
#define __DoorGroups_FWD_DEFINED__

#ifdef __cplusplus
typedef class DoorGroups DoorGroups;
#else
typedef struct DoorGroups DoorGroups;
#endif /* __cplusplus */

#endif 	/* __DoorGroups_FWD_DEFINED__ */


#ifndef __DoorStates_FWD_DEFINED__
#define __DoorStates_FWD_DEFINED__

#ifdef __cplusplus
typedef class DoorStates DoorStates;
#else
typedef struct DoorStates DoorStates;
#endif /* __cplusplus */

#endif 	/* __DoorStates_FWD_DEFINED__ */


#ifndef __DoorState_FWD_DEFINED__
#define __DoorState_FWD_DEFINED__

#ifdef __cplusplus
typedef class DoorState DoorState;
#else
typedef struct DoorState DoorState;
#endif /* __cplusplus */

#endif 	/* __DoorState_FWD_DEFINED__ */


#ifndef __User_FWD_DEFINED__
#define __User_FWD_DEFINED__

#ifdef __cplusplus
typedef class User User;
#else
typedef struct User User;
#endif /* __cplusplus */

#endif 	/* __User_FWD_DEFINED__ */


#ifndef __Users_FWD_DEFINED__
#define __Users_FWD_DEFINED__

#ifdef __cplusplus
typedef class Users Users;
#else
typedef struct Users Users;
#endif /* __cplusplus */

#endif 	/* __Users_FWD_DEFINED__ */


#ifndef __DeviceLog_FWD_DEFINED__
#define __DeviceLog_FWD_DEFINED__

#ifdef __cplusplus
typedef class DeviceLog DeviceLog;
#else
typedef struct DeviceLog DeviceLog;
#endif /* __cplusplus */

#endif 	/* __DeviceLog_FWD_DEFINED__ */


#ifndef __DeviceLogs_FWD_DEFINED__
#define __DeviceLogs_FWD_DEFINED__

#ifdef __cplusplus
typedef class DeviceLogs DeviceLogs;
#else
typedef struct DeviceLogs DeviceLogs;
#endif /* __cplusplus */

#endif 	/* __DeviceLogs_FWD_DEFINED__ */


#ifndef __BusPortData_FWD_DEFINED__
#define __BusPortData_FWD_DEFINED__

#ifdef __cplusplus
typedef class BusPortData BusPortData;
#else
typedef struct BusPortData BusPortData;
#endif /* __cplusplus */

#endif 	/* __BusPortData_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_AnvizOcx_0000_0000 */
/* [local] */ 


enum Anviz_WeekValue
    {	Sun	= 0,
	Mon	= 0x1,
	Tue	= 0x2,
	Wed	= 0x3,
	Thu	= 0x4,
	Fri	= 0x5,
	Sat	= 0x6
    } ;

enum Anviz_TimeType
    {	t_Start	= 0x1,
	t_End	= 0x2
    } ;




extern RPC_IF_HANDLE __MIDL_itf_AnvizOcx_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AnvizOcx_0000_0000_v0_0_s_ifspec;

#ifndef __IDevice_INTERFACE_DEFINED__
#define __IDevice_INTERFACE_DEFINED__

/* interface IDevice */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB384A48-1CD4-40ac-B247-DB606B350AC3")
    IDevice : public IDispatch
    {
    public:
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE LinkBus( 
            /* [in] */ IBus *newValue) = 0;
        
        virtual /* [hidden][helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlinkBus( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDevice * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDevice * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LinkBus )( 
            IDevice * This,
            /* [in] */ IBus *newValue);
        
        /* [hidden][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlinkBus )( 
            IDevice * This);
        
        END_INTERFACE
    } IDeviceVtbl;

    interface IDevice
    {
        CONST_VTBL struct IDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDevice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDevice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDevice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDevice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDevice_LinkBus(This,newValue)	\
    ( (This)->lpVtbl -> LinkBus(This,newValue) ) 

#define IDevice_UnlinkBus(This)	\
    ( (This)->lpVtbl -> UnlinkBus(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDevice_INTERFACE_DEFINED__ */


#ifndef __IBus_INTERFACE_DEFINED__
#define __IBus_INTERFACE_DEFINED__

/* interface IBus */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IBus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F35C0B16-BEC1-4c01-9B78-A6629038DC92")
    IBus : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendData( 
            /* [in] */ IBusPortData *newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBus * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBus * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendData )( 
            IBus * This,
            /* [in] */ IBusPortData *newVal);
        
        END_INTERFACE
    } IBusVtbl;

    interface IBus
    {
        CONST_VTBL struct IBusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBus_SendData(This,newVal)	\
    ( (This)->lpVtbl -> SendData(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBus_INTERFACE_DEFINED__ */


#ifndef __IAnvizItems_INTERFACE_DEFINED__
#define __IAnvizItems_INTERFACE_DEFINED__

/* interface IAnvizItems */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAnvizItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B3DD10E9-0000-4DC1-83B6-2CA5BBFE22C4")
    IAnvizItems : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ VARIANT Key,
            /* [in] */ VARIANT Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAnvizItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAnvizItems * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAnvizItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAnvizItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAnvizItems * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAnvizItems * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAnvizItems * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAnvizItems * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IAnvizItems * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IAnvizItems * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IAnvizItems * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IAnvizItems * This,
            /* [in] */ VARIANT Key,
            /* [in] */ VARIANT Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IAnvizItems * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IAnvizItems * This);
        
        END_INTERFACE
    } IAnvizItemsVtbl;

    interface IAnvizItems
    {
        CONST_VTBL struct IAnvizItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAnvizItems_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAnvizItems_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAnvizItems_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAnvizItems_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAnvizItems_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAnvizItems_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAnvizItems_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAnvizItems_get__NewEnum(This,ppUnk)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppUnk) ) 

#define IAnvizItems_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IAnvizItems_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IAnvizItems_Add(This,Key,Value)	\
    ( (This)->lpVtbl -> Add(This,Key,Value) ) 

#define IAnvizItems_Remove(This,Index)	\
    ( (This)->lpVtbl -> Remove(This,Index) ) 

#define IAnvizItems_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAnvizItems_INTERFACE_DEFINED__ */


#ifndef __IAnviz_INTERFACE_DEFINED__
#define __IAnviz_INTERFACE_DEFINED__

/* interface IAnviz */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAnviz;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("678E6AB5-E9FF-44BD-90F9-C8BDDEF18714")
    IAnviz : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BusItems( 
            /* [retval][out] */ IAnvizItems **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAnvizVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAnviz * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAnviz * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAnviz * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAnviz * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAnviz * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAnviz * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAnviz * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BusItems )( 
            IAnviz * This,
            /* [retval][out] */ IAnvizItems **pVal);
        
        END_INTERFACE
    } IAnvizVtbl;

    interface IAnviz
    {
        CONST_VTBL struct IAnvizVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAnviz_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAnviz_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAnviz_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAnviz_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAnviz_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAnviz_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAnviz_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAnviz_get_BusItems(This,pVal)	\
    ( (This)->lpVtbl -> get_BusItems(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAnviz_INTERFACE_DEFINED__ */


#ifndef __IComBus_INTERFACE_DEFINED__
#define __IComBus_INTERFACE_DEFINED__

/* interface IComBus */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IComBus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DC441879-14CB-4C26-83ED-87E77EE518DD")
    IComBus : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MachineItem( 
            /* [retval][out] */ IAnvizItems **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IComBusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComBus * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComBus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComBus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComBus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComBus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComBus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComBus * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MachineItem )( 
            IComBus * This,
            /* [retval][out] */ IAnvizItems **pVal);
        
        END_INTERFACE
    } IComBusVtbl;

    interface IComBus
    {
        CONST_VTBL struct IComBusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComBus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComBus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComBus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComBus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IComBus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IComBus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IComBus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IComBus_get_MachineItem(This,pVal)	\
    ( (This)->lpVtbl -> get_MachineItem(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComBus_INTERFACE_DEFINED__ */


#ifndef __ITimeList_INTERFACE_DEFINED__
#define __ITimeList_INTERFACE_DEFINED__

/* interface ITimeList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITimeList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3A6AD31A-AC74-4FBD-9367-44DB3969755D")
    ITimeList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Hour( 
            /* [in] */ enum Anviz_TimeType Attrib,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Hour( 
            /* [in] */ enum Anviz_TimeType Attrib,
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Minute( 
            /* [in] */ enum Anviz_TimeType Attrib,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Minute( 
            /* [in] */ enum Anviz_TimeType Attrib,
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Other( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Other( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsDay( 
            /* [in] */ enum Anviz_WeekValue WeekofDay,
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDay( 
            /* [in] */ enum Anviz_WeekValue WeekofDay) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITimeListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITimeList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITimeList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITimeList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITimeList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITimeList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITimeList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITimeList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hour )( 
            ITimeList * This,
            /* [in] */ enum Anviz_TimeType Attrib,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hour )( 
            ITimeList * This,
            /* [in] */ enum Anviz_TimeType Attrib,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Minute )( 
            ITimeList * This,
            /* [in] */ enum Anviz_TimeType Attrib,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Minute )( 
            ITimeList * This,
            /* [in] */ enum Anviz_TimeType Attrib,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Other )( 
            ITimeList * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Other )( 
            ITimeList * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsDay )( 
            ITimeList * This,
            /* [in] */ enum Anviz_WeekValue WeekofDay,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDay )( 
            ITimeList * This,
            /* [in] */ enum Anviz_WeekValue WeekofDay);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            ITimeList * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } ITimeListVtbl;

    interface ITimeList
    {
        CONST_VTBL struct ITimeListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITimeList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITimeList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITimeList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITimeList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITimeList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITimeList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITimeList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITimeList_get_Hour(This,Attrib,pVal)	\
    ( (This)->lpVtbl -> get_Hour(This,Attrib,pVal) ) 

#define ITimeList_put_Hour(This,Attrib,newVal)	\
    ( (This)->lpVtbl -> put_Hour(This,Attrib,newVal) ) 

#define ITimeList_get_Minute(This,Attrib,pVal)	\
    ( (This)->lpVtbl -> get_Minute(This,Attrib,pVal) ) 

#define ITimeList_put_Minute(This,Attrib,newVal)	\
    ( (This)->lpVtbl -> put_Minute(This,Attrib,newVal) ) 

#define ITimeList_get_Other(This,pVal)	\
    ( (This)->lpVtbl -> get_Other(This,pVal) ) 

#define ITimeList_put_Other(This,newVal)	\
    ( (This)->lpVtbl -> put_Other(This,newVal) ) 

#define ITimeList_IsDay(This,WeekofDay,pRetVal)	\
    ( (This)->lpVtbl -> IsDay(This,WeekofDay,pRetVal) ) 

#define ITimeList_SetDay(This,WeekofDay)	\
    ( (This)->lpVtbl -> SetDay(This,WeekofDay) ) 

#define ITimeList_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITimeList_INTERFACE_DEFINED__ */


#ifndef __ITimeLists_INTERFACE_DEFINED__
#define __ITimeLists_INTERFACE_DEFINED__

/* interface ITimeLists */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITimeLists;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("48842D72-2D00-42FB-8606-521915119DF6")
    ITimeLists : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ ITimeList **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITimeListsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITimeLists * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITimeLists * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITimeLists * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITimeLists * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITimeLists * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITimeLists * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITimeLists * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ITimeLists * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ ITimeList **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            ITimeLists * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ITimeLists * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } ITimeListsVtbl;

    interface ITimeLists
    {
        CONST_VTBL struct ITimeListsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITimeLists_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITimeLists_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITimeLists_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITimeLists_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITimeLists_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITimeLists_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITimeLists_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITimeLists_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define ITimeLists_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define ITimeLists_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITimeLists_INTERFACE_DEFINED__ */


#ifndef __IDoorGroup_INTERFACE_DEFINED__
#define __IDoorGroup_INTERFACE_DEFINED__

/* interface IDoorGroup */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDoorGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("06A05261-2B86-4E72-BB3F-0B00C9EE3E38")
    IDoorGroup : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Power( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Power( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Updata( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TimeLists( 
            /* [retval][out] */ ITimeLists **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDoorGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDoorGroup * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDoorGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDoorGroup * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDoorGroup * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDoorGroup * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDoorGroup * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDoorGroup * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Power )( 
            IDoorGroup * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Power )( 
            IDoorGroup * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Updata )( 
            IDoorGroup * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            IDoorGroup * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeLists )( 
            IDoorGroup * This,
            /* [retval][out] */ ITimeLists **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IDoorGroup * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IDoorGroupVtbl;

    interface IDoorGroup
    {
        CONST_VTBL struct IDoorGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDoorGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDoorGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDoorGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDoorGroup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDoorGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDoorGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDoorGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDoorGroup_get_Power(This,pVal)	\
    ( (This)->lpVtbl -> get_Power(This,pVal) ) 

#define IDoorGroup_put_Power(This,newVal)	\
    ( (This)->lpVtbl -> put_Power(This,newVal) ) 

#define IDoorGroup_Updata(This)	\
    ( (This)->lpVtbl -> Updata(This) ) 

#define IDoorGroup_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IDoorGroup_get_TimeLists(This,pVal)	\
    ( (This)->lpVtbl -> get_TimeLists(This,pVal) ) 

#define IDoorGroup_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDoorGroup_INTERFACE_DEFINED__ */


#ifndef __IDoorGroups_INTERFACE_DEFINED__
#define __IDoorGroups_INTERFACE_DEFINED__

/* interface IDoorGroups */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDoorGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("40FD88E4-9EF2-4E2C-839E-2C6B7E6837AF")
    IDoorGroups : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IDoorGroup **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDoorGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDoorGroups * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDoorGroups * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDoorGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDoorGroups * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDoorGroups * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDoorGroups * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDoorGroups * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IDoorGroups * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IDoorGroups * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IDoorGroup **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IDoorGroups * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IDoorGroupsVtbl;

    interface IDoorGroups
    {
        CONST_VTBL struct IDoorGroupsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDoorGroups_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDoorGroups_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDoorGroups_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDoorGroups_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDoorGroups_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDoorGroups_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDoorGroups_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDoorGroups_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define IDoorGroups_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IDoorGroups_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDoorGroups_INTERFACE_DEFINED__ */


#ifndef __IDoorState_INTERFACE_DEFINED__
#define __IDoorState_INTERFACE_DEFINED__

/* interface IDoorState */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDoorState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("095E596A-7292-4A46-84EA-83B3B6036C17")
    IDoorState : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TimeList( 
            /* [retval][out] */ ITimeList **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_State( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Updata( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDoorStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDoorState * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDoorState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDoorState * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDoorState * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDoorState * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDoorState * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDoorState * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TimeList )( 
            IDoorState * This,
            /* [retval][out] */ ITimeList **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IDoorState * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_State )( 
            IDoorState * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Updata )( 
            IDoorState * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            IDoorState * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IDoorState * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IDoorStateVtbl;

    interface IDoorState
    {
        CONST_VTBL struct IDoorStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDoorState_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDoorState_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDoorState_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDoorState_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDoorState_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDoorState_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDoorState_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDoorState_get_TimeList(This,pVal)	\
    ( (This)->lpVtbl -> get_TimeList(This,pVal) ) 

#define IDoorState_get_State(This,pVal)	\
    ( (This)->lpVtbl -> get_State(This,pVal) ) 

#define IDoorState_put_State(This,newVal)	\
    ( (This)->lpVtbl -> put_State(This,newVal) ) 

#define IDoorState_Updata(This)	\
    ( (This)->lpVtbl -> Updata(This) ) 

#define IDoorState_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IDoorState_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDoorState_INTERFACE_DEFINED__ */


#ifndef __IDoorStates_INTERFACE_DEFINED__
#define __IDoorStates_INTERFACE_DEFINED__

/* interface IDoorStates */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDoorStates;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4506665A-662B-4067-ABC2-B9E27B50D092")
    IDoorStates : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [retval][out] */ IDoorState **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDoorStatesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDoorStates * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDoorStates * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDoorStates * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDoorStates * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDoorStates * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDoorStates * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDoorStates * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IDoorStates * This,
            /* [retval][out] */ IDoorState **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IDoorStates * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IDoorStates * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IDoorStatesVtbl;

    interface IDoorStates
    {
        CONST_VTBL struct IDoorStatesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDoorStates_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDoorStates_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDoorStates_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDoorStates_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDoorStates_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDoorStates_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDoorStates_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDoorStates_get_Item(This,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,pVal) ) 

#define IDoorStates_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define IDoorStates_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDoorStates_INTERFACE_DEFINED__ */


#ifndef __IUser_INTERFACE_DEFINED__
#define __IUser_INTERFACE_DEFINED__

/* interface IUser */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("64FD3185-9E5A-41D9-BD2B-D4F8FDEDD666")
    IUser : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddGroup( 
            /* [in] */ LONG GroupIndex) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Groups( 
            /* [retval][out] */ IDoorGroups **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveGroup( 
            /* [in] */ LONG GroupIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAttrib( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearAttrib( 
            /* [in] */ LONG Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAttrib( 
            /* [in] */ LONG Index,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CardID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AreaID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Updata( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUser * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUser * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddGroup )( 
            IUser * This,
            /* [in] */ LONG GroupIndex);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Groups )( 
            IUser * This,
            /* [retval][out] */ IDoorGroups **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveGroup )( 
            IUser * This,
            /* [in] */ LONG GroupIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAttrib )( 
            IUser * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearAttrib )( 
            IUser * This,
            /* [in] */ LONG Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAttrib )( 
            IUser * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CardID )( 
            IUser * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AreaID )( 
            IUser * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserID )( 
            IUser * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Updata )( 
            IUser * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            IUser * This);
        
        END_INTERFACE
    } IUserVtbl;

    interface IUser
    {
        CONST_VTBL struct IUserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUser_AddGroup(This,GroupIndex)	\
    ( (This)->lpVtbl -> AddGroup(This,GroupIndex) ) 

#define IUser_get_Groups(This,pVal)	\
    ( (This)->lpVtbl -> get_Groups(This,pVal) ) 

#define IUser_RemoveGroup(This,GroupIndex)	\
    ( (This)->lpVtbl -> RemoveGroup(This,GroupIndex) ) 

#define IUser_SetAttrib(This,Index)	\
    ( (This)->lpVtbl -> SetAttrib(This,Index) ) 

#define IUser_ClearAttrib(This,Index)	\
    ( (This)->lpVtbl -> ClearAttrib(This,Index) ) 

#define IUser_GetAttrib(This,Index,pVal)	\
    ( (This)->lpVtbl -> GetAttrib(This,Index,pVal) ) 

#define IUser_get_CardID(This,pVal)	\
    ( (This)->lpVtbl -> get_CardID(This,pVal) ) 

#define IUser_get_AreaID(This,pVal)	\
    ( (This)->lpVtbl -> get_AreaID(This,pVal) ) 

#define IUser_get_UserID(This,pVal)	\
    ( (This)->lpVtbl -> get_UserID(This,pVal) ) 

#define IUser_Updata(This)	\
    ( (This)->lpVtbl -> Updata(This) ) 

#define IUser_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUser_INTERFACE_DEFINED__ */


#ifndef __IUsers_INTERFACE_DEFINED__
#define __IUsers_INTERFACE_DEFINED__

/* interface IUsers */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUsers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F691BF16-41C6-433C-AE22-881AF03347F8")
    IUsers : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IUser **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ LONG Area,
            /* [in] */ LONG ID,
            /* [defaultvalue][in] */ LONG LongID,
            /* [retval][out] */ IUser **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ LONG Area,
            /* [in] */ LONG ID,
            /* [defaultvalue][in] */ LONG LongID = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Updata( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUsersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUsers * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUsers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUsers * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUsers * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUsers * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUsers * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUsers * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IUsers * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IUser **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IUsers * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IUsers * This,
            /* [in] */ LONG Area,
            /* [in] */ LONG ID,
            /* [defaultvalue][in] */ LONG LongID,
            /* [retval][out] */ IUser **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IUsers * This,
            /* [in] */ LONG Area,
            /* [in] */ LONG ID,
            /* [defaultvalue][in] */ LONG LongID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Updata )( 
            IUsers * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            IUsers * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IUsers * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IUsersVtbl;

    interface IUsers
    {
        CONST_VTBL struct IUsersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUsers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUsers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUsers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUsers_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUsers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUsers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUsers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUsers_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IUsers_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define IUsers_Add(This,Area,ID,LongID,pVal)	\
    ( (This)->lpVtbl -> Add(This,Area,ID,LongID,pVal) ) 

#define IUsers_Remove(This,Area,ID,LongID)	\
    ( (This)->lpVtbl -> Remove(This,Area,ID,LongID) ) 

#define IUsers_Updata(This)	\
    ( (This)->lpVtbl -> Updata(This) ) 

#define IUsers_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#define IUsers_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUsers_INTERFACE_DEFINED__ */


#ifndef __IDeviceLog_INTERFACE_DEFINED__
#define __IDeviceLog_INTERFACE_DEFINED__

/* interface IDeviceLog */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDeviceLog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11D2320E-E03A-4827-BA16-9B6955C990A8")
    IDeviceLog : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AreaID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CardID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DateTime( 
            /* [retval][out] */ DATE *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Node( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDeviceLogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDeviceLog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDeviceLog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDeviceLog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDeviceLog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDeviceLog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDeviceLog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDeviceLog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogID )( 
            IDeviceLog * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AreaID )( 
            IDeviceLog * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CardID )( 
            IDeviceLog * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserID )( 
            IDeviceLog * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DateTime )( 
            IDeviceLog * This,
            /* [retval][out] */ DATE *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Node )( 
            IDeviceLog * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventID )( 
            IDeviceLog * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IDeviceLogVtbl;

    interface IDeviceLog
    {
        CONST_VTBL struct IDeviceLogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDeviceLog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDeviceLog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDeviceLog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDeviceLog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDeviceLog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDeviceLog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDeviceLog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDeviceLog_get_LogID(This,pVal)	\
    ( (This)->lpVtbl -> get_LogID(This,pVal) ) 

#define IDeviceLog_get_AreaID(This,pVal)	\
    ( (This)->lpVtbl -> get_AreaID(This,pVal) ) 

#define IDeviceLog_get_CardID(This,pVal)	\
    ( (This)->lpVtbl -> get_CardID(This,pVal) ) 

#define IDeviceLog_get_UserID(This,pVal)	\
    ( (This)->lpVtbl -> get_UserID(This,pVal) ) 

#define IDeviceLog_get_DateTime(This,pVal)	\
    ( (This)->lpVtbl -> get_DateTime(This,pVal) ) 

#define IDeviceLog_get_Node(This,pVal)	\
    ( (This)->lpVtbl -> get_Node(This,pVal) ) 

#define IDeviceLog_get_EventID(This,pVal)	\
    ( (This)->lpVtbl -> get_EventID(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDeviceLog_INTERFACE_DEFINED__ */


#ifndef __IDeviceLogs_INTERFACE_DEFINED__
#define __IDeviceLogs_INTERFACE_DEFINED__

/* interface IDeviceLogs */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDeviceLogs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("05874CFC-144F-4812-B7AE-12047FEA2699")
    IDeviceLogs : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ LONG Index,
            /* [retval][out] */ IDeviceLog **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( 
            /* [defaultvalue][in] */ LONG ID,
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDeviceLogsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDeviceLogs * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDeviceLogs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDeviceLogs * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDeviceLogs * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDeviceLogs * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDeviceLogs * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDeviceLogs * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IDeviceLogs * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IDeviceLogs * This,
            /* [in] */ LONG Index,
            /* [retval][out] */ IDeviceLog **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            IDeviceLogs * This,
            /* [defaultvalue][in] */ LONG ID,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IDeviceLogs * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IDeviceLogsVtbl;

    interface IDeviceLogs
    {
        CONST_VTBL struct IDeviceLogsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDeviceLogs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDeviceLogs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDeviceLogs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDeviceLogs_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDeviceLogs_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDeviceLogs_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDeviceLogs_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDeviceLogs_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define IDeviceLogs_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IDeviceLogs_Download(This,ID,pRetVal)	\
    ( (This)->lpVtbl -> Download(This,ID,pRetVal) ) 

#define IDeviceLogs_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDeviceLogs_INTERFACE_DEFINED__ */


#ifndef __IAMJ03_INTERFACE_DEFINED__
#define __IAMJ03_INTERFACE_DEFINED__

/* interface IAMJ03 */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAMJ03;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("77342A19-4433-489D-854B-ACBAC34DF47A")
    IAMJ03 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DoorGroups( 
            /* [retval][out] */ IDoorGroups **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Attrib( 
            /* [in] */ LONG Node,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Attrib( 
            /* [in] */ LONG Node,
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [in] */ LONG Node,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Status( 
            /* [in] */ LONG Node,
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DoorStates( 
            /* [retval][out] */ IDoorStates **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Users( 
            /* [retval][out] */ IUsers **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRTCTime( 
            /* [out][in] */ DATE *pValue,
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRTCTime( 
            /* [in] */ DATE Value,
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MachineAddr( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MachineAddr( 
            /* [in] */ LONG pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevVersion( 
            /* [out][in] */ LONG *value,
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Logs( 
            /* [retval][out] */ IDeviceLogs **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAMJ03Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAMJ03 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAMJ03 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAMJ03 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAMJ03 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAMJ03 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAMJ03 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAMJ03 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DoorGroups )( 
            IAMJ03 * This,
            /* [retval][out] */ IDoorGroups **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attrib )( 
            IAMJ03 * This,
            /* [in] */ LONG Node,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Attrib )( 
            IAMJ03 * This,
            /* [in] */ LONG Node,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IAMJ03 * This,
            /* [in] */ LONG Node,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Status )( 
            IAMJ03 * This,
            /* [in] */ LONG Node,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DoorStates )( 
            IAMJ03 * This,
            /* [retval][out] */ IDoorStates **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Users )( 
            IAMJ03 * This,
            /* [retval][out] */ IUsers **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRTCTime )( 
            IAMJ03 * This,
            /* [out][in] */ DATE *pValue,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRTCTime )( 
            IAMJ03 * This,
            /* [in] */ DATE Value,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MachineAddr )( 
            IAMJ03 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MachineAddr )( 
            IAMJ03 * This,
            /* [in] */ LONG pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevVersion )( 
            IAMJ03 * This,
            /* [out][in] */ LONG *value,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Logs )( 
            IAMJ03 * This,
            /* [retval][out] */ IDeviceLogs **pVal);
        
        END_INTERFACE
    } IAMJ03Vtbl;

    interface IAMJ03
    {
        CONST_VTBL struct IAMJ03Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAMJ03_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAMJ03_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAMJ03_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAMJ03_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAMJ03_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAMJ03_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAMJ03_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAMJ03_get_DoorGroups(This,pVal)	\
    ( (This)->lpVtbl -> get_DoorGroups(This,pVal) ) 

#define IAMJ03_get_Attrib(This,Node,pVal)	\
    ( (This)->lpVtbl -> get_Attrib(This,Node,pVal) ) 

#define IAMJ03_put_Attrib(This,Node,newVal)	\
    ( (This)->lpVtbl -> put_Attrib(This,Node,newVal) ) 

#define IAMJ03_get_Status(This,Node,pVal)	\
    ( (This)->lpVtbl -> get_Status(This,Node,pVal) ) 

#define IAMJ03_put_Status(This,Node,newVal)	\
    ( (This)->lpVtbl -> put_Status(This,Node,newVal) ) 

#define IAMJ03_get_DoorStates(This,pVal)	\
    ( (This)->lpVtbl -> get_DoorStates(This,pVal) ) 

#define IAMJ03_get_Users(This,pVal)	\
    ( (This)->lpVtbl -> get_Users(This,pVal) ) 

#define IAMJ03_GetRTCTime(This,pValue,pRetVal)	\
    ( (This)->lpVtbl -> GetRTCTime(This,pValue,pRetVal) ) 

#define IAMJ03_SetRTCTime(This,Value,pRetVal)	\
    ( (This)->lpVtbl -> SetRTCTime(This,Value,pRetVal) ) 

#define IAMJ03_get_MachineAddr(This,pVal)	\
    ( (This)->lpVtbl -> get_MachineAddr(This,pVal) ) 

#define IAMJ03_put_MachineAddr(This,pVal)	\
    ( (This)->lpVtbl -> put_MachineAddr(This,pVal) ) 

#define IAMJ03_GetDevVersion(This,value,pRetVal)	\
    ( (This)->lpVtbl -> GetDevVersion(This,value,pRetVal) ) 

#define IAMJ03_get_Logs(This,pVal)	\
    ( (This)->lpVtbl -> get_Logs(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAMJ03_INTERFACE_DEFINED__ */


#ifndef __IBusPortData_INTERFACE_DEFINED__
#define __IBusPortData_INTERFACE_DEFINED__

/* interface IBusPortData */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IBusPortData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("014BA2C5-63D4-469F-8AFD-ECDEF42B8B63")
    IBusPortData : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Buffer( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBuffer( 
            /* [in] */ LONG *Buf,
            /* [in] */ LONG nSize) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Param( 
            /* [in] */ LONG id,
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Param( 
            /* [in] */ LONG id,
            /* [in] */ LONG newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBusPortDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBusPortData * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBusPortData * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBusPortData * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBusPortData * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBusPortData * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBusPortData * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBusPortData * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Buffer )( 
            IBusPortData * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IBusPortData * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBuffer )( 
            IBusPortData * This,
            /* [in] */ LONG *Buf,
            /* [in] */ LONG nSize);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Param )( 
            IBusPortData * This,
            /* [in] */ LONG id,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Param )( 
            IBusPortData * This,
            /* [in] */ LONG id,
            /* [in] */ LONG newVal);
        
        END_INTERFACE
    } IBusPortDataVtbl;

    interface IBusPortData
    {
        CONST_VTBL struct IBusPortDataVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBusPortData_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBusPortData_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBusPortData_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBusPortData_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBusPortData_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBusPortData_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBusPortData_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBusPortData_get_Buffer(This,pVal)	\
    ( (This)->lpVtbl -> get_Buffer(This,pVal) ) 

#define IBusPortData_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IBusPortData_SetBuffer(This,Buf,nSize)	\
    ( (This)->lpVtbl -> SetBuffer(This,Buf,nSize) ) 

#define IBusPortData_get_Param(This,id,pVal)	\
    ( (This)->lpVtbl -> get_Param(This,id,pVal) ) 

#define IBusPortData_put_Param(This,id,newVal)	\
    ( (This)->lpVtbl -> put_Param(This,id,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBusPortData_INTERFACE_DEFINED__ */



#ifndef __AnvizOcxLib_LIBRARY_DEFINED__
#define __AnvizOcxLib_LIBRARY_DEFINED__

/* library AnvizOcxLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AnvizOcxLib;

#ifndef ___IAnvizEvents_DISPINTERFACE_DEFINED__
#define ___IAnvizEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IAnvizEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IAnvizEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D762747D-6811-4C08-B640-BB5FBCCC2E08")
    _IAnvizEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IAnvizEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IAnvizEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IAnvizEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IAnvizEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IAnvizEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IAnvizEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IAnvizEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IAnvizEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IAnvizEventsVtbl;

    interface _IAnvizEvents
    {
        CONST_VTBL struct _IAnvizEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IAnvizEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IAnvizEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IAnvizEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IAnvizEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IAnvizEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IAnvizEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IAnvizEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IAnvizEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Anviz;

#ifdef __cplusplus

class DECLSPEC_UUID("68361EBD-63AA-48A4-87FB-86C5585181F9")
Anviz;
#endif

EXTERN_C const CLSID CLSID_AnvizItems;

#ifdef __cplusplus

class DECLSPEC_UUID("2AEDEFE7-A906-4CF2-A8C8-0628E09CD3F7")
AnvizItems;
#endif

EXTERN_C const CLSID CLSID_ComBus;

#ifdef __cplusplus

class DECLSPEC_UUID("216CF6DA-4F04-40E9-B4D2-C7091EAB4C1B")
ComBus;
#endif

EXTERN_C const CLSID CLSID_AMJ03;

#ifdef __cplusplus

class DECLSPEC_UUID("8A899939-DE76-4D15-9BCB-F89B6BC98AA2")
AMJ03;
#endif

EXTERN_C const CLSID CLSID_DoorGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("E0E81ECE-8D5D-4D20-A6D1-449EE5CE8D48")
DoorGroup;
#endif

EXTERN_C const CLSID CLSID_TimeList;

#ifdef __cplusplus

class DECLSPEC_UUID("316F4420-DBD2-40E2-9FB8-9FB95D04EC3C")
TimeList;
#endif

EXTERN_C const CLSID CLSID_TimeLists;

#ifdef __cplusplus

class DECLSPEC_UUID("C3A3F6EF-1DF6-4715-A414-62107C72BF6D")
TimeLists;
#endif

EXTERN_C const CLSID CLSID_DoorGroups;

#ifdef __cplusplus

class DECLSPEC_UUID("DD841611-6898-4947-8ACF-215B16440422")
DoorGroups;
#endif

EXTERN_C const CLSID CLSID_DoorStates;

#ifdef __cplusplus

class DECLSPEC_UUID("647138DF-9C97-45FF-9394-A10C42FA1F37")
DoorStates;
#endif

EXTERN_C const CLSID CLSID_DoorState;

#ifdef __cplusplus

class DECLSPEC_UUID("99DC8D84-86FD-43DC-A601-13CFEAA0DC1A")
DoorState;
#endif

EXTERN_C const CLSID CLSID_User;

#ifdef __cplusplus

class DECLSPEC_UUID("D2FBB274-0F67-42BC-A60D-712CD768A5A1")
User;
#endif

EXTERN_C const CLSID CLSID_Users;

#ifdef __cplusplus

class DECLSPEC_UUID("4449BC37-8370-4103-BC19-A051E59FDC1C")
Users;
#endif

EXTERN_C const CLSID CLSID_DeviceLog;

#ifdef __cplusplus

class DECLSPEC_UUID("198594D8-4EDA-4905-8829-32E034A24C29")
DeviceLog;
#endif

EXTERN_C const CLSID CLSID_DeviceLogs;

#ifdef __cplusplus

class DECLSPEC_UUID("D4239CB7-86BF-47B8-8E20-38D43A233F23")
DeviceLogs;
#endif

EXTERN_C const CLSID CLSID_BusPortData;

#ifdef __cplusplus

class DECLSPEC_UUID("903CD9C7-2FE2-4F2C-8768-5786702B9F55")
BusPortData;
#endif
#endif /* __AnvizOcxLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


