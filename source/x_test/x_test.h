#pragma once

#include "x/x_app.h"

class TestApp : public x::x_App
{
public:
	TestApp::TestApp();
	TestApp::~TestApp();
	void setGraphics(x::x_Graphics* pGraphics);
	void setPlatform(x::x_Platform* pPlatform);

	x::x_Bool TestApp::create(x::x_String windowTitle, x::x_Sint32 width, x::x_Sint32 height);
	x::x_Sint32 TestApp::run(void);
	x::x_Sint32 TestApp::messagePump(void);
	void onClose(void);
	void onSize(x::x_Sint32 x, x::x_Sint32 y);

};
