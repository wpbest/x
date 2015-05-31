#include "x_pch.h"
#include "x\x_platformfactory.h"

#include "x/x_ios.h"
#include "x/x_android.h"
#include "x/x_win32.h"
#include "x/x_winrt.h"

namespace x
{
	x_PlatformFactory::x_PlatformFactory(void)
	{
		m_pPlatform = nullptr;
	}

	x_PlatformFactory::~x_PlatformFactory(void)
	{
		if (m_pPlatform) delete m_pPlatform;
	}

	x_Bool x_PlatformFactory::create(x_PlatformType platformType)
	{
		switch (platformType)
		{
		case x_PlatformType_iOS:
			m_pPlatform = new x_iOS();
			break;
		case x_PlatformType_Android:
			m_pPlatform = new x_Android();
			break;
		case x_PlatformType_Win32:
			m_pPlatform = new x_Win32();
			break;
		case x_PlatformType_WinRT:
			m_pPlatform = new x_WinRT();
			break;
		default:
			m_pPlatform = nullptr;
			break;
		}

		if (m_pPlatform)
			return true;
		else
			return false;

	}

	x_Platform * x_PlatformFactory::get(void)
	{
		return m_pPlatform;
	}
}