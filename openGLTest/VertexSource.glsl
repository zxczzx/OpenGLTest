#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
out vec3 ourColor;

uniform float offset;

void main()
{
	gl_Position = vec4(position.x + offset, position.y, position.z, 1.0f);
	ourColor = color;
}