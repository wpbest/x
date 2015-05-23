#include "x_pch.h"
#include "x/x_platform.h"

#include <windows.h>

static x::x_Bool s_quit = false;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	case WM_CLOSE:
		s_quit = true;
		break;
	}
	return DefWindowProcW(hWnd, message, wParam, lParam);
}

namespace x
{
	class x_Platform::x_WindowHandler
	{
	public:
		x_WindowHandler::x_WindowHandler() : m_hwnd(nullptr) {}
		virtual x_WindowHandler::~x_WindowHandler() { m_hwnd = nullptr; }
		void SetHandler(HWND hwnd) { m_hwnd = hwnd; }
		HWND GetHandler() { return m_hwnd; }
	private:
		HWND m_hwnd;
	};

	class x_Platform::x_DeviceContextHandler
	{
	public:
		x_DeviceContextHandler::x_DeviceContextHandler() : m_hdc(nullptr) {}
		virtual x_DeviceContextHandler::~x_DeviceContextHandler() { m_hdc = nullptr; }
		void SetHandler(HDC hdc) { m_hdc = hdc; }
		HDC GetHandler() { return m_hdc; }
	private:
		HDC m_hdc;
	};

	x_Platform::x_Platform() :
		m_windowHandler(new x_WindowHandler()),
		m_deviceContextHandler(new x_DeviceContextHandler())
	{
	}

	x_Platform::~x_Platform()
	{
		if (m_windowHandler) delete m_windowHandler;
		if (m_deviceContextHandler) delete m_deviceContextHandler;
	}

	x_Bool x_Platform::createWindow(x_Wchar32 *title, x_Sint32 width, x_Sint32 height)
	{
		WNDCLASSEXW windowClass = {};
		windowClass.cbSize = sizeof(WNDCLASSEXW);
		windowClass.style = CS_OWNDC;
		windowClass.lpfnWndProc = WndProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = GetModuleHandle(NULL);
		windowClass.hIcon = NULL;
		windowClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
		windowClass.hbrBackground = 0;
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = title;
		if (!RegisterClassExW(&windowClass))
		{
			return false;
		}

		DWORD style = WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_SYSMENU;
		DWORD extendedStyle = WS_EX_APPWINDOW;

		RECT sizeRect = { 0, 0, width, height };

		AdjustWindowRectEx(&sizeRect, style, false, extendedStyle);

		HWND hWnd = CreateWindowExW(extendedStyle, title, title, style, CW_USEDEFAULT, CW_USEDEFAULT,
			sizeRect.right - sizeRect.left, sizeRect.bottom - sizeRect.top, NULL, NULL,
			GetModuleHandle(NULL), this);

		if (hWnd)
			m_windowHandler->SetHandler(hWnd);
		else
			return false;

		SetWindowLongPtrW(m_windowHandler->GetHandler(), GWLP_USERDATA, reinterpret_cast<LONGLONG>(this));

		ShowWindow(hWnd, SW_SHOW);

		HDC hDC = GetDC (hWnd);

		if (hDC)
			m_deviceContextHandler->SetHandler(hDC);
		else
		{
			x_Platform::destroyWindow();
			return false;
		}

		return true;
	}

	void x_Platform::destroyWindow()
	{
		if (m_deviceContextHandler->GetHandler())
		{
			ReleaseDC(m_windowHandler->GetHandler(), m_deviceContextHandler->GetHandler());
			m_deviceContextHandler->SetHandler(nullptr);
		}

		if (m_windowHandler->GetHandler())
		{
			DestroyWindow(m_windowHandler->GetHandler());
			m_windowHandler->SetHandler(nullptr);
		}

		UnregisterClassW(m_windowTitle, NULL);
	}

	void x_Platform::pollEvents(x_Bool &quit)
	{
		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		quit = s_quit;
	}

	x_Platform::x_WindowHandler *x_Platform::GetWindowHandler()
	{
		return m_windowHandler;
	}

	x_Platform::x_DeviceContextHandler *x_Platform::GetDeviceContextHandler()
	{
		return m_deviceContextHandler;
	}

	void *x_Platform::GetHandler(x_WindowHandler *windowHandler)
	{
		if (windowHandler)
			return (void*)windowHandler->GetHandler();
		else
			return nullptr;
	}

	void *x_Platform::GetHandler(x_DeviceContextHandler *deviceContextHandler)
	{
		if (deviceContextHandler)
			return (void*)deviceContextHandler->GetHandler();
		else
			return nullptr;
	}

}