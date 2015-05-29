#pragma once

#include "x/x_types.h"
#include "x/x_string.h"
#include "x/x_windowHandler.h"
#include "x/x_devicecontexthandler.h"

namespace x
{
	typedef void(*x_OnClose)(void);
	typedef void(*x_OnSize)(x_Sint32 x, x_Sint32 y);

	class X_API x_Platform
	{
	public:

		x_Platform::x_Platform();
		virtual x_Platform::~x_Platform();

		virtual x_Bool x_Platform::createWindow(x_String title, x_Sint32 width, x_Sint32 height)=0;
		virtual void x_Platform::destroyWindow() = 0;
		virtual x_Sint32 x_Platform::messagePump() = 0;
		virtual x_WindowHandler getWindowHandler() = 0;
		virtual void setWindowHandler(x_WindowHandler windowHandler) = 0;
		virtual x_DeviceContextHandler getDeviceContextHandler() = 0;
		virtual void setDeviceContextHandler(x_DeviceContextHandler deviceContextHandler) = 0;
		virtual void registerOnClose(x_OnClose pOnClose);
		virtual void registerOnSize(x_OnSize pOnSize);

	protected:
		static x_String *s_pWindowTitle;
		static x_WindowHandler *s_pWindowHandler;
		static x_DeviceContextHandler *s_pDeviceContextHandler;
		static x_OnClose s_pOnClose;
		static x_OnSize s_pOnSize;
	};
}
