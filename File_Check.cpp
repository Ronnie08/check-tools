#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
void File_Check()
{

//������氲ȫ��װ���
	
	FILE *fp;
	
	char   szBuf[255];			//���ϵͳ·��
	GetSystemDirectory(szBuf,255);
	


	char *filename="TCCSetup.exe";   //Ĭ��Ϊϵͳ·����TCCSetup.exe
	char a[2]="\\";
	strcat(szBuf,a);
	strcat(szBuf,filename);

	
//  "c:\\windows\\system32\\TCCSetup.exe";

	fp=fopen(szBuf,"r");
	printf("\t�Ƿ�װ���氲ȫ�����");
	if(fp==NULL)
	{
		printf("δ��װ\n\n");
	
	}
	else {printf("�Ѱ�װ\n\n");}



}