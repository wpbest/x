#include "x_test_pch.h"

#include "x_test.h"
#include "x/x_opengles2.h"
#include "x/x_win32.h"

TestApp::TestApp()
{
}

TestApp::~TestApp()
{
}

void TestApp::setGraphics(x::x_Graphics* pGraphics)
{
	x::x_App::setGraphics(pGraphics);
}

void TestApp::setPlatform(x::x_Platform* pPlatform)
{
	x::x_App::setPlatform(pPlatform);
}

x::x_Bool TestApp::create(x::x_String windowTitle, x::x_Sint32 width, x::x_Sint32 height)
{
	return x_App::create(windowTitle, width, height);
}

x::x_Sint32 TestApp::run(void)
{
	return x_App::run();
}

x::x_Sint32 TestApp::messagePump(void)
{
	return x_App::messagePump();
}

void TestApp::onClose(void)
{
	x_App::onClose();
}

void TestApp::onSize(x::x_Sint32 x, x::x_Sint32 y)
{
	x_App::onSize(x, y);
}

#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(int argc, char* argv[])
{
	x::x_Graphics* pGraphics = new x::x_OpenGLES2();
	x::x_Platform* pPlatform = new x::x_Win32();
	x::x_Sint32 exitCode = 1;
	x::x_String windowTitle("X Test");

	TestApp app;

	app.setGraphics(pGraphics);
	
	app.setPlatform(pPlatform);

	if (app.create(windowTitle, 1024, 768))
	{
		exitCode = app.run();
	}

	if (pGraphics) delete pGraphics;

	if (pPlatform) delete pPlatform;

	return exitCode;
}

