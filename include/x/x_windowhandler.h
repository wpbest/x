#pragma once

#include "x/x_exports.h"

namespace x
{
	class X_API x_WindowHandler
	{
	public:
		x_WindowHandler::x_WindowHandler();
		virtual x_WindowHandler::~x_WindowHandler();
		void setWindowHandler(void * windowHandler);
		void *getWindowHandler();

	private:
		void *m_windowHandler;
	};
}
