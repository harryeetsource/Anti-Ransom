#include "windows.h"
#include "stdio.h"

//By malvuln
//Purpose: Code Execution
//Target: REvi Ransomware
//MD5: 7d7ee58c2696794b3be958b165eb61a9
/**DISCLAIMER:
Author is NOT responsible for any damages whatsoever by using this software or improper malware
handling. By using this code you assume and accept all risk implied or otherwise.
**/

//gcc -c CLDAPI.c -m32
//gcc -shared -o CLDAPI.dll CLDAPI.o -m32

BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved){
  switch (reason) {
  case DLL_PROCESS_ATTACH:
   MessageBox(NULL, "Code Exec", "by malvuln", MB_OK);
   TCHAR buf[MAX_PATH];
   GetCurrentDirectory(MAX_PATH, TEXT(buf));
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
