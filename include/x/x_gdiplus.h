#pragma once

#include "x/x_graphics.h"
#include "x/x_win32types.h"

namespace x
{
	class X_API x_GDIPlus : public x_Graphics
	{
	public:
		x_GDIPlus::x_GDIPlus();
		virtual x_GDIPlus::~x_GDIPlus();
		x_Bool create(x_WindowHandler windowHandler, x_DeviceContextHandler deviceContextHandler);
		void destroy();
		void clear();
		void draw();
		void present();
		void size(x_Sint32 width, x_Sint32 height);

	private:
		x_ULONG_PTR	m_gdiplusToken;
	};
}
