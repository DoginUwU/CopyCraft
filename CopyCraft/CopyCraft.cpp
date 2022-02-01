// CopyCraft.cpp: define o ponto de entrada para o aplicativo.
//

#include "CopyCraft.h"

std::vector<Vertex> triangles = {
	Vertex{{-0.5f, -0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}}, // bot left corner
	Vertex{{0.5f,  -0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f}, {1.0f, 0.0f}}, // bot right corner
	Vertex{{0.5f,  0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f},  {1.0f, 1.0f}}, // top right corner

	Vertex{{-0.5f, -0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f}, {0.0f, 0.0f}}, // bot left corner
	Vertex{{-0.5f,  0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f}, {0.0f, 1.0f}}, // top right corner
	Vertex{{0.5f,  0.5f, 0.0f}, {1.0f,  1.0f, 1.0f, 1.0f},  {1.0f, 1.0f}}, // top right corner
};

int main()
{
	Engine* engine = new Engine();

	engine->primaryWindow = new Window(1270, 720, "CopyCraft", true);
	engine->primaryCamera = new FlyCamera();

	engine->initialize();

	while (!engine->shouldClose()) {
		engine->update();
	}

	engine->exit();

	return 0;
}
