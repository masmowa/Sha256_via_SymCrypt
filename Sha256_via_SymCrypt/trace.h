#pragma once
#include <windows.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(SAFE_INCLUDE_GUARD_BEGIN)
#define SAFE_INCLUDE_GUARD_BEGIN __pragma(warning(push)) \
                                 __pragma(warning(disable:28253)) \
                                 __pragma(warning(disable:28252)) 

#define SAFE_INCLUDE_GUARD_END   __pragma(warning(pop))
#endif

#if !defined(SYMCRYPT_MS_VC)
#if !defined(PCBYTE)
	typedef uint8_t* PCBYTE;
#endif
#endif

void fatal(_In_ PSTR file, ULONG line, _In_ PSTR format, ...);

//
// Macros for easy testing
//
#define FATAL( text ) {fatal( __FILE__, __LINE__, text );}
#define FATAL2( text, a ) {fatal( __FILE__, __LINE__, text, a );}
#define FATAL3( text, a, b ) {fatal( __FILE__, __LINE__, text, a, b );}
#define FATAL4( text, a, b, c  ) {fatal( __FILE__, __LINE__, text, a, b, c );}
#define FATAL5( text, a, b, c, d ) {fatal( __FILE__, __LINE__, text, a, b, c, d );}
#define FATAL6( text, a, b, c, d, e ) {fatal( __FILE__, __LINE__, text, a, b, c, d, e );}
#define CHECK( cond, text )           { if( !(cond) ) { fatal(__FILE__, __LINE__, text          );}; _Analysis_assume_( cond );}
#define CHECK3( cond, text, a )       { if( !(cond) ) { fatal(__FILE__, __LINE__, text, a       );}; _Analysis_assume_( cond );}
#define CHECK4( cond, text, a, b )    { if( !(cond) ) { fatal(__FILE__, __LINE__, text, a, b    );}; _Analysis_assume_( cond );}
#define CHECK5( cond, text, a, b, c ) { if( !(cond) ) { fatal(__FILE__, __LINE__, text, a, b, c );}; _Analysis_assume_( cond );}
#define SOFTCHECK( cond, text ) if( !(cond) ) { print( "%s(%d): %s\n", __FILE__, __LINE__, text ); }



SAFE_INCLUDE_GUARD_BEGIN
void printfBinaryBlock(_In_ PCBYTE pData, _In_ size_t cbData);
void printfBinaryArray(_In_ PCBYTE pData, _In_ size_t cbData);
SAFE_INCLUDE_GUARD_END


#ifdef __cplusplus
}
#endif