#include "hack.h"

#pragma function(memcmp)
int memcmp(const void *a, const void *b, size_t maxCount)
{
    size_t i;
    uint8_t ac;
    uint8_t bc;

    for (i = 0; i < maxCount; i++)
    {
    ac = ((uint8_t *)a)[i];
    bc = ((uint8_t *)b)[i];

    if (ac < bc)
    {
        return -1;
    }
    else if (ac > bc)
    {
        return 1;
    }
    }

    return 0;
}

#pragma function(strncmp)
int strncmp(const char* a, const char* b, size_t maxCount)
{
    size_t aLength;
    size_t bLength;

    aLength = strlen(a);
    if (aLength > maxCount)
    {
    aLength = maxCount;
    }

    bLength = strlen(b);
    if (bLength > maxCount)
    {
    bLength = maxCount;
    }

    if (aLength != bLength)
    {
    return -1;
    }

    return memcmp(a, b, aLength);
}

#pragma function(strcmp)
int strcmp(const char* a, const char* b)
{
    return strncmp(a, b, SIZE_MAX);
}

int wcsncasecmp(const wchar_t *a, const wchar_t *b, size_t maxCount)
{
    size_t i;
    size_t aLength;
    size_t bLength;
    wchar_t ac;
    wchar_t bc;

    aLength = wcslen(a);
    if (aLength > maxCount)
    {
        aLength = maxCount;
    }

    bLength = wcslen(b);
    if (bLength > maxCount)
    {
        bLength = maxCount;
    }

    if (aLength != bLength)
    {
        return -1;
    }

    for (i = 0; i < maxCount && i < aLength && i < bLength; i++)
    {
        ac = towupper(a[i]);
        bc = towupper(b[i]);

        if (ac < bc)
        {
            return -1;
        }
        else if (ac > bc)
        {
            return 1;
        }
    }

    return 0;
}

int wcscasecmp(const wchar_t *a, const wchar_t *b)
{
    return wcsncasecmp(a, b, wcslen(a));
}
