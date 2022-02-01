#include "game-object.h"

std::vector<Object> GameObject::objects;

void GameObject::addGameObject(Object* object)
{
	objects.push_back(*object);
}
