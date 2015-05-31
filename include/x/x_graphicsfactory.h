#pragma once

#include "x/x_graphics.h"

namespace x
{
	typedef enum _x_GraphicsType
	{
		x_GraphicsType_GDIPlus,
		x_GraphicsType_OpenGLES2
	} x_GraphicsType;

	class X_API x_GraphicsFactory
	{
	public:
		x_GraphicsFactory(void);
		virtual ~x_GraphicsFactory(void);
		x_Bool create(x_GraphicsType graphicsType);
		x_Graphics* get(void);

	private:
		x_Graphics* m_pGraphics;

	};
}
