#include "x_pch.h"

#include "x/x_string.h"

#include <string.h>
#include <stdlib.h>

namespace x
{
	x_String::x_String()
	{
		m_pWchar = nullptr;
		m_length = 0;
	}

	x_String::~x_String()
	{
		if (m_pWchar) delete m_pWchar;
		m_length = 0;
	}

	x_String::x_String(const char c)
	{
		x_PSint8 pSint8 = new x_Sint8[2];
		pSint8[0] = c;
		pSint8[1] = '\0';
		m_length = convert((const char*)pSint8, m_pWchar);
		delete pSint8;
	}

	x_String::x_String(const char * pSint8)
	{
		 m_length = convert(pSint8, m_pWchar);
	}

	x_String::x_String(const x_PWchar pWchar)
	{
		m_pWchar = pWchar;
		m_length = wcslen(pWchar);
	}

	x_String::x_String(const x_String& str)
	{
		if (str.m_length > 0)
		{
			size_t charSize = sizeof(x_Wchar);
			size_t bytesToCopy = charSize*(str.m_length + 1);
			m_pWchar = new x_Wchar[str.m_length + 1];
			memcpy(m_pWchar, str.m_pWchar, bytesToCopy);
			m_length = str.m_length;
		}
		else
		{
			m_pWchar = nullptr;
			m_length = 0;
		}
	}

	x_PWchar x_String::getPWchar()
	{
		return m_pWchar;
	}

	size_t x_String::getLength()
	{
		return m_length;
	}

	size_t x_String::convert(const char * pSchar8, x_PWchar& pWchar)
	{
		size_t length = strlen(pSchar8);
		pWchar = new x_Wchar[length + 1];
		size_t converted = mbstowcs(pWchar, pSchar8, length+1);
		return converted;
	}

}