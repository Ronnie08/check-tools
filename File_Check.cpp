#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
void File_Check()
{

//检查桌面安全安装情况
	
	FILE *fp;
	
	char   szBuf[255];			//获得系统路径
	GetSystemDirectory(szBuf,255);
	


	char *filename="TCCSetup.exe";   //默认为系统路径下TCCSetup.exe
	char a[2]="\\";
	strcat(szBuf,a);
	strcat(szBuf,filename);

	
//  "c:\\windows\\system32\\TCCSetup.exe";

	fp=fopen(szBuf,"r");
	printf("\t是否安装桌面安全软件：");
	if(fp==NULL)
	{
		printf("未安装\n\n");
	
	}
	else {printf("已安装\n\n");}



}