
//1.����Ƿ�װɱ�����
//2.�������װ��ɱ�������Ƿ����
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
using namespace std;
#define  KEY_SET "SOFTWARE\\TrendMicro\\PC-cillinNTCorp\\CurrentVersion\\Misc."
#define  KEY_NAME	"PatternDate"
#define MAX_VALUE_NAME 16383
void Trend_Check()
{
	HKEY hkey;
	printf("\t�Ƿ�װ���Ʒ����ͻ��ˣ�");
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KEY_SET,0,KEY_READ,&hkey)==ERROR_SUCCESS)          //�����Ʋ����������־���ڵĴ洢��ֵ
	{
		// printf("�򿪼�ֵ�ɹ�\n");
		

		TCHAR shareValue[MAX_VALUE_NAME];
		DWORD shareType;
		DWORD shareSize;
		shareType=REG_SZ;
		shareSize=strlen(shareValue);	
	
		LONG ret0=RegQueryValueEx(hkey,KEY_NAME,NULL,&shareType, (LPBYTE)shareValue, &shareSize);  
		
		if(ret0==ERROR_SUCCESS)
		{
		
			printf("��\t\n\n");
			printf("\t\t���Ʋ������������Ϊ��");
			printf("%s\n\n",shareValue);
			

		}
		else
		{	printf("\t��ѯʧ��\n");}


	}
	//��ע���ʧ��ʱ����δ��װ
	else
	{
		printf("��\n\n");
	
	}
	RegCloseKey(hkey);
}






