#include "delta-time.h"
#include <stdio.h>

volatile float DeltaTime::deltaTime = 0.0f;
volatile float DeltaTime::lastFrame = 0.0f;

void DeltaTime::update()
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}
