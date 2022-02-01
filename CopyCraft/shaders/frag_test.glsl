#version 460 core

out vec4 FragColor;

in vec4 vertexColor;
in vec2 textureCoord;

uniform sampler2D ourTexture;

void main() {
	FragColor = texture(ourTexture, textureCoord) * vertexColor;
}