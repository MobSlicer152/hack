#include "hack.h"

wchar_t towupper(wchar_t c)
{
    return c & ~(1 << 5);
}

wchar_t towlower(wchar_t c)
{
    return c | (1 << 5);
}
