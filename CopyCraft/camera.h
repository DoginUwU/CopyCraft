#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include <GLFW/glfw3.h>
#include <glm/gtx/matrix_decompose.hpp>
#include "transform.h"

class Camera {
public:
	Camera();
	virtual void updateProjection();
	virtual void update();
	glm::mat4 projection;
	Transform* transform;
protected:
	float fov = 45.0f;
	float near = 0.1f;
	float far = 100.0f;
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
};
#endif