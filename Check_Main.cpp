//*************************************************************
//Time:   2012-01-19
//Author:	YRH
//Function:	To Read all the share name,and to identify  the 
//				 share's access authority 
//*************************************************************
#include <windows.h>
#include <iostream>
#include <winsock.h>
#include <wsipx.h>
#include <wsnwlink.h>
#include <stdio.h>
#pragma comment(lib, "wsock32.lib")
using namespace std;
void Check_Share_Authority_Key();
void Trend_Check();
void Domain_Check();	
void get_ComputerInfo(void);
int Software_Check();
void Guset_Check();
void Change_SAM_Access();
void File_Check();
void CDg_Check();
void main(void)
{
	printf("* * * * * * * * * * * * *  * * * * *\n");
	printf("*                                  *\n");
	printf("*       信息安全自查小工具V1.0     *\n");
	printf("*                                  *\n");
	printf("* * * * * * * * * * * * *  * * * * *\n");
	printf("\n");
	printf("//内部使用，请勿外传               \n");
	printf("//安全稽核部 All Rights Reserved.  \n");

	cout<<endl;

cout<<"\t计算机信息："<<endl<<endl;

	get_ComputerInfo();


cout<<"1、检查桌面安全软件是否安装：\n\n";

	File_Check();

cout<<"2、检查文档加密软件是否安装：\n\n";
	
	CDg_Check();

cout<<"3、检查杀毒软件\n\n";

	Trend_Check();									//检查是否安装趋势，检查病毒库

	Software_Check();                               //检查是否运行杀毒软件
	
	cout<<endl;

cout<<"4、检查是否加入公司域环境\n\n";
	
	Domain_Check();									//检查域


cout<<"5、Guest账号是否禁用\n"<<endl;				//检查是否禁用guest账号

	Change_SAM_Access();

cout<<"6、检查匿名共享\n";
	
	Check_Share_Authority_Key();                    //检查匿名共享的函数

	cout<<endl;
	
	system("pause");
}

