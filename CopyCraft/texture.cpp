#include <GL/glew.h>
#include "texture.h"

Texture::Texture(const char* file)
{
	if (!file) return;

	image = new Image(file);

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	glGenerateMipmap(GL_TEXTURE_2D);


	image->freeImage();
}
