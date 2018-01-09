#ifndef TIMER_Mgr
#define TIMER_Mgr

#include <vector>
#include "Timer.h"

class TimerMgr
{
public:
	static TimerMgr* m_TimerMgr;
	static TimerMgr* GetInstance();

	void createTimer(int milliseconds, function<void()> fn);
	void tickTimers();

private:
	TimerMgr();
	//static TimerMgr* m_TimerMgr;
	unsigned int m_startTime;
	std::vector<Timer*> m_timers;
};

#endif
