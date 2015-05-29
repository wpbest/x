#pragma once

#include "x/x_types.h"
#include "x/x_exports.h"
#include "x/x_graphics.h"
#include "x/x_platform.h"

namespace x
{
	class X_API x_App
	{
	public:
		x_App::x_App();
		virtual x_App::~x_App();
		virtual void setGraphics(x_Graphics* pGraphics);
		virtual void setPlatform(x_Platform* pPlatform);
		virtual x_Bool x_App::create(x_String windowTitle, x_Sint32 width, x_Sint32 height);
		virtual x_Sint32 x_App::run(void);
		virtual x_Sint32 messagePump(void);
		virtual void onClose(void);
		virtual void onSize(x_Sint32 x, x_Sint32 y);
	private:
		x_Graphics *m_pGraphics;
		x_Platform *m_pPlatform;
		x_Bool m_running;
	};
}