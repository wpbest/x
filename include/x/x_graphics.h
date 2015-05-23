#pragma once
#include "x/x_types.h"
#include "x/x_platform.h"

namespace x
{
	class x_Graphics
	{
	public:
		x_Graphics::x_Graphics();
		virtual x_Graphics::~x_Graphics();
		void draw();
		x_Bool create(x_Platform::x_WindowHandler *windowHandler,
			          x_Platform::x_DeviceContextHandler *deviceContextHandler);
		void destroy();
		void present();
		void size(x_Sint32 width, x_Sint32 height);

	private:
		x_Platform::x_WindowHandler *m_windowHandler;
		x_Platform::x_DeviceContextHandler *m_deviceContextHandler;
	};
}