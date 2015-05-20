// x.cpp : Defines the exported functions for the DLL application.
//

#include "x_pch.h"
#include "x/x.h"


// This is an example of an exported variable
X_API int nx=0;

// This is an example of an exported function.
X_API int fnx(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see x.h for the class definition
Cx::Cx()
{
	return;
}
