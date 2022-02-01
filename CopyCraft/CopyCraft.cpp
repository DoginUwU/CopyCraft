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

	GameController::primaryWindow = new Window(1270, 720, "CopyCraft", true);
	GameController::primaryCamera = new FlyCamera();

	engine->initialize();

	Object* testObject = new Object("Kanna");
	testObject->setMesh(new Mesh(triangles));
	testObject->setTexture(new Texture("textures/test.jpg"));

	GameObject::addGameObject(testObject);

	while (!engine->shouldClose()) {
		engine->update();
	}

	engine->exit();

	return 0;
}
