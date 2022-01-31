#ifndef INPUT_H
#define INPUT_H
#pragma once
#include <GLFW/glfw3.h>
#include "engine.h"

class Input {
	public:
		static bool isKeyDown(int key);
		static bool isKeyUp(int key);
private:
	Input();
	static GLFWwindow* getWindow() {
		return glfwGetCurrentContext();
	}
};

#endif