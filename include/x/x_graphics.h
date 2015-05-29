#pragma once

#include "x/x_types.h"
#include "x/x_platform.h"

namespace x
{
	class X_API x_Graphics
	{
	public:
		x_Graphics::x_Graphics();
		virtual x_Graphics::~x_Graphics();
		virtual x_Bool create(x_WindowHandler windowHandler, x_DeviceContextHandler deviceContextHandler) = 0;
		virtual void destroy() = 0;
		virtual void clear() = 0;
		virtual void draw() = 0;
		virtual void present() = 0;
		virtual void size(x_Sint32 width, x_Sint32 height) = 0;

	protected:
		x_WindowHandler m_windowHandler;
		x_DeviceContextHandler m_deviceContextHandler;
	};
}