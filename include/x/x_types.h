#pragma once

#include <stdint.h>
#include <stdbool.h>

namespace x
{
	typedef bool            x_Bool;
	typedef bool          * x_PBool;
	typedef int8_t          x_Sint8;
	typedef int8_t        * x_PSint8;
	typedef uint8_t         x_Uint8;
	typedef uint8_t       * x_PUint8;
	typedef int16_t         x_Sint16;
	typedef int16_t       * x_PSint16;
	typedef uint16_t        x_Uint16;
	typedef uint16_t      * x_PUint16;
	typedef int32_t         x_Sint32;
	typedef int32_t       * x_PSint32;
	typedef uint32_t        x_Uint32;
	typedef uint32_t      * x_PUint32;
	typedef int64_t         x_Sint64;
	typedef int64_t       * x_PSint64;
	typedef uint64_t        x_Uint64;
	typedef uint64_t      * x_PUint64;
	typedef signed char     x_Schar8;
	typedef signed char   * x_PSchar8;
	typedef unsigned char   x_Uchar8;
	typedef unsigned char * x_PUchar8;
	typedef wchar_t         x_Wchar32;
	typedef wchar_t       * x_PWchar32;
	typedef float           x_Float32;
	typedef float         * x_PFloat32;
	typedef double          x_Float64;
	typedef double        * x_PFloat64;
	typedef long double     x_Float128;
	typedef long double   * x_PFloat128;
}