#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#pragma once
#include "window.h"
#include "camera.h"

class GameController {
public:
	static Window* primaryWindow;
	static Camera* primaryCamera;
private:
	GameController();
};
#endif