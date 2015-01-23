#ifndef _UIBUTTON_H_
#define _UIBUTTON_H_

#include "UIRectangle.h"
class UIButton : public UIRectangle
{
public:
	UIButton(unsigned int a_shader,
				const glm::vec2& a_dimensions = glm::vec2(1,1),
				const glm::vec4& a_normalColor = glm::vec4(1),
				const glm::vec4& a_pressedColor = glm::vec4(1),
				const glm::vec4& a_hoverColor =  glm::vec4(1));
	virtual ~UIButton();

	typedef void(*OnPressCB)(UIButton * a_caller, void* a_userData);

	void setPressedCB(OnPressCB a_callback, void* a_userData){ m_pressedCB = a_callback; m_pressedUD = a_userData; }
	
	virtual void update(float a_deltaTime);

protected:
	glm::vec4 m_normalColor;
	glm::vec4 m_pressedColor;
	glm::vec4 m_hoverColor;
	bool m_pressed;

	OnPressCB m_pressedCB;
	void* m_pressedUD;

};

#endif
