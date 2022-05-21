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
runSha256SelfTest()
{
	SYMCRYPT_SHA256_CHAINING_STATE x256State;

	BYTE result[SYMCRYPT_SHA256_RESULT_SIZE];

	SymCryptSha256(SymCryptTestMsg3, sizeof(SymCryptTestMsg3), result);

	printf("SHA256 of \"%s\"\n", SymCryptTestMsg3);

	printfBinaryArray(SymCryptTestMsg3, sizeof(SymCryptTestMsg3));
	printfBinaryArray(result, sizeof(result));

	printfBinaryBlock(result, sizeof(result));

}

void runHmacSha256SelfTest()
{
	SYMCRYPT_HMAC_SHA256_EXPANDED_KEY xxKey;
	BYTE result[SYMCRYPT_HMAC_SHA256_RESULT_SIZE] = { 0 };

	SYMCRYPT_HMAC_SHA256_STATE theState = { 0 };

	SymCryptHmacSha256ExpandKey(
		&xxKey,
		SymCryptTestKey32,
		16
	);
	SymCryptHmacSha256(
		&xxKey,
		SymCryptTestMsg3,
		sizeof(SymCryptTestMsg3),
		result
	);

	printf("HMAC_SHA256 of \"%s\"\n", SymCryptTestMsg3);

	printfBinaryArray(SymCryptTestMsg3, sizeof(SymCryptTestMsg3));
	printfBinaryArray(result, sizeof(result));

	printfBinaryBlock(result, sizeof(result));
}

void
doSha256Hash(const char* pPlainText, size_t cchPlainText)
{
	std::vector<BYTE> Data((BYTE*)pPlainText, (BYTE*)pPlainText + cchPlainText);

	printf("HMAC_SHA256 of \"%s\"\n", pPlainText);

	SYMCRYPT_HMAC_SHA256_EXPANDED_KEY xxKey;
	BYTE result[SYMCRYPT_HMAC_SHA256_RESULT_SIZE] = { 0 };

	SYMCRYPT_HMAC_SHA256_STATE theState = { 0 };

	SymCryptHmacSha256ExpandKey(
		&xxKey,
		SymCryptTestKey32,
		16
	);
	SymCryptHmacSha256(
		&xxKey,
		Data.data(),
		Data.size(),
		result
	);

	printfBinaryArray(Data.data(), Data.size());
	printfBinaryArray(result, sizeof(result));

	printfBinaryBlock(result, sizeof(result));

}