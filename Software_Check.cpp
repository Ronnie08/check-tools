//��������װ���
//����Ƿ�����360ɱ�������ơ��ĵ�����
#include <windows.h>
#include <String.h>
#include <tlhelp32.h>//�������պ���ͷ�ļ�
#include <iostream>
using namespace std; 
int Software_Check()
{

        HANDLE hProcessSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
        if(hProcessSnap==INVALID_HANDLE_VALUE){
           printf("CreateToolhelp32Snapshot����ʧ��!\n");
           return -1;
        }

        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);
//�������̿��ա�������ʾÿ�����̵���Ϣ
        BOOL bMore=Process32First(hProcessSnap,&pe32);
       

			int i=0,k=0,j=0;
			char a[]="360sd.exe";
			char b[]="NTRtScan.exe";
			char c[]="TCCMgtC.exe";
			
		

	printf("\t�Ƿ����з��������");	
	while(bMore)
		{
			i++;
			bMore=Process32Next(hProcessSnap,&pe32);

			  if(strcmp(pe32.szExeFile,a)==0)
			
			  {
				  printf("\t������360ɱ�����\n\n");
				  break;
				}

			  else if(strcmp(pe32.szExeFile,b)==0)
			  
			 { 
				printf("\t����������ɱ�����\n\n");
				break;
				
			  }


			  else if(bMore==0)
				  printf("δ�������ƻ�360ɱ��\n\n");

	
	
		}


//���snapshot����
	CloseHandle(hProcessSnap);
	return 0;
}
