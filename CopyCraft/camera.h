#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include <GLFW/glfw3.h>
#include "transform.h"

class Camera {
public:
	Camera();
	virtual void updateProjection();
	glm::mat4 projection;
	Transform* transform;
protected:
	float fov = 45.0f;
	float near = 0.1f;
	float far = 100.0f;
};
#endif