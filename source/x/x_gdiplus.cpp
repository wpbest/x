#include "x_pch.h"

#include "x/x_gdiplus.h"

#include <objidl.h>
#include <gdiplus.h>
#include <windows.h>

#pragma comment (lib,"gdiplus.lib")

namespace x
{
	static Gdiplus::Bitmap* pBitmap = nullptr;
	static Gdiplus::Graphics* pGraphicsImage = nullptr;

	x_GDIPlus::x_GDIPlus()
	{

	}
	x_GDIPlus::~x_GDIPlus()
	{
	}
	x_Bool x_GDIPlus::create(x_WindowHandler windowHandler, x_DeviceContextHandler deviceContextHandler)
	{
		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
		Gdiplus::Status status = Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
		m_windowHandler = windowHandler;
		m_deviceContextHandler = deviceContextHandler;

		return x_Bool(true);
	}
	void x_GDIPlus::destroy()
	{
		Gdiplus::GdiplusShutdown(m_gdiplusToken);
	}
	void x_GDIPlus::clear()
	{
		RECT rect;
		HWND hWnd = (HWND)m_windowHandler.getWindowHandler();
		GetClientRect(hWnd, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;
		pBitmap = new Gdiplus::Bitmap(width, height);
		pGraphicsImage = Gdiplus::Graphics::FromImage(pBitmap);
		pGraphicsImage->Clear(Gdiplus::Color::Black);
	}
	void x_GDIPlus::draw()
	{
		Gdiplus::SolidBrush  brush(Gdiplus::Color::Red);
		Gdiplus::PointF point1(520.0f, 50.0f);
		Gdiplus::PointF point2(925.0f, 650.0f);
		Gdiplus::PointF point3(75.0f, 650.0f);
		Gdiplus::PointF points[3] = { point1, point2, point3};

		// Fill the polygon.
		pGraphicsImage->FillPolygon(&brush, points, 5);
	}
	void x_GDIPlus::present()
	{
		HDC hdc = (HDC)m_deviceContextHandler.getDeviceContextHandler();
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(pBitmap, 0, 0);
		delete pBitmap;

	}
	void x_GDIPlus::size(x_Sint32 width, x_Sint32 height)
	{
	}
}