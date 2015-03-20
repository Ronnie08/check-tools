
//1.检测是否加入域
//2.加入域的名称
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
	
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KEY_SET,0,KEY_READ,&hkey)==ERROR_SUCCESS)          //打开域名存储位置
	{
		// printf("打开键值成功\n");
		

		TCHAR shareValue[MAX_VALUE_NAME];
		DWORD shareType;
		DWORD shareSize;
		shareType=REG_SZ;
		shareSize=strlen(shareValue);	


//读取域信息
		
		LONG ret0=RegQueryValueEx(hkey,KEY_NAME,NULL,&shareType, (LPBYTE)shareValue, &shareSize);  
		if(ret0==ERROR_SUCCESS)
		{	

			if(shareSize==1)                   //Domain的REG_SZ值为空时，代表未加入任何域
			{	printf("\t未加入任何域\n\n");      //此时shareSize值为1
				
			}
			else
			{
				printf("\t已加入公司域：");
				printf("%s\n\n",shareValue);
			}

		}
		else
		{	printf("\t查询键值失败\n\n");
			
		}


	RegCloseKey(hkey);

	}
}