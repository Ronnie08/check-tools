#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <tchar.h>
using namespace std;
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
#define KEY_SET "SYSTEM\\ControlSet001\\Services\\LanmanServer\\Shares\\Security"
void Check_Share_Authority_Key() 
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
    
/*列出子项   

  if (cSubKeys)
    {
        printf( "\nNumber of subkeys: %d\n", cSubKeys);

        for (i=0; i<cSubKeys; i++) 
        { 
            cbName = MAX_KEY_LENGTH;
            retCode = RegEnumKeyEx(hKey, i,
                     achKey, 
                     &cbName, 
                     NULL, 
                     NULL, 
                     NULL, 
                     &ftLastWriteTime); 
            if (retCode == ERROR_SUCCESS) 
            {
                _tprintf(TEXT("(%d) %s\n"), i+1, achKey);
            }
        }
    } 
 
*/ 
	// Enumerate the key values. 
	//列出子键
    if (cValues!=0) 
    {
        printf( "\n\t检测到 %d个共享:\n", cValues);
		int k=0;

        for (i=0, retCode=ERROR_SUCCESS; i<cValues; i++) 
        { 
            cchValue = MAX_VALUE_NAME; 
			shareSize=MAX_KEY_LENGTH;
            achValue[0] = '\0'; 
            retCode = RegEnumValue(hKey, i, 
                achValue, 
                &cchValue, 
                NULL, 
                NULL,
                NULL,
                NULL);
 
            if (retCode == ERROR_SUCCESS ) 
            { 
				
				// _tprintf(TEXT("(%d) %s\t\t\t\t"), i+1, achValue); 
			
					printf("\t(%d) %s\t",i+1,achValue);


			shareValue[0] = '\0'; 
		
			LONG ret0=RegQueryValueEx(hKey,achValue,NULL,&shareType, (LPBYTE)shareValue, &shareSize);  //查询共享的键值
	
		
			if(ret0==ERROR_SUCCESS)
				{
					if(shareValue[8]=='L')
					
						{	cout<<"是匿名共享";
							k++;			
						}
					else 
						cout<<"非匿名共享";
					

				}
			
			else 
				{
					printf("WRONG");
				}
		



			cout<<endl<<endl;
//
            } 
		
	

        }
			if(k!=0)
		
			printf("\t共检测到存在%d个匿名共享\n",k);
			
			else printf("\t未检测到匿名共享\n");

    }
	else
	
		printf("\n\t未检测到任何共享\n");
	}
	else
	{
	printf("打开注册表失败");
	exit(-1);
	}

	RegCloseKey(hKey);
}

