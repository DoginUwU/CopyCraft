#ifndef TRANSFORM_H
#define TRANSFORM_H
#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform {
public:
	Transform();
	void setTransform(glm::mat4 trans);
	glm::mat4 getTransform();
	void translate(glm::vec3 position);
	void rotate(float degress, glm::vec3 direction);
	void scale(glm::vec3 amount);
private:
	glm::mat4 transform;
};
#endif