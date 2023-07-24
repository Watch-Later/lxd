#pragma once

#include "defines.h"

namespace lxd {
	DLL_PUBLIC void sleep(int milliseconds);
	DLL_PUBLIC uint64_t nanosecond();
	DLL_PUBLIC float millisecond();
	DLL_PUBLIC double second();
	enum DateFormat {
		Default,
		Human
	};
	DLL_PUBLIC const std::string date(const DateFormat fmt = Default);
#ifdef _WIN32
	DLL_PUBLIC char* strptime(const char* s, const char* f, struct tm* tm);
#endif
}