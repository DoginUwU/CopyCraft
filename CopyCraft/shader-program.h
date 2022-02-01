#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#pragma once
#include "shader.h"

class ShaderProgram {
public:
	ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile);
	GLuint programId;
	Shader* vertexShader; 
	Shader* fragmentShader;

private:
	void checkShaderErrors();
};
#endif