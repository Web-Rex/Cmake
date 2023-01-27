// src.h : Include file for standard system include files,
// or project specific include files.

#pragma once

// #include <iostream>

#if OUT_LIB == 1
	#include "../lib/print/print.h"
	#define USE_OUT_LIB OUT_LIB
#elif OUT_LIB == 2
	#include "lib/math/math.h"
	#define USE_OUT_LIB OUT_LIB
#elif OUT_LIB == 3
	#include "../lib/convert/convert.h"
	#define USE_OUT_LIB OUT_LIB
#endif // !OUT_LIB




// TODO: Reference additional headers your program requires here.
