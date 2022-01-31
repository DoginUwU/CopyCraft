#include <GL/glew.h>
#include "shaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile)
{
	programId = glCreateProgram();

	vertexShader = new Shader(vertexShaderFile, GL_VERTEX_SHADER);
	fragmentShader = new Shader(fragmentShaderFile, GL_FRAGMENT_SHADER);

	glAttachShader(programId, vertexShader->shaderId);
	glAttachShader(programId, fragmentShader->shaderId);

	glLinkProgram(programId);

	checkShaderErrors();
}

void ShaderProgram::checkShaderErrors()
{
	GLint isLinked = GL_FALSE;
	glGetProgramiv(programId, GL_LINK_STATUS, &isLinked);

	if (isLinked == GL_FALSE) {
		// ERROR

		// Find out log length
		GLint maxLength = 0;
		glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(programId, maxLength, &maxLength, &infoLog[0]);

		glDeleteProgram(programId);
		glDeleteShader(vertexShader->shaderId);
		glDeleteShader(fragmentShader->shaderId);

		throw ("Shader linking failed: \n%s", infoLog.data());
	}

	printf("[SHADER PROGRAM] Linked\n");
}
