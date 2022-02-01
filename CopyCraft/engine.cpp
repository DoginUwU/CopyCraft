#include <GL/glew.h>
#include "engine.h"

FlyCamera* Engine::primaryCamera;

Engine::Engine()
{
	if (!glfwInit()) throw "Failed to initialize GLFW Library.";

	primaryWindow = nullptr;
	primaryCamera = nullptr;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// testObject = new Object("Kanna");
	// testObject->setMesh(new Mesh(triangles));
	// testObject->setTexture(new Texture("textures/test.jpg"));
}

void Engine::initialize() {
	if (primaryWindow == nullptr) throw "Primary Window not created! Try set manually";
	if (primaryCamera == nullptr) throw "Primary Camera not created! Try set manually";
	if (glewInit() != GLEW_OK) throw "Failed to initialize GLEW Library.";

	glEnable(GL_DEPTH_TEST);
}

void Engine::update()
{
	glClearColor(99.0f / 255.0f, 221.0f / 255.0f, 255.0f / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	primaryWindow->update();
	primaryCamera->update();
	DeltaTime::update();

	

	glfwPollEvents();
}

bool Engine::shouldClose() {
	return primaryWindow->shouldClose();
}

void Engine::exit()
{
	

	glfwTerminate();
}
