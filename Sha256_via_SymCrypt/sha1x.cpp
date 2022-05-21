#include <Windows.h>
#include <symcrypt.h>
#include <stdarg.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "trace.h"

#include "selftest_test_input.c"

void
runSha1SelfTest()
{
	BYTE result[SYMCRYPT_SHA1_RESULT_SIZE];
	SymCryptSha1(SymCryptTestMsg3, sizeof(SymCryptTestMsg3), result);
	printf("SHA1 of \"%s\"\n", SymCryptTestMsg3);

	printfBinaryArray(SymCryptTestMsg3, sizeof(SymCryptTestMsg3));
	printfBinaryArray(result, sizeof(result));

	printfBinaryBlock(result, sizeof(result));
}