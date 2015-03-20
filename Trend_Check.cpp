
//1.检测是否安装杀毒软件
//2.检测所安装的杀软病毒库是否过期
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
	printf("\t是否安装趋势防毒客户端：");
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,KEY_SET,0,KEY_READ,&hkey)==ERROR_SUCCESS)          //打开趋势病毒码更新日志所在的存储键值
	{
		// printf("打开键值成功\n");
		

		TCHAR shareValue[MAX_VALUE_NAME];
		DWORD shareType;
		DWORD shareSize;
		shareType=REG_SZ;
		shareSize=strlen(shareValue);	
	
		LONG ret0=RegQueryValueEx(hkey,KEY_NAME,NULL,&shareType, (LPBYTE)shareValue, &shareSize);  
		
		if(ret0==ERROR_SUCCESS)
		{
		
			printf("是\t\n\n");
			printf("\t\t趋势病毒库更新日期为：");
			printf("%s\n\n",shareValue);
			

		}
		else
		{	printf("\t查询失败\n");}


	}
	//打开注册表失败时代表未安装
	else
	{
		printf("否\n\n");
	
	}
	RegCloseKey(hkey);
}






