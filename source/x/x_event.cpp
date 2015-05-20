#include "x_pch.h"

#include "x/x_event.h"

namespace x
{
	x_Event::x_Event()
	{
	}

	x_Event::x_Event(x_EventType eventType)
	{
		m_eventType = eventType;
	}

	x_Event::~x_Event()
	{
	}

	void x_Event::SetEventType(x_EventType eventType)
	{
		m_eventType = eventType;
	}

	x_EventType x_Event::GetEventType()
	{
		return m_eventType;
	}

}