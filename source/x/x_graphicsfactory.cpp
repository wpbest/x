#include "x_pch.h"

#include "x/x_graphicsfactory.h"

#include "x/x_opengles2.h"
#include "x/x_gdiplus.h"

namespace x
{
	x_GraphicsFactory::x_GraphicsFactory(void)
	{
		m_pGraphics = nullptr;
	}

	x_GraphicsFactory::~x_GraphicsFactory(void)
	{
		if (m_pGraphics) delete m_pGraphics;
	}

	x_Bool x_GraphicsFactory::create(x_GraphicsType graphicsType)
	{
		switch (graphicsType)
		{
		case x_GraphicsType_GDIPlus:
			m_pGraphics = new x_GDIPlus();
			break;
		case x_GraphicsType_OpenGLES2:
			m_pGraphics = new x_OpenGLES2();
			break;

		default:
			m_pGraphics = nullptr;
			break;
		}

		if (m_pGraphics)
			return true;
		else
			return false;
	}

	x_Graphics * x_GraphicsFactory::get(void)
	{
		return m_pGraphics;
	}
}
