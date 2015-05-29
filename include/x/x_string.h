#pragma once

#include "x/x_types.h"
#include "x/x_exports.h"

namespace x
{
	class X_API x_String
	{
	public:
		// Constructor
		x_String::x_String();

		// Destructor
		virtual x_String::~x_String();

		// Copy constructors
		x_String::x_String(const char c);
		x_String::x_String(const char * pSchar8);
		x_String::x_String(const x_PWchar pWchar);
		x_String::x_String(const x_String& str);

		// Information
		x_PWchar getPWchar();
		size_t getLength();


	private:
		size_t convert(const char *pSchar8, x_PWchar& pWchar);
		x_PWchar m_pWchar;
		size_t m_length;
	};

}