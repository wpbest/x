#pragma once

#include "x/x_types.h"
#include "x/x_exports.h"

namespace x
{
	class X_API x_App
	{
	public:
		x_App::x_App();
		virtual x_App::~x_App();
		virtual x::x_Bool x_App::create(x::x_PWchar32 windowTitle, x::x_Sint32 width, x::x_Sint32 height);
		virtual x::x_Sint32 x_App::run(void);
	};
}