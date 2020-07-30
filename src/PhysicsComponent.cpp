#include "PhysicsComponent.h"
#include <iostream>

PhysicsComponent::PhysicsComponent(Entity* owner, Position pos, Size size)
{
	owner = owner;
	mPos = pos;
	mSize = size;
	mNewPosition = pos;
	//mNewPosition = size;
}

void PhysicsComponent::updatePosition()
{
	if (mPos.x != mNewPosition.x) {
		if (mNewPosition.x > mPos.x)
		{
			mPos.x++;
		}
		else
		{
			mPos.x--;
		}
	}
	else if (mPos.y != mNewPosition.y)
	{
		if (mNewPosition.y > mPos.y)
		{
			mPos.y++;
		}
		else {
			mPos.y = mPos.y - 1;
		}
	}
}

void PhysicsComponent::setNewPosition(Position pos)
{
	mNewPosition = pos;
}

void PhysicsComponent::setBoundary(Boundary boundary)
{
	mBoundary = boundary;
}

bool PhysicsComponent::checkBoundary()
{
	//

	if (mPos.x >= mBoundary.leftX && (mPos.x + mSize.width) <= mBoundary.rightX && mPos.y >= mBoundary.topY && (mPos.y + mSize.height) <= mBoundary.bottomY)
	{
		return true;
	}
	else {
		//std::cout << "OUT OF BOUNDS! SIZE: " << mPos.x << std::endl;
		return false;
	}
}


void PhysicsComponent::setNewSize(Size size)
{
	mNewSize = size;
}

void PhysicsComponent::update()
{
	if (this->checkBoundary()) {
		this->updatePosition();
	}
	//updateSize();
}