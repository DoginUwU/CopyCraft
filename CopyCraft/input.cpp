#include "input.h"

Input::Input() {}

bool Input::isKeyDown(int key) {
	int state = glfwGetKey(getWindow(), key);
	return state == GLFW_PRESS;
}

bool Input::isKeyUp(int key) {
	int state = glfwGetKey(getWindow(), key);
	return state == GLFW_RELEASE;
}