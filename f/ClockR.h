#pragma once
#include <chrono>
#include <functional>

using namespace std::literals;

const std::chrono::milliseconds DELAY = 40ms;

class ClockR
{
public:
	ClockR();
	~ClockR();
	ClockR(std::chrono::milliseconds dly);
	bool click(std::function<void(void)> fun);
	void update();
	ClockR& setDelay(std::chrono::milliseconds dly);
	std::chrono::milliseconds getDelay();
private:
	std::chrono::milliseconds delay = DELAY;
	std::chrono::high_resolution_clock hrClock;
	std::chrono::time_point<typename std::chrono::high_resolution_clock> lastClick;
};

