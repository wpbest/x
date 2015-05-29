#include "x_pch.h"
#include "x/x_platform.h"



namespace x
{
	x_String* x_Platform::s_pWindowTitle = nullptr;
	x_WindowHandler* x_Platform::s_pWindowHandler = nullptr;
	x_DeviceContextHandler* x_Platform::s_pDeviceContextHandler = nullptr;
	x_OnClose x_Platform::s_pOnClose = nullptr;
	x_OnSize x_Platform::s_pOnSize = nullptr;


	x_Platform::x_Platform() 
	{
		s_pWindowTitle = new x_String();
		s_pWindowHandler = new x_WindowHandler();
		s_pDeviceContextHandler = new x_DeviceContextHandler();
	}

	x_Platform::~x_Platform()
	{
		if (s_pWindowTitle) delete s_pWindowTitle;
		if (s_pWindowHandler) delete s_pWindowHandler;
		if (s_pDeviceContextHandler) delete s_pDeviceContextHandler;
	}

	void x_Platform::registerOnClose(x_OnClose pOnClose)
	{
		s_pOnClose = pOnClose;
	}
	void x_Platform::registerOnSize(x_OnSize pOnSize)
	{
		s_pOnSize = pOnSize;
	}
}