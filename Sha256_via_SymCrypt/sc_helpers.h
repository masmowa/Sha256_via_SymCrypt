#pragma once
#include <Windows.h>
#include <symcrypt.h>

#if !defined(SYMCRYPT_API_VERSION)
_Analysis_noreturn_
VOID
SYMCRYPT_CALL
SymCryptInjectError(PBYTE pbBuf, SIZE_T cbBuf);
_Analysis_noreturn_
VOID
SYMCRYPT_CALL
SymCryptFatal(UINT32 fatalCode);

#endif