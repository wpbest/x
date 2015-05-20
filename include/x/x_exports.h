#pragma once

#ifdef _MSC_VER
#ifdef X_EXPORTS
#define X_API __declspec(dllexport)
#else
#define X_API __declspec(dllimport)
#endif
#endif
