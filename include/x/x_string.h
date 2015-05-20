#pragma once

#include "x/x_types.h"
#include "x/x_exports.h"

namespace x
{
	class X_API x_String
	{
	public:
		x_String::x_String();
		x_String::x_String(const char * cstring);
		virtual x_String::~x_String();
		operator x::x_PWchar32();
	private:
		x::x_PWchar32 m_wcstring;
	};

}