#pragma once

enum class ETimeUnits { Seconds, Miliseconds };

class Timer
{
public:
	Timer();
	void Update();

	inline float GetCurrentFrameTime(ETimeUnits unit) { return AdjustToTimeUnit(m_CurrentFrameTime, unit); }
	inline float GetLastFrameTime(ETimeUnits unit) { return AdjustToTimeUnit(m_LastFrameTime, unit); }
	inline float GetDeltaTime(ETimeUnits unit) { return AdjustToTimeUnit(m_DeltaTime, unit); }
	inline float GetFPS() { return 1.0 / GetDeltaTime(ETimeUnits::Seconds); }
private:
	float AdjustToTimeUnit(float value, ETimeUnits unit);
	inline float GetInSeconds(float time) const { return time; }
	inline float GetInMiliSeconds(float time) const { return time * 1000.0f; }
	float GetTimeCurrent();

	float m_CurrentFrameTime;
	float m_LastFrameTime;
	float m_DeltaTime;
};

