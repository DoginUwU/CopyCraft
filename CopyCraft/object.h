#ifndef OBJECT_H
#define OBJECT_H
#pragma once
#include "transform.h"
#include "mesh.h"
#include "shader-program.h"
#include "texture.h"
#include "file.h"
#include "game-controller.h"

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
	Transform* transform;
	Mesh* mesh;
	ShaderProgram* shaders;
	Texture* texture;
	const char* name;
};
#endif