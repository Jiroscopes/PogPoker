#include "AnimationComponent.h"


AnimationComponent::AnimationComponent(GraphicsComponent* gfx, float speed, int count) 
	: gfxComponent(gfx), animationSpeed(speed), numOfFrames(count), clock(0) 
{
	frameSize = gfxComponent->getTextureSize().width;
}


AnimationComponent::~AnimationComponent()
{
	delete clock;
}

void AnimationComponent::startAnimation()
{

	clock = new Timer();

	if (!clock->isStarted())
	{
		clock->start();
	}
}

void AnimationComponent::nextFrame()
{
	// if we've passed the last frame go back to first frame
	if (frameCount > numOfFrames)
	{
		frameCount = 0;
		gfxComponent->setTextureBoxPosition({ 0 , gfxComponent->getTextureBoxPosition().y });

		std::cout << "FRAMES RESET" << std::endl;
	}
	else
	{
		gfxComponent->setTextureBoxPosition({ gfxComponent->getTextureBoxPosition().x + (frameSize) , gfxComponent->getTextureBoxPosition().y });
	}

	std::cout << "FRAME COUNT" << frameCount << std::endl;
}

void AnimationComponent::update()
{
	if (clock->getTicks() >= animationSpeed)
	{
		frameCount++;
		clock->pause();
		nextFrame();
		std::cout << "ONE SECOND HAS PASSED: " << clock->getTicks() << std::endl;
		clock->start();
	}
}