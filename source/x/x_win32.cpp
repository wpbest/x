#include "x_pch.h"
#include "x/x_win32.h"

#include "x/x_app.h"

#include <windows.h>

namespace x
{

	x_Win32::x_Win32()
	{

	}

	x_Win32::~x_Win32()
	{

	}

	x_Bool x_Win32::createWindow(x_String windowTitle, x_Sint32 width, x_Sint32 height)
	{
		WNDCLASSEXW windowClass = {};
		windowClass.cbSize = sizeof(WNDCLASSEXW);
		windowClass.style = CS_OWNDC;
		windowClass.lpfnWndProc = (WNDPROC)WndProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = GetModuleHandle(NULL);
		windowClass.hIcon = NULL;
		windowClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
		windowClass.hbrBackground = 0;
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = windowTitle.getPWchar();
		if (!RegisterClassExW(&windowClass))
		{
			return false;
		}

		DWORD style = WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_SYSMENU;
		DWORD extendedStyle = WS_EX_APPWINDOW;

		RECT sizeRect = { 0, 0, width, height };

		AdjustWindowRectEx(&sizeRect, style, false, extendedStyle);

		HWND hWnd = CreateWindowExW(extendedStyle, windowTitle.getPWchar(), windowTitle.getPWchar(), style, CW_USEDEFAULT, CW_USEDEFAULT,
			sizeRect.right - sizeRect.left, sizeRect.bottom - sizeRect.top, NULL, NULL,
			GetModuleHandle(NULL), this);

		if (hWnd)
			x_Platform::s_pWindowHandler->setWindowHandler(hWnd);
		else
			return false;

		SetWindowLongPtrW(hWnd, GWLP_USERDATA, reinterpret_cast<LONGLONG>(this));

		ShowWindow(hWnd, SW_SHOW);

		HDC hDC = GetDC(hWnd);

		if (hDC)
			x_Platform::s_pDeviceContextHandler->setDeviceContextHandler(hDC);
		else
		{
			destroyWindow();
			return false;
		}

		return true;
	}

	void x_Win32::destroyWindow()
	{
		HDC hDC = (HDC)x_Platform::s_pDeviceContextHandler->getDeviceContextHandler();
		HWND hWnd = (HWND)x_Platform::s_pWindowHandler->getWindowHandler();

		if (hDC)
		{
			ReleaseDC(hWnd, hDC);
			x_Platform::s_pDeviceContextHandler->setDeviceContextHandler(nullptr);
		}

		if (hWnd)
		{
			DestroyWindow(hWnd);
			x_Platform::s_pWindowHandler->setWindowHandler(nullptr);
		}

		UnregisterClassW(s_pWindowTitle->getPWchar(), NULL);
	}

	x_Sint32 x_Win32::messagePump()
	{
		MSG msg = {};
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return (x_Sint32)msg.wParam;
	}

	x_WindowHandler x_Win32::getWindowHandler()
	{
		return *x_Platform::s_pWindowHandler;
	}

	void x_Win32::setWindowHandler(x_WindowHandler windowHandler)
	{
		*x_Platform::s_pWindowHandler = windowHandler;
	}

	x_DeviceContextHandler x_Win32::getDeviceContextHandler()
	{
		return *x_Platform::s_pDeviceContextHandler;
	}

	void x_Win32::setDeviceContextHandler(x_DeviceContextHandler deviceContextHandler)
	{
		*x_Platform::s_pDeviceContextHandler = deviceContextHandler;
	}

	x_LRESULT x_CALLBACK x_Win32::WndProc(x_HWND hWnd, x_UINT message, x_WPARAM wParam, x_LPARAM lParam)
	{
			switch (message)
			{
			case WM_DESTROY:
				break;
			case WM_CLOSE:
				if (s_pOnClose)
				{
					(*s_pOnClose)();
				}
				break;
			case WM_SIZE:
			{
				if (s_pOnClose)
				{
					RECT winRect;
					GetClientRect((HWND)hWnd, &winRect);

					POINT topLeft;
					topLeft.x = winRect.left;
					topLeft.y = winRect.top;
					ClientToScreen((HWND)hWnd, &topLeft);

					POINT botRight;
					botRight.x = winRect.right;
					botRight.y = winRect.bottom;
					ClientToScreen((HWND)hWnd, &botRight);

					x_Sint32 x = botRight.x - topLeft.x;
					x_Sint32 y = botRight.y - topLeft.y;

					(*s_pOnSize)(x, y);
				}
				break;
			}
			}
		return DefWindowProcW((HWND)hWnd, message, wParam, lParam);
	}

}