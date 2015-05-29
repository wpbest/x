#pragma once

#include "x/x_graphics.h"

namespace x
{
	class X_API x_OpenGLES2 : public x_Graphics
	{
	public:
		x_OpenGLES2::x_OpenGLES2();
		virtual x_OpenGLES2::~x_OpenGLES2();
		x_Bool create(x_WindowHandler windowHandler, x_DeviceContextHandler deviceContextHandler);
		void destroy();
		void clear();
		void draw();
		void present();
		void size(x_Sint32 width, x_Sint32 height);

	};
}