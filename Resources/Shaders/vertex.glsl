#version 330 core

in vec3 position;

uniform float screenRatio;
uniform float offsetX;
uniform float offsetY;
uniform float offsetAngle;

void main()
{
	float radiansAngle = radians(offsetAngle);

	float x = position.x * cos(radiansAngle) - position.y * sin(radiansAngle);
	float y = position.x * sin(radiansAngle) + position.y * cos(radiansAngle);

	gl_Position = vec4((x + offsetX) * screenRatio, y + offsetY, position.z, 1.0);
}
