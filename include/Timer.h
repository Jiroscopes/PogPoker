#pragma once
#include "SDL.h"

class Timer
{
private:
	//The clock time when the timer started
	Uint32 startTicks;

	//The ticks stored when the timer was paused
	Uint32 pausedTicks;

	//The timer status
	bool paused;
	bool started;

public:
	Timer();

	void start();
	void stop();
	void pause();
	void unpause();

	// Get time
	Uint32 getTicks();

	bool isPaused();
	bool isStarted();


};

