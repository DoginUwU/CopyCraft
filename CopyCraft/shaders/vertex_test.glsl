#version 460 core

layout (location = 0) in vec3 aPosition;

uniform mat4 uTransform;
uniform mat4 uProjection;
uniform mat4 uView;

out vec4 vertexColor;

void main() {
	gl_Position = vec4(aPosition, 1.0);
	vertexColor = vec4(1.0, 1.0, 1.0, 1.0); 
}