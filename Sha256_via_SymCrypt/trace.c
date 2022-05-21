#include <Windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <symcrypt.h>
#include "trace.h"
#include "basic_inc.h"

// print data as hex-dump
void printfBinaryBlock(_In_ PCBYTE pData, _In_ size_t cbData)
{
    char dataAsChar[32] = { 0 };
    size_t dataLeft = 0;
    size_t lastCol = 0;
    size_t ctFillCol = 0;

    if (!pData || cbData == 0) goto cleanup;

    for (size_t i = 0; i < cbData; i += 16) {
        printf("%02x: ", (unsigned int)i);
        memset(dataAsChar, '\0', sizeof(dataAsChar));
        ctFillCol = 0;

        dataLeft = cbData - i;
        lastCol = 16;

        if (dataLeft < 16) lastCol = dataLeft;
        if (lastCol < 16) ctFillCol = 16 - lastCol;
        for (size_t j = 0; j < lastCol; ++j) {
            if (isprint((int)*pData)) {
                dataAsChar[j] = (char)*pData;
            }
            else {
                dataAsChar[j] = '.';
            }
            printf("%02x ", *(pData++));
        }
        if (ctFillCol > 0) {
            for (size_t k = 0; k < ctFillCol; ++k) {
                printf("   ");
            }
        }
        printf(" %s\n", dataAsChar);
    }
    printf("\n");
cleanup:
    dataAsChar[0] = 0;
}

// print data as 1 long string
void printfBinaryArray(_In_ PCBYTE pData, _In_ size_t cbData)
{
    int xyzzy = 0;

    if (!pData || cbData == 0) goto cleanup;

    for (size_t i = 0; i < cbData; ++i) {
        printf("%02x", pData[i]);
    }
    printf("\n");
cleanup:
    xyzzy = 0;
}

SAFE_INCLUDE_GUARD_BEGIN
_Analysis_noreturn_
VOID
fatal(_In_ PSTR file, ULONG line, _In_ PSTR format, ...)
{
    va_list vl;

    fprintf(stdout, "*\n\n***** FATAL ERROR %s(%d): ", file, line);

    va_start(vl, format);

    vfprintf(stdout, format, vl);
    fprintf(stdout, "\n");

    exit(-1);
}
SAFE_INCLUDE_GUARD_END
