#include "UIRectangle.h"
#include <GL\glew.h>
#include <glm\ext.hpp>
#include <stb_image.h>


UIRectangle::UIRectangle(unsigned int a_shader,
						 const glm::vec2& a_dimensions, 
						 const glm::vec4& a_color) 
						 : m_shader(a_shader),
						 m_vao(0), m_vbo(0),
						 m_dimsensions(a_dimensions),
						 m_color(a_color),
						 m_texture(0)
{
	m_textureCoordinates[1] = glm::vec2(0, 1);
	m_textureCoordinates[0] = glm::vec2(0, 0);
	m_textureCoordinates[3] = glm::vec2(1, 1);
	m_textureCoordinates[2] = glm::vec2(1, 0);
	glm::vec3 vertices[4] = {
		glm::vec3(-0.5f, 0.5f, 1),
		glm::vec3(-0.5f, -0.5f, 1),
		glm::vec3(0.5f, 0.5f, 1),
		glm::vec3(0.5f, -0.5f, 1) 
	};

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec3), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT,GL_FALSE, sizeof(glm::vec3), 0);
	glBindVertexArray(0);



}


UIRectangle::~UIRectangle()
{
	glDeleteVertexArrays(1, &m_vbo);
	glDeleteBuffers(1, &m_vbo);

}
void UIRectangle::draw(const glm::mat4& a_projection)
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program != m_shader)
		glUseProgram(m_shader);

	int location = glGetUniformLocation(m_shader, "projection");
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(a_projection));

	glm::mat3 transform = UIElement::getTransform();
	location = glGetUniformLocation(m_shader, "transform");
	glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(transform));
	
	location = glGetUniformLocation(m_shader, "dimensions");
	glUniform2f(location, m_dimsensions.x, m_dimsensions.y);

	location = glGetUniformLocation(m_shader, "color");
	glUniform4fv(location, 1, glm::value_ptr(m_color));

	location = glGetUniformLocation(m_shader, "textureCoordinates");
	glUniform2fv(location, 4, (float*)m_textureCoordinates);

	location = glGetUniformLocation(m_shader, "diffuseMap");
	glUniform1i(location, 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	UIElement::draw(a_projection);

	if (program != m_shader)
		glUseProgram(program);



}

void UIRectangle::setTexture(unsigned char* a_pixelData, int a_height, int a_width, int a_format)
{

	// set pixel data for texture
	switch (a_format)
	{
	case STBI_grey: a_format = GL_LUMINANCE; break;
	case STBI_grey_alpha: a_format = GL_LUMINANCE_ALPHA; break;
	case STBI_rgb: a_format = GL_RGB; break;
	case STBI_rgb_alpha: a_format = GL_RGBA; break;
	};

	// create openGL texture
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	glTexImage2D(GL_TEXTURE_2D, 0, a_format, a_width, a_height, 0, a_format, GL_UNSIGNED_BYTE, a_pixelData);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//clear bound texture state so we dont accidentally change it
	glBindTexture(GL_TEXTURE_2D, 0);


}