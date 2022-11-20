#include "pch.h"
#include "Timer.h"

Timer::Timer()
	: m_DeltaTime(0.0f)
{
	float current_time = (float)glfwGetTime();
	m_CurrentFrameTime = current_time;
	m_LastFrameTime = current_time;

}

float Timer::AdjustToTimeUnit(float value, ETimeUnits unit)
{
	switch (unit)
	{
	case(ETimeUnits::Seconds):
		return GetInSeconds(value);

	case(ETimeUnits::Miliseconds):
		return GetInMiliSeconds(value);
	}
}

float Timer::GetTimeCurrent()
{
	return (float)glfwGetTime();
}

void Timer::Update()
{
	m_LastFrameTime = m_CurrentFrameTime;
	m_CurrentFrameTime = GetTimeCurrent();
	m_DeltaTime = m_CurrentFrameTime - m_LastFrameTime;
}