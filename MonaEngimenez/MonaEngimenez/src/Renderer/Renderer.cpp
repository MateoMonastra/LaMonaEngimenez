#include "Renderer.h"

#include <fstream>
#include <string>
#include <sstream>

#include "Debugger/Debugger.h"
#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Clear(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::SwapBuffers(Window window)
{
	glfwSwapBuffers(window.GetWindow());
}

void Renderer::GenerateBuffer(unsigned int& VAO, unsigned int& shader, int& location)
{
	DebuggerCall(glGenVertexArrays(1, &VAO));
	DebuggerCall(glBindVertexArray(VAO));

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


	DebuggerCall(ShaderProgramSource source = ParseShader("../MonaEngimenez/src/Shaders/Basic.shader"));

	shader = CreateShader(source.VertexSource, source.FragmentSource);

	DebuggerCall(glUseProgram(shader));

	DebuggerCall(location = glGetUniformLocation(shader, "u_Color"));
	ASSERT(location != -1);
	DebuggerCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f));

	DebuggerCall(glBindVertexArray(0));
	DebuggerCall(glUseProgram(0));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

MONA_ENGIMENEZ unsigned int Renderer::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

MONA_ENGIMENEZ unsigned int Renderer::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);

	const char* src = source.c_str();

	glShaderSource(id, 1, &src, nullptr);

	std::cout << id << endl;

	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;

		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)_malloca(length * sizeof(char));

		glGetShaderInfoLog(id, length, &length, message);

		std::cout << "Filed to comnpile "
			<< (type == GL_VERTEX_SHADER ? "vertex" : "fragment") 
			<< " shader!" << std::endl;

		std::cout << message << std::endl;

		glDeleteShader(id);

		return 0;
	}

	return id;
}

ShaderProgramSource Renderer::ParseShader(const std::string& filepath)
{
	enum class ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	std::ifstream stream(filepath);

	if (!stream.is_open())
	{
		std::cout << "Failed to open file: " << filepath << std::endl;
	}

	std::string line;

	std::stringstream ss[2];

	ShaderType type = ShaderType::NONE;

	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}

	return { ss[0].str(), ss[1].str() };
}
