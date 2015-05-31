#pragma once

#ifdef _MSC_VER
#define x_DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
#define x_CALLBACK __stdcall
x_DECLARE_HANDLE(x_HWND);
#if defined(_WIN64)
typedef unsigned __int64 x_UINT_PTR, *x_PUINT_PTR;
typedef __int64 x_LONG_PTR, *x_PLONG_PTR;
typedef unsigned __int64 x_ULONG_PTR, *x_PULONG_PTR;
#else
typedef unsigned int x_UINT_PTR, *x_PUINT_PTR;
typedef long x_LONG_PTR, *x_PLONG_PTR;
typedef unsigned long x_ULONG_PTR, *x_PULONG_PTR;
#endif
typedef unsigned int x_UINT;
typedef x_UINT_PTR x_WPARAM;
typedef x_LONG_PTR x_LPARAM;
typedef x_LONG_PTR x_LRESULT;
#endif