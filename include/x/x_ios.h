#pragma once

#include "x/x_platform.h"

namespace x
{
	class x_iOS : public x_Platform
	{
	public:
		x_iOS::x_iOS();
		virtual x_iOS::~x_iOS();

		x_Bool createWindow(x_String windowTitle, x_Sint32 width, x_Sint32 height);
		void destroyWindow();
		x_Sint32 messagePump();
		x_WindowHandler getWindowHandler();
		void setWindowHandler(x_WindowHandler windowHandler);
		x_DeviceContextHandler getDeviceContextHandler();
		void setDeviceContextHandler(x_DeviceContextHandler deviceContextHandler);

	};
}
