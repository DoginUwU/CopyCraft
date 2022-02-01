#ifndef OBJECT_H
#define OBJECT_H
#pragma once
#include "mesh.h"
#include "shaderProgram.h"
#include "texture.h"
#include "file.h"

class Object {
public:
	Object(const char* objectName);
	virtual void update();
	virtual void updateShaders();
	virtual void setMesh(Mesh* newMesh);
	virtual void setTexture(Texture* newTexture);
	virtual void setShaders(ShaderProgram* newShaderProgram);
	virtual void destroy();
protected:
	Mesh* mesh;
	ShaderProgram* shaders;
	Texture* texture;
	const char* name;
};
#endif