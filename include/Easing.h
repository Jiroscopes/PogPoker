#pragma once
#include "SDL.h"

class Easing
{

private:
	float speed;
	Uint32 time;
public:

	Easing();
	void update();
	
	void resetTime();
	Uint32 getCurrentTime();

	void setSpeed(float s);
	float getSpeed();

	float easeOut(float time, int start, int end, float totalTime); // totalTime  == speed???
};
