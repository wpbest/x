#pragma once

#include "x/x_platform.h"


#ifdef _MSC_VER
#define x_DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
#define x_CALLBACK __stdcall
x_DECLARE_HANDLE(x_HWND);
#if defined(_WIN64)
typedef unsigned __int64 x_UINT_PTR, *x_PUINT_PTR;
typedef __int64 x_LONG_PTR, *x_PLONG_PTR;
#else
typedef unsigned int x_UINT_PTR, *x_PUINT_PTR;
typedef long x_LONG_PTR, *x_PLONG_PTR;
#endif
typedef unsigned int x_UINT;
typedef x_UINT_PTR x_WPARAM;
typedef x_LONG_PTR x_LPARAM;
typedef x_LONG_PTR x_LRESULT;
#endif


namespace x
{
	class X_API x_Win32: public x_Platform
	{
	public:
		x_Win32::x_Win32();
		virtual x_Win32::~x_Win32();

		x_Bool x_Platform::createWindow(x_String windowTitle, x_Sint32 width, x_Sint32 height);
		void x_Platform::destroyWindow();
		x_Sint32 x_Platform::messagePump();
		x_WindowHandler getWindowHandler();
		void setWindowHandler(x_WindowHandler windowHandler);
		x_DeviceContextHandler getDeviceContextHandler();
		void setDeviceContextHandler(x_DeviceContextHandler deviceContextHandler);

	private:
		static x_LRESULT x_CALLBACK WndProc(x_HWND hWnd, x_UINT message, x_WPARAM wParam, x_LPARAM lParam);
	};
}