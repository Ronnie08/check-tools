#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "wsock32.lib")
void get_ComputerInfo()
{
	 char buf[256]=""; 
	 struct hostent *ph = 0;
	 WSADATA w; WSAStartup(0x0101, &w); //��һ�б�����ʹ���κ�SOCKET����ǰд��

	if(gethostname(buf, 256))
	{ 
		fprintf(stderr, "gethostname() fault %d\n", GetLastError());
  
	}
	else
	 {
		printf("\t�������: %s\n", buf);
	 }
	 ph = gethostbyname(buf);
	 printf("\t����IP:%s\n\n",  inet_ntoa(*((struct in_addr *)ph->h_addr_list[0])));
	 WSACleanup();
 
}