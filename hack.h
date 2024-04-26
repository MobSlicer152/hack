#pragma once

#include <stdint.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#include "phnt_windows.h"
#include "phnt.h"

#define HackAssert(condition) if (!(condition)) { NtTerminateProcess(NtCurrentProcess(), STATUS_ASSERTION_FAILURE); }

extern void InitializeFunctionLoader(void);

