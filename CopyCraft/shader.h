#ifndef SHADER_H
#define SHADER_H
#pragma once
#include <cstdint>
#include <vector>

class Shader {
public:
	Shader(const char* source, GLenum shaderType);
	uint32_t shaderId;
private:
	void checkShaderErrors();
};
#endif