#include "x_test_pch.h"

#include "x_test.h"


#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

TestApp::TestApp()
{
}

TestApp::~TestApp()
{
}

x::x_Bool TestApp::create(x::x_PWchar32 windowTitle, x::x_Sint32 width, x::x_Sint32 height)
{
	return x_App::create(windowTitle, width, height);
}

x::x_Sint32 TestApp::run(void)
{
	return x_App::run();
}

int main(int argc, char* argv[])
{
	TestApp testApp;
	x::x_Sint32 exitCode = 1;
	x::x_String windowTitle("X Test");

	if (testApp.create(windowTitle, 1024, 768))
	{
		exitCode = testApp.run();
	}

	return exitCode;
}

