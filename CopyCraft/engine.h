#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include "window.h"
#include "input.h"

class Engine {
public:
	Engine();
	Window* primaryWindow;

private:
	void update();
	void exit();
};

#endif