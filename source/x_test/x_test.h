#pragma once

#include "x/x.h"

class TestApp : public x::x_App
{
public:
	TestApp::TestApp();
	TestApp::~TestApp();
	x::x_Bool TestApp::create(x::x_PWchar32 windowTitle, x::x_Sint32 width, x::x_Sint32 height);
	x::x_Sint32 TestApp::run(void);
};
