#include <GL/glew.h>
#include "engine.h"

Engine::Engine()
{
	if (!glfwInit()) throw "Failed to initialize GLFW Library.";

	GameController::primaryWindow = nullptr;
	GameController::primaryCamera = nullptr;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Engine::initialize() {
	if (GameController::primaryWindow == nullptr) throw "Primary Window not created! Try set manually";
	if (GameController::primaryCamera == nullptr) throw "Primary Camera not created! Try set manually";
	if (glewInit() != GLEW_OK) throw "Failed to initialize GLEW Library.";

	glEnable(GL_DEPTH_TEST);
}

void Engine::update()
{
	glClearColor(99.0f / 255.0f, 221.0f / 255.0f, 255.0f / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (Object obj : GameObject::objects)
	{
		obj.update();
	}

	GameController::primaryWindow->update();
	GameController::primaryCamera->update();
	DeltaTime::update();

	glfwPollEvents();
}

bool Engine::shouldClose() {
	return GameController::primaryWindow->shouldClose();
}

void Engine::exit()
{
	for (Object obj : GameObject::objects)
	{
		obj.destroy();
	}

	glfwTerminate();
}
