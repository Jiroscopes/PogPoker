#include "PhysicsComponent.h"
#include "game.h"
#include <iostream>

// Position equality comparisons
bool operator == (const Position& lhs, const Position& rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

PhysicsComponent::PhysicsComponent(Entity* owner, Position pos, Size size)
{
	owner = owner;
	mPos = pos;
	mSize = size;
	mNewPosition = pos;
	homePosition = pos;
	//mNewPosition = size;
}

void PhysicsComponent::updatePosition()
{
	if (mPos.x != mNewPosition.x) {
		if (mNewPosition.x > mPos.x)
		{
			std::cout << testTime << std::endl;
			mPos.x = mPos.x + 1 * (animationSpeed * testTime);

			/* 
			
			mPos.x = mPos.x + 1 * (animationSpeed * time^2);
			
			*/
		}
		else
		{
			mPos.x = mPos.x - 1 * animationSpeed;
		}
	}
	else if (mPos.y != mNewPosition.y)
	{
		if (mNewPosition.y > mPos.y)
		{
			std::cout << "Current Time: " << Game::easingMan->easeOut(Game::easingMan->getCurrentTime(), mPos.y, mNewPosition.y, animationSpeed) << std::endl;
			mPos.y = mPos.y + 1 + Game::easingMan->easeOut(Game::easingMan->getCurrentTime(), mPos.y, mNewPosition.y, animationSpeed); //* testTime
		}
		else {
			mPos.y = mPos.y - 1 * animationSpeed;
		}
	}
}

Position PhysicsComponent::getHomePosition()
{
	return homePosition;
}

void PhysicsComponent::setNewPosition(Position pos)
{
	mNewPosition = pos;
}

void PhysicsComponent::setNewSize(Size size)
{
	mNewSize = size;
}


void PhysicsComponent::update()
{
	testTime = testTime + 1;
	this->updatePosition();
	//updateSize();
}

void PhysicsComponent::setSpeed(float speed)
{
	animationSpeed = speed;
}
