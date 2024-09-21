#pragma once
#include "Exporter.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define DebuggerCall(x) Debugger::ClearError();\
	x;\
	ASSERT(Debugger::LogCall(#x, __FILE__, __LINE__));

class Debugger
{
public:

	static void ClearError();
	static bool LogCall(const char* function, const char* file, int line);
	
};

