
//1.����Ƿ������
//2.�����������
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
using namespace std;
#define  KEY_SET "SYSTEM\\ControlSet001\\Services\\Tcpip\\Parameters"
#define  KEY_NAME	"Domain"
#define MAX_VALUE_NAME 16383
void Domain_Check()
{
	HKEY hkey;
	
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KEY_SET,0,KEY_READ,&hkey)==ERROR_SUCCESS)          //�������洢λ��
	{
		// printf("�򿪼�ֵ�ɹ�\n");
		

		TCHAR shareValue[MAX_VALUE_NAME];
		DWORD shareType;
		DWORD shareSize;
		shareType=REG_SZ;
		shareSize=strlen(shareValue);	


//��ȡ����Ϣ
		
		LONG ret0=RegQueryValueEx(hkey,KEY_NAME,NULL,&shareType, (LPBYTE)shareValue, &shareSize);  
		if(ret0==ERROR_SUCCESS)
		{	

			if(shareSize==1)                   //Domain��REG_SZֵΪ��ʱ������δ�����κ���
			{	printf("\tδ�����κ���\n\n");      //��ʱshareSizeֵΪ1
				
			}
			else
			{
				printf("\t�Ѽ��빫˾��");
				printf("%s\n\n",shareValue);
			}

		}
		else
		{	printf("\t��ѯ��ֵʧ��\n\n");
			
		}


	RegCloseKey(hkey);

	}
}