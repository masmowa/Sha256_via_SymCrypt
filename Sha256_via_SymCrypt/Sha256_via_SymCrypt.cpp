// Sha256_via_SymCrypt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "basic_inc.h"
#include <iostream>
#include <sc_lib.h>
#include "trace.h"
#include "lclFunctions.h"

int main()
{
    const char* HelloWorldData = "Hello World!";
    runSha1SelfTest();
    runSha256SelfTest();
    runHmacSha256SelfTest();
    std::cout << "Hello World!\n";
    doSha256Hash(HelloWorldData, strlen(HelloWorldData));
}
