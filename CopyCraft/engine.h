#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <iostream>
#include <array>

#include <GLFW/glfw3.h>

#include "window.h"
#include "input.h"
#include "vertex.h"
#include "object.h"
#include "fly-camera.h"

class Engine {
public:
	Engine();
	Window* primaryWindow;
	static FlyCamera* primaryCamera;

private:
	void update();
	void exit();
};

#endif