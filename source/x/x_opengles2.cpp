
#include "x_pch.h"

#include "x/x_opengles2.h"

#include <GLES3/gl3.h> 
#include <GLES3/gl3ext.h>
#include <EGL/egl.h> 
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>

#define STRING(s) #s

namespace x
{

	GLuint CompileShader(GLenum type, const char* source)
	{
		GLuint shader = glCreateShader(type);

		const char *sourceArray[1] = { source };

		glShaderSource(shader, 1, sourceArray, NULL);

		glCompileShader(shader);

		GLint compileResult;

		glGetShaderiv(shader, GL_COMPILE_STATUS, &compileResult);

		if (compileResult == 0)
		{
			GLint infoLogLength;

			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

			// glGetShaderInfoLog(shader, infoLog.size(), NULL, infoLog.data());

			glDeleteShader(shader);
			shader = 0;
		}

		return shader;
	}

	GLuint CompileProgram(const char *vsSource, const char *fsSource)
	{
		GLuint program = glCreateProgram();

		if (program == 0)
		{
			//OutputDebugStringW(L"Program creation failed");
			return 0;
		}

		GLuint vs = CompileShader(GL_VERTEX_SHADER, vsSource);
		GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fsSource);

		if (vs == 0 || fs == 0)
		{
			glDeleteShader(fs);
			glDeleteShader(vs);
			glDeleteProgram(program);
			return 0;
		}

		glAttachShader(program, vs);
		glDeleteShader(vs);

		glAttachShader(program, fs);
		glDeleteShader(fs);

		glLinkProgram(program);

		GLint linkStatus;
		glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

		if (linkStatus == 0)
		{
			GLint infoLogLength;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

			//std::vector<GLchar> infoLog(infoLogLength);
			//glGetProgramInfoLog(program, infoLog.size(), NULL, infoLog.data());

			//std::wstring errorMessage = std::wstring(L"Shader linking failed: ");
			//errorMessage += std::wstring(infoLog.begin(), infoLog.end());
			//OutputDebugStringW(errorMessage.c_str());

			glDeleteProgram(program);
			return 0;
		}

		return program;
	}

	static EGLDisplay eglDisplay = nullptr;
	static EGLContext eglContext = nullptr;
	static EGLSurface eglSurface = nullptr;
	static GLuint program = 0;

	x_OpenGLES2::x_OpenGLES2()
	{
		eglSurface = EGL_NO_SURFACE;
		eglContext = EGL_NO_CONTEXT;
		eglDisplay = EGL_NO_DISPLAY;
	}

	x_OpenGLES2::~x_OpenGLES2()
	{

	}

	void x_OpenGLES2::draw()
	{
		GLfloat vertices[] =
		{
			0.0f,  0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
		};

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(program);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);

		glEnableVertexAttribArray(0);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	x_Bool x_OpenGLES2::create(x_WindowHandler windowHandler, x_DeviceContextHandler deviceContextHandler)
	{
		m_windowHandler = windowHandler;
		m_deviceContextHandler = deviceContextHandler;

		const EGLint configAttributes[] =
		{
			EGL_RED_SIZE, 8,
			EGL_GREEN_SIZE, 8,
			EGL_BLUE_SIZE, 8,
			EGL_ALPHA_SIZE, 8,
			EGL_DEPTH_SIZE, 8,
			EGL_STENCIL_SIZE, 8,
			EGL_NONE
		};

		const EGLint surfaceAttributes[] =
		{
			EGL_NONE
		};

		const EGLint contextAttibutes[] =
		{
			EGL_CONTEXT_CLIENT_VERSION, 2,
			EGL_NONE
		};

		const EGLint displayAttributes[] =
		{
			EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
			EGL_NONE,
		};

		EGLConfig config = nullptr;

		PFNEGLGETPLATFORMDISPLAYEXTPROC eglGetPlatformDisplayEXT = reinterpret_cast<PFNEGLGETPLATFORMDISPLAYEXTPROC>(eglGetProcAddress("eglGetPlatformDisplayEXT"));

		if (!eglGetPlatformDisplayEXT)
		{
		}

		void* handler = m_deviceContextHandler.getDeviceContextHandler();

		eglDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, handler, displayAttributes);

		if (eglDisplay == EGL_NO_DISPLAY)
		{
			destroy();
			return false;
		}

		if (eglInitialize(eglDisplay, NULL, NULL) == EGL_FALSE)
		{
			destroy();
			return false;
		}

		EGLint numConfigs;
		if ((eglChooseConfig(eglDisplay, configAttributes, &config, 1, &numConfigs) == EGL_FALSE) || (numConfigs == 0))
		{
			destroy();
			return false;
		}

		EGLNativeWindowType win = (EGLNativeWindowType)m_windowHandler.getWindowHandler();


		eglSurface = eglCreateWindowSurface(eglDisplay, config, win, surfaceAttributes);

		if (eglSurface == EGL_NO_SURFACE)
		{
			destroy();
			return false;
		}

		if (eglGetError() != EGL_SUCCESS)
		{
			destroy();
			return false;
		}

		eglContext = eglCreateContext(eglDisplay, config, NULL, contextAttibutes);

		if (eglContext == EGL_NO_CONTEXT)
		{
			destroy();
			return false;
		}

		if (eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext) == EGL_FALSE)
		{
			destroy();
			return false;
		}


		const char* vs = STRING
		(
				attribute vec4 vPosition;
		        void main()
		        {
			       gl_Position = vPosition;
		        }
		);

		const char* fs = STRING
		(
				precision mediump float;
		        void main()
		        {
			       gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
		        }
		);

		program = CompileProgram(vs, fs);

		if (!program)
		{
			return false;
		}

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		return true;
	}

	void x_OpenGLES2::destroy()
	{
		if (eglDisplay != EGL_NO_DISPLAY && eglSurface != EGL_NO_SURFACE)
		{
			eglDestroySurface(eglDisplay, eglSurface);
			eglSurface = EGL_NO_SURFACE;
		}

		if (eglDisplay != EGL_NO_DISPLAY && eglContext != EGL_NO_CONTEXT)
		{
			eglDestroyContext(eglDisplay, eglContext);
			eglContext = EGL_NO_CONTEXT;
		}

		if (eglDisplay != EGL_NO_DISPLAY)
		{
			eglMakeCurrent(eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
			eglTerminate(eglDisplay);
			eglDisplay = EGL_NO_DISPLAY;
		}
	}

	void x::x_OpenGLES2::clear()
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void x_OpenGLES2::present()
	{
		if (eglSwapBuffers(eglDisplay, eglSurface) != GL_TRUE)
		{
			//OutputDebugStringW(L"Call to eglSwapBuffers failed.");
			//mTriangleRenderer.reset(nullptr);
			destroy();

			if (!create(m_windowHandler, m_deviceContextHandler))
			{
				//OutputDebugStringW(L"Failed to reinitialize EGL. Exiting.");
				//break;
			}

			//mTriangleRenderer.reset(new HelloTriangleRenderer());
			//if (!mTriangleRenderer->Initialize())
			//{
			//	OutputDebugStringW(L"Failed to reinitialize the triangle renderer. Exiting.");
			//	break;
			//}
		}
	}

	void x_OpenGLES2::size(x_Sint32 width, x_Sint32 height)
	{
		glViewport(0, 0, width, height);
	}

}