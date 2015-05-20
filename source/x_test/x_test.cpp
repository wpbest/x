#include "x_test_pch.h"
#include "x_test.h"
#include "x/x.h"

#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(int argc, char* argv[])
{
	Cx cx;
	int a = nx;
	a = a + fnx();
	return 0;
}