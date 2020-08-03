#pragma once
#include "Component.h"
#include "Entity.h"

struct Position {
	int x;
	int y;
};

struct Size {
	int width;
	int height;
};

class PhysicsComponent : public Component
{
private:
	Entity* owner;
	Position mPos;
	Position mNewPosition;
	Position homePosition;
	float testTime = 2;
	Size mNewSize;
	Size mSize;
	float animationSpeed;

public:
	
	int id = 3;

	PhysicsComponent(Entity* owner, Position pos, Size size);
	void update();

	void setSpeed(float speed);

	Position getHomePosition();
	Position* getPosition() { return &mPos; }
	void updatePosition();
	void setNewPosition(Position pos);

	void setNewSize(Size size);
	Size* getSize() { return &mSize; }
};