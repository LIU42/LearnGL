#version 330 core

in vec3 position;

uniform float offsetX;
uniform float offsetY;

void main()
{
	gl_Position = vec4(position.x + offsetX, position.y + offsetY, position.z, 1.0);
}
