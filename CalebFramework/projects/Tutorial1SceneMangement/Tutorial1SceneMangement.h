#pragma once

#include "Application.h"
#include <glm/glm.hpp>

// derived application class that wraps up all globals neatly
class Tutorial1SceneMangement : public Application
{
public:

	Tutorial1SceneMangement();
	virtual ~Tutorial1SceneMangement();

protected:

	virtual bool onCreate(int a_argc, char* a_argv[]);
	virtual void onUpdate(float a_deltaTime);
	virtual void onDraw();
	virtual void onDestroy();

	int planeSphereTest(const glm::vec4& a_plane, const glm::vec3& a_center, float a_radius);
	void getFrustrumPlanes(const glm::mat4& a_transform, glm::vec4* a_planes);


	glm::mat4	m_cameraMatrix;
	glm::mat4	m_projectionMatrix;
};