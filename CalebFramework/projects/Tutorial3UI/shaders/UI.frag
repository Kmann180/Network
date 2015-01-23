
#version 330

layout (location = 0) out vec4  fragColor;

uniform vec4 color;

uniform sampler2D diffuseMap;

in vec2 texCoord;

void main()
{
	fragColor = texture(diffuseMap,texCoord) * color;


}