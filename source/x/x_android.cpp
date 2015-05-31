#include "x_pch.h"

#include "x/x_platform.h"
#include "x/x_android.h"

namespace x
{
	x_Android::x_Android()
	{
	}
	x_Android::~x_Android()
	{
	}
	x_Bool x_Android::createWindow(x_String windowTitle, x_Sint32 width, x_Sint32 height)
	{
		return x_Bool();
	}
	void x_Android::destroyWindow()
	{
	}
	x_Sint32 x_Android::messagePump()
	{
		return x_Sint32();
	}
	x_WindowHandler x_Android::getWindowHandler()
	{
		return x_WindowHandler();
	}
	void x_Android::setWindowHandler(x_WindowHandler windowHandler)
	{
	}
	x_DeviceContextHandler x_Android::getDeviceContextHandler()
	{
		return x_DeviceContextHandler();
	}
	void x_Android::setDeviceContextHandler(x_DeviceContextHandler deviceContextHandler)
	{
	}
}