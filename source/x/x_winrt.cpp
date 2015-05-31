#include "x_pch.h"

#include "x/x_winrt.h"

namespace x
{
	x_WinRT::x_WinRT()
	{
	}
	x_WinRT::~x_WinRT()
	{
	}
	x_Bool x_WinRT::createWindow(x_String windowTitle, x_Sint32 width, x_Sint32 height)
	{
		return x_Bool(true);
	}
	void x_WinRT::destroyWindow()
	{
	}
	x_Sint32 x_WinRT::messagePump()
	{
		return x_Sint32(0);
	}
	x_WindowHandler x_WinRT::getWindowHandler()
	{
		return x_WindowHandler();
	}
	void x_WinRT::setWindowHandler(x_WindowHandler windowHandler)
	{
	}
	x_DeviceContextHandler x_WinRT::getDeviceContextHandler()
	{
		return x_DeviceContextHandler();
	}
	void x_WinRT::setDeviceContextHandler(x_DeviceContextHandler deviceContextHandler)
	{
	}
}