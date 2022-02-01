#version 460 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec4 aColour;
layout (location = 2) in vec2 aTexture;

uniform mat4 uTransform;
uniform mat4 uProjection;
uniform mat4 uView;

out vec4 vertexColor;
out vec2 textureCoord;

void main() {
	// gl_Position = uProjection * uView * (uTransform * vec4(aPosition, 1.0));
	gl_Position = vec4(aPosition, 1.0);
	vertexColor = aColour;
	textureCoord = aTexture;
}