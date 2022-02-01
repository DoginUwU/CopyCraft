#include <GL/glew.h>
#include "engine.h"

void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// camera
float lastX, lastY;
bool firstMouse = true;

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

	glfwSetCursorPosCallback(GameController::primaryWindow->getWindow(), mouse_callback);
	// tell GLFW to capture our mouse
	glfwSetInputMode(GameController::primaryWindow->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Engine::update()
{
	glClearColor(99.0f / 255.0f, 221.0f / 255.0f, 255.0f / 255.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (Object obj : GameObject::objects)
	{
		obj.update();
	}

	processInput(GameController::primaryWindow->getWindow());
	GameController::primaryCamera->update();
	GameController::primaryWindow->update();
	DeltaTime::update();

	glfwPollEvents();
}

void Engine::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		GameController::primaryCamera->ProcessKeyboard(FORWARD, DeltaTime::deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		GameController::primaryCamera->ProcessKeyboard(BACKWARD, DeltaTime::deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		GameController::primaryCamera->ProcessKeyboard(LEFT, DeltaTime::deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		GameController::primaryCamera->ProcessKeyboard(RIGHT, DeltaTime::deltaTime);
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	GameController::primaryCamera->ProcessMouseMovement(xoffset, yoffset);
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
