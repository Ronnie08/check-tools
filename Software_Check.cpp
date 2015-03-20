//检查软件安装情况
//检查是否运行360杀毒、趋势、文档加密
#include <windows.h>
#include <String.h>
#include <tlhelp32.h>//声明快照函数头文件
#include <iostream>
using namespace std; 
int Software_Check()
{

        HANDLE hProcessSnap=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
        if(hProcessSnap==INVALID_HANDLE_VALUE){
           printf("CreateToolhelp32Snapshot调用失败!\n");
           return -1;
        }

        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);
//遍历进程快照。轮流显示每个进程的信息
        BOOL bMore=Process32First(hProcessSnap,&pe32);
       

			int i=0,k=0,j=0;
			char a[]="360sd.exe";
			char b[]="NTRtScan.exe";
			char c[]="TCCMgtC.exe";
			
		

	printf("\t是否运行防毒软件：");	
	while(bMore)
		{
			i++;
			bMore=Process32Next(hProcessSnap,&pe32);

			  if(strcmp(pe32.szExeFile,a)==0)
			
			  {
				  printf("\t已运行360杀毒软件\n\n");
				  break;
				}

			  else if(strcmp(pe32.szExeFile,b)==0)
			  
			 { 
				printf("\t已运行趋势杀毒软件\n\n");
				break;
				
			  }


			  else if(bMore==0)
				  printf("未运行趋势或360杀毒\n\n");

	
	
		}


//清除snapshot对象
	CloseHandle(hProcessSnap);
	return 0;
}
