#ifndef TIMER
#define TIMER

#include <functional>
#include <time.h>

using std::function;

class Timer
{
public:
	Timer(int milliseconds, unsigned int currentTime, function<void()> fn);
	bool tick(unsigned int currentTime);

private:
	std::function<void(void)> m_callback;

	unsigned int m_startTime;
	unsigned int m_interval;
};

#endif
