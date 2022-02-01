#include <GL/glew.h>
#include "object.h"

Object::Object(const char* objectName)
{
	name = objectName;
	transform = new Transform();
	mesh = new Mesh({});
	texture = new Texture(nullptr);
	shaders = new ShaderProgram(File::readFromFile("shaders/vertex_test.glsl").c_str(),
		                        File::readFromFile("shaders/frag_test.glsl").c_str());
}

void Object::update()
{
	glBindTexture(GL_TEXTURE_2D, texture->textureId);
	mesh->update();
	updateShaders();
}

void Object::updateShaders()
{
	glActiveTexture(GL_TEXTURE0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texture));

	Shader::setUniform(shaders->programId, "uTransform", transform->getTransform());
	Shader::setUniform(shaders->programId, "uProjection", GameController::primaryCamera->projection);
	Shader::setUniform(shaders->programId, "uView", GameController::primaryCamera->transform->getTransform());

	glUseProgram(shaders->programId);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

void Object::setMesh(Mesh* newMesh)
{
	mesh = newMesh;
}

void Object::setTexture(Texture* newTexture)
{
	texture = newTexture;
}

void Object::setShaders(ShaderProgram* newShaderProgram)
{
	shaders = newShaderProgram;
}

void Object::destroy()
{
	mesh->destroy();
}
