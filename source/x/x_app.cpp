#include "x_pch.h"
#include "x/x_app.h"

#include "x/x_Win32.h"
#include "x/x_opengles2.h"

namespace x
{
	
	static x_App *s_pApp = nullptr;

	void OnClose()
	{
		if (s_pApp) s_pApp->onClose();
	}

	void OnSize(x::x_Sint32 x, x::x_Sint32 y)
	{
		if (s_pApp) s_pApp->onSize(x, y);
	}


	x_App::x_App()
	  : m_pGraphics(nullptr)
	  , m_pPlatform(nullptr)
	  , m_running(false)
	{
		s_pApp = this;
	}

	x_App::~x_App()
	{
	}

	void x_App::setGraphics(x_Graphics* pGraphics)
	{
		m_pGraphics = pGraphics;
	}

	void x_App::setPlatform(x_Platform* pPlatform)
	{
		m_pPlatform = pPlatform;
	}

	x_Bool x_App::create(x_String windowTitle, x_Sint32 width, x_Sint32 height)
	{
		x_Bool returnValue = false;
		m_pPlatform->registerOnClose(OnClose);
		m_pPlatform->registerOnSize(OnSize);
		if (m_pPlatform->createWindow(windowTitle, width, height))
		{
			if (m_pGraphics->create(m_pPlatform->getWindowHandler(), m_pPlatform->getDeviceContextHandler()))
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

		while (m_running)
		{
			exitCode = messagePump();

			if (m_running)
			{
				m_pGraphics->clear();
				m_pGraphics->draw();
				m_pGraphics->present();
			}
		}
		return exitCode;
	}

	x_Sint32 x_App::messagePump(void)
	{
		return m_pPlatform->messagePump();
	}

	void x_App::onClose(void)
	{
		m_running = false;
	}

	void x_App::onSize(x_Sint32 x, x_Sint32 y)
	{
		if (m_running) m_pGraphics->size(x, y);
	}
}