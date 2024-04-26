#pragma once

#include <stdint.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#include "phnt.h"
#include "phnt_windows.h"

#define HackAssert(condition)                                                                                          \
    if (!(condition))                                                                                                  \
    {                                                                                                                  \
        DbgPrint("Assertion \"" #condition "\" failed");                                                               \
        NtTerminateProcess(NtCurrentProcess(), STATUS_ASSERTION_FAILURE);                                              \
    }

#ifdef __INTELLISENSE__
#define restrict
#endif

extern void InitializeFunctionLoader(void);
