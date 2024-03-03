#version 450 core

in vec2 texCoord;
in vec3 texColor;

uniform sampler2D sampler;

out vec4 outColor;

void main()
{
	outColor = texture(sampler, texCoord);
}
