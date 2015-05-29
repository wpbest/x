#pragma once

#include "x/x_exports.h"

namespace x
{
	class X_API x_DeviceContextHandler
	{
	public:
		x_DeviceContextHandler::x_DeviceContextHandler();
		virtual x_DeviceContextHandler::~x_DeviceContextHandler();
		void setDeviceContextHandler(void * deviceContextHandler);
		void *getDeviceContextHandler();
	private:
		void *m_deviceContextHandler;
	};
}
