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
	}while( Process32Next(hProcessSnap, &pe32));

}


int main(int argc, CHAR* argv[]){
	//DWORD procIDs[6];
	//DWORD maxCount = 6;
	BOOL result = GetProcessList();
	//cout << result << endl;
	//cout << procIDs[0] << endl;
	//cout << procIDs[1] << endl;
}