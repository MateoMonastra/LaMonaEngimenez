#include "Debugger.h"

#include <glew.h>

#include <iostream>




void Debugger::ClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool Debugger::LogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ")" << function <<
			" " << file << ":" << line << std::endl;
		return false;
	}

	return true;
}
