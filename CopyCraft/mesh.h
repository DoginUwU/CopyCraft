#ifndef MESH_H
#define MESH_H
#pragma once
#include <glm/fwd.hpp>
#include <vector>
#include <array>
#include "vertex.h"

class Mesh {
public:
	Mesh(std::vector<Vertex> vertexData);
	void update();
	void destroy();
private:
	glm::uint32 vao;
	glm::uint32 vbo;
	std::vector<Vertex> vertex;
};
#endif