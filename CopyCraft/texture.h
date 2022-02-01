#ifndef TEXTURE_H
#define TEXTURE_H
#pragma once
#include "image.h"

class Texture {
public:
	Texture(const char* file);
	Image* image;
	unsigned int textureId;
};
#endif