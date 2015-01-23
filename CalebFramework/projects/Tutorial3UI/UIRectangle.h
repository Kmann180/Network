#ifndef _UIRECTANGLE_H_
#define _UIRECTANGLE_H_

#include "UIElement.h"
#include <glm\glm.hpp>
#include <vector>

//using glm::vec4;


class UIRectangle : public UIElement
{
public:
	UIRectangle(unsigned int a_shader,const glm::vec2& a_dimensions = glm::vec2(1,1),const glm::vec4& a_color = glm::vec4(1));

	virtual ~UIRectangle();

	virtual void draw(const glm::mat4& a_projection);

	virtual void setTexture(unsigned char* a_pixelData, int a_height, int a_width, int a_format);

	int reTexture(){
		return m_texture;
	}
	unsigned int m_texture;

protected:
	unsigned int m_shader;
	unsigned int m_vao, m_vbo;

	glm::vec2 m_dimsensions;
	glm::vec4 m_color;
	glm::vec2 m_textureCoordinates[4];

};

#endif  //UIRectangle


