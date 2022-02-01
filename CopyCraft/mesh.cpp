#include <GL/glew.h>
#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> vertexData)
{
	vertex = vertexData;
	if (vertexData.size() == 0) return;

	// VAO
	glCreateVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexData.size(), vertexData.data(), GL_STATIC_DRAW);
}

void Mesh::update()
{
	if (vertex.size() == 0) return;

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, vertex.size());
}

void Mesh::destroy()
{
	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
}

