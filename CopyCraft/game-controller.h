#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#pragma once
#include "window.h"
#include "fly-camera.h"

class GameController {
public:
	static Window* primaryWindow;
	static FlyCamera* primaryCamera;
private:
	GameController();
};
#endif