#include <GL/glew.h>
#include "shader.h"

Shader::Shader(const char* source, int shaderType)
{
	// Create an empty shader handler
	shaderId = glCreateShader(shaderType);

	// Send the shader source to GL
	glShaderSource(shaderId, 1, &source, nullptr);

	// Compile the shader
	glCompileShader(shaderId);

	checkShaderErrors();
}

void Shader::setUniform(int programId, const char* name, glm::mat4 value)
{
	unsigned int loc = glGetUniformLocation(programId, name);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::checkShaderErrors()
{
	GLint isCompiled = GL_FALSE;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_FALSE) {
		// ERROR
		
		// Find out log length
		GLint maxLength = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetShaderInfoLog(shaderId, maxLength, &maxLength, infoLog.data());

		glDeleteShader(shaderId);

		throw ("Shader compilation failed: \n%s", infoLog.data());
	}

	printf("[SHADER] Compiled\n");
}
