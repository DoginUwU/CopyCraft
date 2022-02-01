#ifndef VERTEX_H
#define VERTEX_H
#pragma once
#include <glm/glm.hpp>

struct Vertex {
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 texture;
};
#endif