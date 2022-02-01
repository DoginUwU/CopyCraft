#ifndef IMAGE_H
#define IMAGE_H
#pragma once
#include "stb_image.h"

class Image {
public:
	Image(const char* file);
	void freeImage();
	int width;
	int height;
	int nrChannels;
	unsigned char* data;
};
#endif