#include "hack.h"

#pragma function(strnlen)
size_t strnlen(const char *string, size_t maxCount)
{
    size_t length;

    length = 0;
    while (length < maxCount && string[length] != '\0')
    {
        length++;
    }

    return length;
}

#pragma function(strlen)
size_t strlen(const char *string)
{
    return strnlen(string, SIZE_MAX);
}

#pragma function(memset)
void *memset(const void *dest, int value, size_t count)
{
    size_t i;

    for (i = 0; i < count; i++)
    {
        ((uint8_t *)dest)[i] = (uint8_t)value;
    }

    return (void *)dest;
}

#pragma function(wcsnlen)
size_t wcsnlen(const wchar_t *string, size_t maxCount)
{
    size_t length;

    length = 0;
    while (length < maxCount && string[length] != L'\0')
    {
        length++;
    }

    return length;
}

#pragma function(wcslen)
size_t wcslen(const wchar_t *string)
{
    return wcsnlen(string, SIZE_MAX);
}
