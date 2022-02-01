#include "fly-camera.h"


FlyCamera::FlyCamera()
{
}

void FlyCamera::update()
{
	float cameraSpeed = 2.5f * DeltaTime::deltaTime;
	if (Input::isKeyDown(GLFW_KEY_W)) {
		transform->translate(cameraSpeed * -cameraFront);
	}
	if (Input::isKeyDown(GLFW_KEY_S)) {
		transform->translate(cameraSpeed * cameraFront);
	}
	if (Input::isKeyDown(GLFW_KEY_A)) {
		transform->translate(glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed);
	}
	if (Input::isKeyDown(GLFW_KEY_D)) {
		transform->translate(-glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed);
	}
}
