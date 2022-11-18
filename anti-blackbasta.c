#include "windows.h"
#include "stdio.h"

//By malvuln - 5/2022
//Target: BlackBasta Ransom
//MD5: 998022b70d83c6de68e5bdf94e0f8d71
/**DISCLAIMER:
Author is NOT responsible for any damages whatsoever by using this software or improper malware
handling. By using this code you assume and accept all risk implied or otherwise.
**/

//compile as x64
//gcc -c wow64log.c 
//gcc -shared -o wow64log.dll wow64log.o 
//DLL must live under Windows/System32 dir

BOOL APIENTRY DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved){
  switch (reason) {
  case DLL_PROCESS_ATTACH:
   MessageBox(NULL, "Code Exec", "by malvuln", MB_OK);
   exit(0);
    break;
  }
  return TRUE;
}

extern __declspec(dllexport) WINBASEAPI LONG WINAPI InterlockedExchange (LONG volatile *Target, LONG Value){
    exit(1);
}
