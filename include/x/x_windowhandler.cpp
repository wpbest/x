#include "x_pch.h"
#include "x_windowhandler.h"

namespace x
{
	x_WindowHandler::x_WindowHandler() : m_windowHandler(nullptr)
	{
	}
	x_WindowHandler::~x_WindowHandler() 
	{ 
		m_windowHandler = nullptr; 
	}
		
	void x_WindowHandler::setWindowHandler(void * windowHandler)
	{ 
		m_windowHandler = windowHandler; 
	}
		
	void *x_WindowHandler::getWindowHandler() 
	{ 
		return m_windowHandler; 
	}
}
