#define STB_IMAGE_IMPLEMENTATION
#include "image.h"

Image::Image(const char* file)
{
	stbi_set_flip_vertically_on_load(true);

	data = stbi_load(file, &width, &height, &nrChannels, 0);

	if (!data) throw "Image not found";
}

void Image::freeImage()
{
	stbi_image_free(data);
}
