#ifndef WINDOW_H
#define WINDOW_H
#pragma once
#include <GLFW/glfw3.h>

class Window {
public:
	Window(int width, int height, const char* title, bool primary);
	void update();
	GLFWwindow* getWindow();
	bool shouldClose();
	void close();

private:
	GLFWwindow* window;
	bool requestedExit;
};

#endif