#pragma once

#include <stdlib.h>
#include <string.h>

#include "symcrypt.h"

#define SAFE_INCLUDE_GUARD_BEGIN __pragma(warning(push)) \
                                 __pragma(warning(disable:28253)) \
                                 __pragma(warning(disable:28252)) 

#define SAFE_INCLUDE_GUARD_END   __pragma(warning(pop))
