#include "StdAfx.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>


using namespace std;


BOOL GetProcessList(){
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriotiryClass;

	// Take a snapshot of all processes in the systems
	hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0);
	if( hProcessSnap == INVALID_HANDLE_VALUE){
		//printError( TEXT("CreateToolhelp32Snapshot (of processes)"));
		return( FALSE );
	}

	pe32.dwSize = sizeof(PROCESSENTRY32);

	if(!Process32First(hProcessSnap, &pe32)){
		//printError( TEXT("Process32First"));
		CloseHandle(hProcessSnap);
		return( FALSE);
	}

	cout << "True" << endl;

	do{
		printf("PROCESS NAME: %s\n", pe32.szExeFile);
		printf("Process Size: %lu\n", pe32.dwSize);
	}while( Process32Next(hProcessSnap, &pe32));

	return(TRUE);

}


BOOL CALLBACK EnumWindowsProc(HWND hWnd, long lParam) {
    char buff[255];

    if (IsWindowVisible(hWnd)) {
        GetWindowText(hWnd, (LPSTR) buff, 254);
        SetWindowPos( hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW );
        printf("%s\n", buff);
    }
    return TRUE;
}


int main(int argc, CHAR* argv[]){
	//DWORD procIDs[6];
	//DWORD maxCount = 6;
	//BOOL result = GetProcessList();
	EnumWindows(EnumWindowsProc, 0);
    return 0;
	//cout << result << endl;
	//cout << procIDs[0] << endl;
	//cout << procIDs[1] << endl;
}