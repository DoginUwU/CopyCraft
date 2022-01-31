#include <GL/glew.h>
#include "engine.h"

std::array<Vertex, 3> triangles = {
	Vertex{{0.9f,  0.1f, 0.12f, 1.0f},   {-0.5f, -0.5f, 0.0f}},
	Vertex{{0.1f,  0.9f, 0.12f, 1.0f},   {0.5f,  -0.5f, 0.0f}},
	Vertex{{0.12f, 0.9f, 0.1f,  1.0f},   { 0.0f,  0.5f, 0.0f}},
};
static glm::uint32 trianglesVao;
static glm::uint32 trianglesVbo;


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

	test();

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

	glBindVertexArray(trianglesVao);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	primaryWindow->update();
	
	if(Input::isKeyDown(GLFW_KEY_ESCAPE)) {
		primaryWindow->close();
	}

	glfwPollEvents();
}

void Engine::test() {
	shaderProgram = new ShaderProgram(File::readFromFile("shaders/vertex_test.glsl").c_str(),
		File::readFromFile("shaders/frag_test.glsl").c_str());

	// VAO
	glCreateVertexArrays(1, &trianglesVao);
	glBindVertexArray(trianglesVao);

	// VBO
	glGenBuffers(1, &trianglesVbo);
	glBindBuffer(GL_ARRAY_BUFFER, trianglesVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangles), triangles.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	glUseProgram(shaderProgram->programId);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}


void Engine::exit()
{
	glDeleteBuffers(1, &trianglesVbo);
	glDeleteVertexArrays(1, &trianglesVao);

	glfwTerminate();
}
