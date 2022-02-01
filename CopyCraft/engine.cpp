#include <GL/glew.h>
#include "engine.h"

std::vector<Vertex> triangles = {
	Vertex{{-0.5f, -0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}}, // bot left corner
	Vertex{{0.5f,  -0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}}, // bot right corner
	Vertex{{0.5f,  0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f},  {1.0f, 1.0f}}, // top right corner

	Vertex{{-0.5f, -0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}}, // bot left corner
	Vertex{{-0.5f,  0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}, // top right corner
	Vertex{{0.5f,  0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f},  {1.0f, 1.0f}}, // top right corner
};

Object* testObject;

FlyCamera* Engine::primaryCamera;

Engine::Engine()
{
	if (!glfwInit()) {
		throw "Failed to initialize GLFW Library.";
	}

	// Check if OpenGl is min ver 4.6
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	// Core profile without deprecated functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	primaryWindow = new Window(1270, 720, "CopyCraft", true);

	if (glewInit() != GLEW_OK)
	{
		throw "Failed to initialize GLEW Library.";
	}

	testObject = new Object("Kanna");
	testObject->setMesh(new Mesh(triangles));
	testObject->setTexture(new Texture("textures/test.jpg"));

	primaryCamera = new FlyCamera();

	while (!primaryWindow->shouldClose()) {
		update();
	}

	exit();
}

void Engine::update()
{
	// Clear the screen
	glClearColor(99.0f / 255.0f, 221.0f / 255.0f, 255.0f / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	testObject->update();

	primaryWindow->update();
	
	if(Input::isKeyDown(GLFW_KEY_ESCAPE)) {
		primaryWindow->close();
	}

	glfwPollEvents();
}


void Engine::exit()
{
	testObject->destroy();

	glfwTerminate();
}
