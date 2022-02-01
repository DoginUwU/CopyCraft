#ifndef SHADER_H
#define SHADER_H
#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
	Shader(const char* source, GLenum shaderType);
	static void setUniform(int programId, const char* name, glm::mat4 value);
	uint32_t shaderId;
private:
	void checkShaderErrors();
};
#endif