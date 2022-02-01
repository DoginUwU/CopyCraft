#ifndef FLYCAMERA_H
#define FLYCAMERA_H
#pragma once
#include "camera.h"
#include "input.h"
#include "delta-time.h"

class FlyCamera : public Camera {
public:
	FlyCamera();
	void update() override;
};
#endif