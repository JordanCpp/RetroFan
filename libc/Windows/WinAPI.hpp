/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#ifndef Windows_WinAPI_hpp
#define Windows_WinAPI_hpp
/*********************************************************************************************                                           
                                            Macros
*********************************************************************************************/
#define WINAPI          __stdcall
#define DECLSPEC_IMPORT __declspec(dllimport)
#define WINBASEAPI      DECLSPEC_IMPORT
/*********************************************************************************************
                                            Types
*********************************************************************************************/
typedef void*          LPVOID;
typedef void*          HANDLE;
typedef unsigned long  DWORD;
typedef DWORD*         LPDWORD;
typedef unsigned long  ULONG_PTR;
typedef ULONG_PTR      SIZE_T;
typedef ULONG_PTR      DWORD_PTR;
typedef int            BOOL;
typedef unsigned int   UINT;
typedef void*          PVOID;
typedef char           CHAR;
typedef const CHAR* LPCSTR, * PCSTR;

typedef struct _SECURITY_ATTRIBUTES
{
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, * PSECURITY_ATTRIBUTES, * LPSECURITY_ATTRIBUTES;

typedef struct _OVERLAPPED 
{
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        } DUMMYSTRUCTNAME;
        PVOID Pointer;
    } DUMMYUNIONNAME;

    HANDLE  hEvent;
} OVERLAPPED, * LPOVERLAPPED;
/*********************************************************************************************
                                          Constants
*********************************************************************************************/
const DWORD STD_INPUT_HANDLE  = ((DWORD)-10);
const DWORD STD_OUTPUT_HANDLE = ((DWORD)-11);
const DWORD STD_ERROR_HANDLE  = ((DWORD)-12);

const DWORD  CREATE_NEW        = 1;
const DWORD  CREATE_ALWAYS     = 2;
const DWORD  OPEN_EXISTING     = 3;
const DWORD  OPEN_ALWAYS       = 4;
const DWORD  TRUNCATE_EXISTING = 5;

const DWORD GENERIC_READ    = (0x80000000L);
const DWORD GENERIC_WRITE   = (0x40000000L);
const DWORD GENERIC_EXECUTE = (0x20000000L);
const DWORD GENERIC_ALL     = (0x10000000L);

const DWORD FILE_ATTRIBUTE_NORMAL = 0x00000080;
/*********************************************************************************************
                                        Common functions
*********************************************************************************************/
extern "C" WINBASEAPI void   WINAPI ExitProcess(UINT uExitCode);
extern "C" WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
/*********************************************************************************************
                                        Heap functions
*********************************************************************************************/
extern "C" WINBASEAPI HANDLE WINAPI HeapCreate(DWORD flOptions, SIZE_T dwInitialSize, SIZE_T dwMaximumSize);
extern "C" WINBASEAPI BOOL   WINAPI HeapDestroy(HANDLE hHeap);
extern "C" WINBASEAPI LPVOID WINAPI HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
extern "C" WINBASEAPI BOOL   WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
/*********************************************************************************************
                                        Console functions
*********************************************************************************************/
extern "C" WINBASEAPI BOOL   WINAPI WriteConsoleA(HANDLE hConsoleOutput, const void* lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved);
/*********************************************************************************************
                                        File functions
*********************************************************************************************/
extern "C" WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
extern "C" WINBASEAPI BOOL   WINAPI CloseHandle(HANDLE hObject);
extern "C" WINBASEAPI BOOL   WINAPI ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);

#endif
