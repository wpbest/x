#pragma once

#include <stdint.h>
#include <stdbool.h>

namespace x
{
	typedef bool            x_Bool,     *x_PBool;
	typedef int8_t          x_Sint8,    *x_PSint8;
	typedef uint8_t         x_Uint8,    *x_PUint8;
	typedef int16_t         x_Sint16,   *x_PSint16;
	typedef uint16_t        x_Uint16,   *x_PUint16;
	typedef int32_t         x_Sint32,   *x_PSint32;
	typedef uint32_t        x_Uint32,   *x_PUint32;
	typedef int64_t         x_Sint64,   *x_PSint64;
	typedef uint64_t        x_Uint64,   *x_PUint64;
	typedef wchar_t         x_Wchar,    *x_PWchar;
	typedef float           x_Float32,  *x_PFloat32;
	typedef double          x_Float64,  *x_PFloat64;
	typedef long double     x_Float128, *x_PFloat128;
	typedef size_t          x_Size,     *x_PSize;

}