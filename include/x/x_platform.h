#pragma once

#include "x/x_types.h"
#include "x/x_string.h"
#include "x/x_event.h"

namespace x
{

	class X_API x_Platform
	{
	public:
		class x_WindowHandler;
		class x_DeviceContextHandler;
		x_Platform::x_Platform();
		virtual x_Platform::~x_Platform();
		x_Bool x_Platform::createWindow(x_Wchar32 *title, x_Sint32 width, x_Sint32 height);
		void x_Platform::destroyWindow();
		void x_Platform::pollEvents(x::x_Bool &quit);
		x_WindowHandler *GetWindowHandler();
		x_DeviceContextHandler *GetDeviceContextHandler();
		static void *GetHandler(x_WindowHandler *windowHandler);
		static void *GetHandler(x_DeviceContextHandler *deviceContextHandler);

	private:
		x::x_Wchar32 *m_windowTitle;
		x_WindowHandler *m_windowHandler;
		x_DeviceContextHandler  *m_deviceContextHandler;
	};
}
