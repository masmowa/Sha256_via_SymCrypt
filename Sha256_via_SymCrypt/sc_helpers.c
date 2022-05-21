#include <Windows.h>
#include <symcrypt.h>
#include <stdarg.h>
#include <stdint.h>

_Analysis_noreturn_
void
SYMCRYPT_CALL
SymCryptInjectError(PBYTE pbBuf, SIZE_T cbBuf)
{
    //
    // This feature is only used during testing. In production it is always
    // an empty function that the compiler can optimize away.
    //
    UNREFERENCED_PARAMETER(pbBuf);
    UNREFERENCED_PARAMETER(cbBuf);

}

_Analysis_noreturn_
void
SYMCRYPT_CALL
SymCryptFatal(UINT32 fatalCode)
{
    UNREFERENCED_PARAMETER(fatalCode);
}