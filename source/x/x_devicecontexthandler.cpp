
#include "x_pch.h"
#include "x/x_devicecontexthandler.h"

namespace x
{
	x_DeviceContextHandler::x_DeviceContextHandler() : m_deviceContextHandler(nullptr)
	{
	}
	
	x_DeviceContextHandler::~x_DeviceContextHandler() 
	{ 
		m_deviceContextHandler = nullptr; 
	}

	void x_DeviceContextHandler::setDeviceContextHandler(void * deviceContextHandler)
	{
		m_deviceContextHandler = deviceContextHandler; 
	}

	void *x_DeviceContextHandler::getDeviceContextHandler()
	{ 
		return m_deviceContextHandler; 
	}

}