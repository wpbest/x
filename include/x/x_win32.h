#pragma once

#include "x/x_platform.h"
#include "x/x_win32types.h"

namespace x
{
	class X_API x_Win32: public x_Platform
	{
	public:
		x_Win32();
		virtual ~x_Win32();

		virtual x_Bool createWindow(x_String windowTitle, x_Sint32 width, x_Sint32 height);
		virtual void destroyWindow();
		virtual x_Sint32 messagePump();
		x_WindowHandler getWindowHandler();
		void setWindowHandler(x_WindowHandler windowHandler);
		x_DeviceContextHandler getDeviceContextHandler();
		void setDeviceContextHandler(x_DeviceContextHandler deviceContextHandler);

	private:
		static x_LRESULT x_CALLBACK WndProc(x_HWND hWnd, x_UINT message, x_WPARAM wParam, x_LPARAM lParam);
	};
}