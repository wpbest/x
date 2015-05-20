#include "x_pch.h"

#include "x/x_string.h"

#include <string.h>
#include <stdlib.h>

namespace x
{
	x_String::x_String()
	{
		m_wcstring = nullptr;
	}

	x_String::x_String(const char * cstring)
	{
		size_t stringSize = strlen(cstring) + 1;
		m_wcstring = new x::x_Wchar32[stringSize];
		size_t convertedChars = 0;
		mbstowcs_s(&convertedChars, m_wcstring, stringSize, cstring, _TRUNCATE);
	}

	x_String::~x_String()
	{
		if (m_wcstring) delete m_wcstring;
	}

	x_String::operator x::x_PWchar32()
	{
		return m_wcstring;
	}
}