#ifndef ENGINE_H
#define ENGINE_H
#pragma once
#include <iostream>
#include <array>

#include <GLFW/glfw3.h>

#include "window.h"
#include "input.h"
#include "vertex.h"
#include "shaderProgram.h"
#include "file.h"

class Engine {
public:
	Engine();
	Window* primaryWindow;

private:
	void update();
	void exit();
	void test();
	ShaderProgram* shaderProgram;
};

#endif