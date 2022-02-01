#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <iostream>
#include <array>
#include <vector>

#include <GLFW/glfw3.h>

#include "window.h"
#include "input.h"
#include "vertex.h"
#include "camera.h"
#include "game-controller.h"
#include "game-object.h"
#include "delta-time.h"

class Engine {
public:
	Engine();
	void initialize();
	void update();
	void processInput(GLFWwindow* window);
	bool shouldClose();
	void exit();
};
#endif