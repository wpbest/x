#include "x_pch.h"
#include "x/x_app.h"

namespace x
{
	x_App::x_App() :
		m_graphics(new x_Graphics()),
		m_platform(new x_Platform()),
		m_running(false)
	{
	}

	x_App::~x_App()
	{
		if (m_graphics) delete m_graphics;
		if (m_platform) delete m_platform;
		m_running = false;
	}

	x_Bool x_App::create(x_PWchar32 windowTitle, x_Sint32 width, x_Sint32 height)
	{
		x_Bool returnValue = false;

		if (m_platform->createWindow(windowTitle, width, height))
		{
			if (m_graphics->create(m_platform->GetWindowHandler(), m_platform->GetDeviceContextHandler()))
			{
				returnValue = true;
				m_running = true;
			}
		}

		return returnValue;
	}

	x_Sint32 x_App::run(void)
	{
		x_Sint32 exitCode = 0;
		x_Bool quit;

		while (m_running)
		{
			m_platform->pollEvents(quit);
			if (quit) m_running = false;
			else
			{
				m_graphics->draw();
				m_graphics->present();
			}
		}
		return exitCode;
	}
}