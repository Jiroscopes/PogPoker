#pragma once
#include "GraphicsComponent.h"
#include "Component.h"
#include "Timer.h"

//WARNING!!! Must create Graphics Component BEFORE this one.

// This is really a helper component to the graphics component.


class AnimationComponent : public Component
{
private:
	GraphicsComponent* gfxComponent;
	float animationSpeed;
	Timer* clock;
	int frameCount = 0;
	int numOfFrames;
	int frameSize;
public:
	AnimationComponent(GraphicsComponent* gfx, float animationSpeed, int count);
	~AnimationComponent();
	void startAnimation();
	void nextFrame();
	void update();
};