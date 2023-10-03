#version 330 core

in vec2 texCoord;
in vec3 texColor;

uniform sampler2D textureSampler;

out vec4 outColor;

void main()
{
	outColor = texture(textureSampler, texCoord);
}
