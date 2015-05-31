#pragma once

#include "x/x_platform.h"

namespace x
{
	class X_API x_WinRT : public x_Platform
	{
	public:
		x_WinRT();
		virtual ~x_WinRT();

		x_Bool createWindow(x_String windowTitle, x_Sint32 width, x_Sint32 height);
		void destroyWindow();
		x_Sint32 messagePump();
		x_WindowHandler getWindowHandler();
		void setWindowHandler(x_WindowHandler windowHandler);
		x_DeviceContextHandler getDeviceContextHandler();
		void setDeviceContextHandler(x_DeviceContextHandler deviceContextHandler);

	};
}
