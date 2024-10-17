#pragma once
#include "GLFW/glfw3.h"

struct GLFWTimer
{
	float m_StartTime = 0.0f;

	// CurrentTime=m_Running -m_StartTime
	float m_CurrenTime = 0.f;
	float m_DeltaTime = 0.0f;
	float m_LastTime = 0.f;
	uint64_t m_Ticks = 0;

	void OnStart()
	{
		m_StartTime = glfwGetTime();

	}
	void OnTick()
	{
		m_CurrenTime = glfwGetTime() - m_StartTime;
		m_DeltaTime = m_CurrenTime - m_LastTime;
		m_LastTime = m_CurrenTime;

		m_Ticks++;
	}

	uint64_t Ticks()
	{
		return this->m_Ticks;
	}
	float DeltaTime()
	{
		return this->m_DeltaTime;

	}
	float CurrenTime()
	{
		return this->m_CurrenTime;

	}

};

