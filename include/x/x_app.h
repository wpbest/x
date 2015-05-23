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
		virtual x_Bool x_App::create(x_PWchar32 windowTitle, x_Sint32 width, x_Sint32 height);
		virtual x_Sint32 x_App::run(void);
	private:
		x_Graphics *m_graphics;
		x_Platform *m_platform;
		x_Bool m_running;
	};
}