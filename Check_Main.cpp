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
	printf("*       ��Ϣ��ȫ�Բ�С����V1.0     *\n");
	printf("*                                  *\n");
	printf("* * * * * * * * * * * * *  * * * * *\n");
	printf("\n");
	printf("//�ڲ�ʹ�ã������⴫               \n");
	printf("//��ȫ���˲� All Rights Reserved.  \n");

	cout<<endl;

cout<<"\t�������Ϣ��"<<endl<<endl;

	get_ComputerInfo();


cout<<"1��������氲ȫ����Ƿ�װ��\n\n";

	File_Check();

cout<<"2������ĵ���������Ƿ�װ��\n\n";
	
	CDg_Check();

cout<<"3�����ɱ�����\n\n";

	Trend_Check();									//����Ƿ�װ���ƣ���鲡����

	Software_Check();                               //����Ƿ�����ɱ�����
	
	cout<<endl;

cout<<"4������Ƿ���빫˾�򻷾�\n\n";
	
	Domain_Check();									//�����


cout<<"5��Guest�˺��Ƿ����\n"<<endl;				//����Ƿ����guest�˺�

	Change_SAM_Access();

cout<<"6�������������\n";
	
	Check_Share_Authority_Key();                    //�����������ĺ���

	cout<<endl;
	
	system("pause");
}

