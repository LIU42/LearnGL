#version 450 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inTexCoord;

uniform float offsetX;
uniform float offsetY;
uniform float rotate;
uniform float aspectRatio;

out vec2 texCoord;

void main()
{
	mat4 rotateMatrix = mat4(
		 cos(radians(rotate)),  sin(radians(rotate)),  0.0,  0.0,
		-sin(radians(rotate)),  cos(radians(rotate)),  0.0,  0.0,
		0.0,                    0.0,                   1.0,  0.0,
		0.0,                    0.0,                   0.0,  1.0
	);

	mat4 offsetMatrix = mat4(
		1.0, 0.0, 0.0, offsetX,
		0.0, 1.0, 0.0, offsetY,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	);

	mat4 aspectMatrix = mat4(
		aspectRatio,  0.0, 0.0, 0.0,
		0.0,          1.0, 0.0, 0.0,
		0.0,          0.0, 1.0, 0.0,
		0.0,          0.0, 0.0, 1.0
	);

	gl_Position = vec4(inPosition, 1.0) * rotateMatrix * offsetMatrix * aspectMatrix;
	texCoord = inTexCoord;
}