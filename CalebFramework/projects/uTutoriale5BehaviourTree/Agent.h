#ifndef _AGENT_H_
#define _AGENT_H_

#include "Behaviour.h"
#include <glm\glm.hpp>

class Agent
{
public:
	Agent() : m_behaviour(nullptr), m_position(0), m_target(0){}
	~Agent(){}

	const glm::vec3& getPosition() const { return m_position; }
	const glm::vec3& getTarget() const { return m_target; }

	void setPosition(const glm::vec3& a_pos){ m_position= a_pos; }
	void setTarget(const glm::vec3 & a_pos){ m_target = a_pos; }

	void setBehaviour(Behaviour* a_behaviour){ m_behaviour = a_behaviour; }

	virtual void update(float a_deltaTime)
	{
		if (m_behaviour != nullptr)
			m_behaviour->execute(this);

	}
protected: 
	Behaviour* m_behaviour;
	glm::vec3 m_position;
	glm::vec3 m_target;
	
};

#endif
