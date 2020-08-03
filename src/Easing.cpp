#include "Easing.h"

Easing::Easing()
{
	time = SDL_GetTicks();
	speed = 1.0;
}

void Easing::resetTime()
{
	time = 0;
}

Uint32 Easing::getCurrentTime()
{
	return time;
}

void Easing::setSpeed(float s)
{
	speed = s;
}

float Easing::getSpeed()
{
	return speed;
}

float Easing::easeOut(float time, int start, int end, float totalTime)
{
	return -end * (time /= totalTime) * (time - 2) + start;
}

void Easing::update()
{
	time = SDL_GetTicks();
}
