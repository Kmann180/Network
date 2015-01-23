#pragma once

#include "Application.h"
#include <glm/glm.hpp>

class Agent;
class Behaviour;

// derived application class that wraps up all globals neatly
class uTutoriale5BehaviourTree : public Application
{
public:

	uTutoriale5BehaviourTree();
	virtual ~uTutoriale5BehaviourTree();

protected:

	virtual bool onCreate(int a_argc, char* a_argv[]);
	virtual void onUpdate(float a_deltaTime);
	virtual void onDraw();
	virtual void onDestroy();

	Agent* m_agent;
	Behaviour* m_behaviour;

	glm::mat4	m_cameraMatrix;
	glm::mat4	m_projectionMatrix;
};