#ifndef INPUT_H
#define INPUT_H
#pragma once
#include <GLFW/glfw3.h>

class Input {
	public:
		static bool isKeyDown(int key);
		static bool isKeyUp(int key);
		static void getCursorPos(double* xpos, double* ypos);
private:
	Input();
	static GLFWwindow* getWindow() {
		return glfwGetCurrentContext();
	}
};

#endif