#version 330 core

in vec3 inPosition;
in vec2 inTexCoord;

uniform float screenRatio;
uniform float offsetX;
uniform float offsetY;
uniform float offsetAngle;

out vec2 texCoord;

void main()
{
	float radiansAngle = radians(offsetAngle);

	float x = inPosition.x * cos(radiansAngle) - inPosition.y * sin(radiansAngle);
	float y = inPosition.x * sin(radiansAngle) + inPosition.y * cos(radiansAngle);

	gl_Position = vec4((x + offsetX) * screenRatio, y + offsetY, inPosition.z, 1.0);
	texCoord = inTexCoord;
}
