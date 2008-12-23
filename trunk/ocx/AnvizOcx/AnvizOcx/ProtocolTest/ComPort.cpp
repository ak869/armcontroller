// ComPort.cpp: implementation of the CComPort class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ComPort.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CComPort::CComPort()
{
	m_hCom = INVALID_HANDLE_VALUE;
	m_ErrCode = 0;
}

CComPort::~CComPort()
{
	CloseCom();
}
BOOL CComPort::OpenPort(void)
{
	return OpenCom(_T("COM1"));
}
VOID CComPort::ClosePort(void)
{
	CloseCom();
}

BOOL CComPort::OpenCom(TCHAR * COMName)
{
   DCB dcb;
   HANDLE hCom;
   BOOL fSuccess;
   COMMTIMEOUTS CommTimeOuts;
   hCom = ::CreateFile( COMName,
                    GENERIC_READ | GENERIC_WRITE,
                    0,    // must be opened with exclusive-access
                    NULL, // no security attributes
                    OPEN_EXISTING, // must use OPEN_EXISTING
                    0,    // not overlapped I/O
                    NULL  // hTemplate must be NULL for comm devices
                    );

   if (hCom == INVALID_HANDLE_VALUE) 
   {
       // Handle the error.
 //      printf ("CreateFile failed with error %d.\n", GetLastError());
       return FALSE;
   }

   // Build on the current configuration, and skip setting the size
   // of the input and output buffers with SetupComm.

   fSuccess = GetCommState(hCom, &dcb);

   if (!fSuccess) 
   {
      // Handle the error.
//      printf ("GetCommState failed with error %d.\n", GetLastError());
	   CloseHandle(hCom);
      return FALSE;
   }

   // Fill in DCB: 57,600 bps, 8 data bits, no parity, and 1 stop bit.
   fSuccess = GetCommState(hCom, &dcb);

   dcb.BaudRate = CBR_9600;     // set the baud rate
   dcb.ByteSize = 8;             // data size, xmit, and rcv
   dcb.Parity = NOPARITY;        // no parity bit
   dcb.StopBits = ONESTOPBIT;    // one stop bit
   dcb.fDtrControl = DTR_CONTROL_DISABLE;
   dcb.fRtsControl = RTS_CONTROL_DISABLE;
   dcb.fInX = dcb.fOutX = 0 ;
   dcb.fBinary = TRUE ;

   fSuccess = SetCommState(hCom, &dcb);

   if (!fSuccess) 
   {
      // Handle the error.
 //     printf ("SetCommState failed with error %d.\n", GetLastError());
	  CloseHandle(hCom);
   }
	SetupComm( hCom, 4096, 4096 );

	PurgeComm( hCom, PURGE_TXABORT | PURGE_RXABORT |
                                      PURGE_TXCLEAR | PURGE_RXCLEAR ) ;

    CommTimeOuts.ReadIntervalTimeout = 10;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0 ;
    CommTimeOuts.ReadTotalTimeoutConstant = 4000;
      // CBR_9600 is approximately 1byte/ms. For our purposes, allow
      // double the expected time per character for a fudge factor.
    CommTimeOuts.WriteTotalTimeoutMultiplier = 1;
    CommTimeOuts.WriteTotalTimeoutConstant = 0 ;

	SetCommTimeouts( hCom, &CommTimeOuts ) ;

	read_o.hEvent = CreateEvent(
        NULL,   // default security attributes 
        FALSE,  // auto reset event 
        FALSE,  // not signaled 
        NULL    // no name
		);

	write_o.hEvent = CreateEvent(
        NULL,   // default security attributes 
        FALSE,  // auto reset event 
        FALSE,  // not signaled 
        NULL    // no name
		);

	read_o.Internal = 0;
    read_o.InternalHigh = 0;
    read_o.Offset = 0;
    read_o.OffsetHigh = 0;

	write_o.Internal = 0;
    write_o.InternalHigh = 0;
    write_o.Offset = 0;
    write_o.OffsetHigh = 0;

	m_hCom = hCom;
	return TRUE;
}

void CComPort::CloseCom()
{
	if( m_hCom != INVALID_HANDLE_VALUE)
		CloseHandle(m_hCom);
	m_hCom = INVALID_HANDLE_VALUE;
}

BOOL CComPort::ReadData(BYTE *Buffer, DWORD *nSize)
{
	DWORD dwLength,dwErrorFlags;
	BOOL fReadStat;

	COMSTAT ComStat;

	dwLength = *nSize;
	if( m_hCom == INVALID_HANDLE_VALUE ) return FALSE;

	ClearCommError( m_hCom, &dwErrorFlags, &ComStat );

	fReadStat = ReadFile(m_hCom, Buffer, dwLength, nSize, &read_o);
	if( !fReadStat )
	{
		m_ErrCode = GetLastError();
		ClearCommError( m_hCom, &dwErrorFlags, &ComStat );
	}
	return TRUE;
}

BOOL CComPort::WriteData(BYTE *Buffer, DWORD nSize)
{
	DWORD dwLength;
	BOOL fWriteStat;

	dwLength = nSize;
	if( m_hCom == INVALID_HANDLE_VALUE ) return FALSE;
	fWriteStat = WriteFile(m_hCom, Buffer, dwLength, &nSize, &write_o);
	if( !fWriteStat )
	{
		m_ErrCode = GetLastError();
	}
	return TRUE;
}

DWORD CComPort::GetErrCode()
{
	return m_ErrCode;
}

void CComPort::ClearData(BYTE *Buffer, DWORD *nSize)
{
	DWORD dwLength,dwErrorFlags;
	BOOL fReadStat;
	COMMTIMEOUTS CommTimeOuts;
	COMSTAT ComStat;

	if( m_hCom == INVALID_HANDLE_VALUE ) return;

	ClearCommError( m_hCom, &dwErrorFlags, &ComStat );
	GetCommTimeouts( m_hCom, &CommTimeOuts ) ;

    CommTimeOuts.ReadTotalTimeoutConstant = 10;
	SetCommTimeouts( m_hCom, &CommTimeOuts ) ;

	dwLength = *nSize;
	
	fReadStat = ReadFile(m_hCom, Buffer, dwLength, nSize, &read_o);
	if( !fReadStat )
	{
		m_ErrCode = GetLastError();
		ClearCommError( m_hCom, &dwErrorFlags, &ComStat );
	}

    CommTimeOuts.ReadTotalTimeoutConstant = 4000;
	SetCommTimeouts( m_hCom, &CommTimeOuts ) ;
	return;
}

VOID CComPort::SetTimeOut(DWORD RecvTimeOut)
{
	COMMTIMEOUTS CommTimeOuts;
	CommTimeOuts.ReadIntervalTimeout = 10;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0 ;
    CommTimeOuts.ReadTotalTimeoutConstant = RecvTimeOut;
      // CBR_9600 is approximately 1byte/ms. For our purposes, allow
      // double the expected time per character for a fudge factor.
    CommTimeOuts.WriteTotalTimeoutMultiplier = 1;
    CommTimeOuts.WriteTotalTimeoutConstant = 0 ;

	SetCommTimeouts( m_hCom, &CommTimeOuts ) ;
}
