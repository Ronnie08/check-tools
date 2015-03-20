#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
using namespace std;
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
#define KEY_SET "SAM\\SAM\\Domains\\Account\\Users\\000001F5"
void Guset_Check() 
{ 
	HKEY hKey;
	if( RegOpenKeyEx( HKEY_LOCAL_MACHINE,KEY_SET,0,KEY_READ,&hKey) == ERROR_SUCCESS
      )
	{

    TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
    DWORD    cbName;                   // size of name string 
    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
    DWORD    cchClassName = MAX_PATH;  // size of class string 
    DWORD    cSubKeys=0;               // number of subkeys 
    DWORD    cbMaxSubKey;              // longest subkey size 
    DWORD    cchMaxClass;              // longest class string 
    DWORD    cValues;              // number of values for key 
    DWORD    cchMaxValue;          // longest value name 
    DWORD    cbMaxValueData;       // longest value data 
    DWORD    cbSecurityDescriptor; // size of security descriptor 
    FILETIME ftLastWriteTime;      // last write time 
 
    DWORD i, retCode; 
 
    TCHAR  achValue[MAX_VALUE_NAME]; 
    DWORD cchValue = MAX_VALUE_NAME; 
	TCHAR shareValue[MAX_VALUE_NAME];
	DWORD shareType;
	DWORD shareSize;
	shareType=REG_BINARY;	
	shareSize=strlen(shareValue);	

 
    // Get the class name and the value count. 
    retCode = RegQueryInfoKey(
        hKey,                    // key handle 
        achClass,                // buffer for class name 
        &cchClassName,           // size of class string 
        NULL,                    // reserved 
        &cSubKeys,               // number of subkeys 
        &cbMaxSubKey,            // longest subkey size 
        &cchMaxClass,            // longest class string 
        &cValues,                // number of values for this key 
        &cchMaxValue,            // longest value name 
        &cbMaxValueData,         // longest value data 
        &cbSecurityDescriptor,   // security descriptor 
        &ftLastWriteTime);       // last write time 
 
    // Enumerate the subkeys, until RegEnumKeyEx fails.
    
			shareValue[0] = '\0'; 
		
			LONG ret0=RegQueryValueEx(hKey,"F",NULL,&shareType, (LPBYTE)shareValue, &shareSize);  //查询guest中F的键值
	
		
		if(ret0==ERROR_SUCCESS)
				{
					if(shareValue[56]==20)				//第56位字符为15时，为未禁用
					
						{	printf("\t未禁用\n");
							
						}
					else 
							printf("\t已禁用\n");
					

				}
 
			else 
				{
					printf("WRONG");
				}

			cout<<endl;
//
 

	}
	else
	{
	printf("打开注册表失败");
	exit(-1);
	}

	RegCloseKey(hKey);
}


