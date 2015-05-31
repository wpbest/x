#pragma once

#include "x/x_platform.h"

namespace x
{
	typedef enum _x_PlatformType
	{
		x_PlatformType_iOS,
		x_PlatformType_Android,
		x_PlatformType_Win32,
		x_PlatformType_WinRT

	} x_PlatformType;

	class X_API x_PlatformFactory
	{
	public:
		x_PlatformFactory(void);
		virtual ~x_PlatformFactory(void);
		x_Bool create(x_PlatformType platformType);
		x_Platform* get(void);

	private:
		x_Platform* m_pPlatform;

	};
}
