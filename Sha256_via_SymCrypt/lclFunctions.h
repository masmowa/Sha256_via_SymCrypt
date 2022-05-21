#pragma once
void
runSha1SelfTest();
void
runSha256SelfTest();

void runHmacSha256SelfTest();

void doSha256Hash(const char* pPlainText, size_t cchPlainText);
