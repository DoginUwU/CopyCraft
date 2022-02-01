#include "transform.h"

Transform::Transform()
{
	transform = glm::identity<glm::mat4>();
}

void Transform::setTransform(glm::mat4 trans)
{
	transform = trans;
}

glm::mat4 Transform::getTransform()
{
	return transform;
}

void Transform::translate(glm::vec3 position)
{
	transform = glm::translate(transform, position);
}

void Transform::rotate(float degress, glm::vec3 direction)
{
	transform = glm::rotate(transform, glm::radians(degress), direction);
}

void Transform::scale(glm::vec3 amount)
{
	transform = glm::scale(transform, amount);
}
