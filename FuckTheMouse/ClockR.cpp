#include "stdafx.h"
#include "ClockR.h"


ClockR::ClockR() = default;


ClockR::~ClockR() = default;

ClockR::ClockR(std::chrono::milliseconds dly) : delay(dly)
{
	lastClick = hrClock.now();
}

bool ClockR::click(std::function<void(void)> fun)
{
	auto now = hrClock.now();
	if (now - lastClick < delay)
	{
		lastClick = now;
		fun();
		return true;
	}
	lastClick = now;
	return false;
}

void ClockR::update()
{
	lastClick = hrClock.now();
}

ClockR & ClockR::setDelay(std::chrono::milliseconds dly)
{
	delay = dly;
	return *this;
}

std::chrono::milliseconds ClockR::getDelay()
{
	return delay;
}

