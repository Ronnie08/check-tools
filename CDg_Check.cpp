//1.����Ƿ�װ�ĵ�����
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
using namespace std;
#define  KEY_SET "SOFTWARE\\����й¶����ϵͳ"
#define  KEY_NAME	"����й¶����ϵͳ-�ͻ���"
#define MAX_VALUE_NAME 16383
void CDg_Check()
{
	HKEY hkey;
	printf("\t�Ƿ�װ����й©����ϵͳ(�ĵ�����)��");
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KEY_SET,0,KEY_READ,&hkey)==ERROR_SUCCESS)          //���ĵ��������ڼ�ֵ
	{
		 printf("��\n\n");
		
	/*
		TCHAR shareValue[MAX_VALUE_NAME];
		DWORD shareType;
		DWORD shareSize;
		shareType=REG_SZ;
		shareSize=strlen(shareValue);	
	
		LONG ret0=RegQueryValueEx(hkey,KEY_NAME,NULL,&shareType, (LPBYTE)shareValue, &shareSize);  
		
		if(ret0==ERROR_SUCCESS)
		{
		
			printf("��\t\n\n");
		

		}
		else
		{	printf("\t��ѯʧ��\n");}

	*/
	}
	//��ע���ʧ��ʱ����δ��װ
	else
	{
		printf("��\n\n");
	
	}
	RegCloseKey(hkey);
}






