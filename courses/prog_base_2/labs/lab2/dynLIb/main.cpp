#include "main.h"

int check_list(list_t * list)
{
    int i;
    int sum = 0;
    for(i = 0; i<list_callSize(list); i++)
        sum+=list_callData(list, i);
    printf("Success!");
    int a = sum/list_callSize(list);
    return a;
}

void action_whenChecked(int check)
{
    if(check >= 0)
        puts("\nPositive\n");
    else
        puts("\nNegative\n");
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // attach to process
        // return FALSE to fail DLL load
        break;

    case DLL_PROCESS_DETACH:
        // detach from process
        break;

    case DLL_THREAD_ATTACH:
        // attach to thread
        break;

    case DLL_THREAD_DETACH:
        // detach from thread
        break;
    }
    return TRUE; // successful
}
