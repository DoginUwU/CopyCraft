#include "camera.h"

Camera::Camera()
{
	transform = new Transform();
	transform->translate(glm::vec3(0.0f, 0.0f, -3.0f));

	updateProjection();
}

void Camera::updateProjection()
{
	int width, height;
	GLFWwindow* window = glfwGetCurrentContext();

	glfwGetWindowSize(window, &width, &height);

	projection = glm::perspective(glm::radians(fov), (float)width / (float)height, near, far);
}
