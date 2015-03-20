//1.检测是否安装文档加密
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
using namespace std;
#define  KEY_SET "SOFTWARE\\数据泄露防护系统"
#define  KEY_NAME	"数据泄露防护系统-客户端"
#define MAX_VALUE_NAME 16383
void CDg_Check()
{
	HKEY hkey;
	printf("\t是否安装数据泄漏防护系统(文档加密)：");
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KEY_SET,0,KEY_READ,&hkey)==ERROR_SUCCESS)          //打开文档加密所在键值
	{
		 printf("是\n\n");
		
	/*
		TCHAR shareValue[MAX_VALUE_NAME];
		DWORD shareType;
		DWORD shareSize;
		shareType=REG_SZ;
		shareSize=strlen(shareValue);	
	
		LONG ret0=RegQueryValueEx(hkey,KEY_NAME,NULL,&shareType, (LPBYTE)shareValue, &shareSize);  
		
		if(ret0==ERROR_SUCCESS)
		{
		
			printf("是\t\n\n");
		

		}
		else
		{	printf("\t查询失败\n");}

	*/
	}
	//打开注册表失败时代表未安装
	else
	{
		printf("否\n\n");
	
	}
	RegCloseKey(hkey);
}






