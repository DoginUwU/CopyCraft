#include "window.h"

Window::Window(int width, int height, const char* title, bool primary) {
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	requestedExit = false;

	if (window == nullptr) {
		glfwTerminate();
		throw "Failed to create a Window.";
	}

	if (primary) {
		glfwMakeContextCurrent(window);
		glViewport(0, 0, width, height);
	}
}


void Window::update()
{
	glfwSwapBuffers(window);
}


GLFWwindow* Window::getWindow()
{
	return window;
}

bool Window::shouldClose()
{
	return requestedExit || glfwWindowShouldClose(window);
}

void Window::close()
{
	requestedExit = true;
}
