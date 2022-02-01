#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include "object.h"

class GameObject {
public:
	static void addGameObject(Object* object);
	static std::vector<Object> objects;
private:
	GameObject();
};
#endif