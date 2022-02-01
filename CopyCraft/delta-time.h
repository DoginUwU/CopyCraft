#ifndef DELTATIME_H
#define DELTATIME_H
#pragma once
#include <GLFW/glfw3.h>

class DeltaTime{
public:
	static void update();
	volatile static float deltaTime;
	volatile static float lastFrame;
};
#endif