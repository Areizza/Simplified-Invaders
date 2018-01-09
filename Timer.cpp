#include "Timer.h"

Timer::Timer(int milliseconds, unsigned int currentTime, function<void()> fn)
{
	m_interval = milliseconds;
	m_callback = fn;
	m_startTime = currentTime;
}

bool Timer::tick(unsigned int currentTime)
{
	if (currentTime - m_startTime >= m_interval)
	{
		m_callback();
		return true;
	}
	return false;
}
