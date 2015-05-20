#pragma once

#include "x/x_exports.h"

namespace x
{
	typedef enum _x_EventType
	{
		x_EventType_Quit,
		x_EventType_Size
	} x_EventType;

	class X_API x_Event
	{
	public:
		x_Event();
		x_Event(x_EventType eventType);
		virtual ~x_Event();
		void SetEventType(x_EventType eventType);
		x_EventType GetEventType();
	private:
		x_EventType m_eventType;
	};

	typedef x_Event* x_PEvent;

}
