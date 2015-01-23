#version 330

out vec2 texCoord;
layout(location = 0) in vec3 position;

uniform mat4 projection;
uniform vec2 dimensions;
uniform mat3 transform;

uniform vec2 textureCoordinates[4];

void main()
{
	vec3 p = position;
	p.xy *= dimensions;

	texCoord = textureCoordinates[gl_VertexID];
	
	gl_Position = projection * vec4(transform* p,1 );
}
