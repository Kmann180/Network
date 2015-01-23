#version 330

in vec2 TexCoord;

layout (location = 0) out vec4 fragColor;

uniform sampler2D diffuseMap;

void main()
{
	fragColor.rgb =texture(diffuseMap,TexCoord).rrr;
	fragColor.a = 1;

}