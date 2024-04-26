#include "hack.h"

void mainCRTStartup(void)
{
    InitializeFunctionLoader();



    NtTerminateProcess(NtCurrentProcess(), STATUS_SUCCESS);
}
