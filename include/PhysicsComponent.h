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
	Size mNewSize;
	Size mSize;

public:
	int id = 3;
	PhysicsComponent(Entity* owner, Position pos, Size size);
	void updatePosition();
	void update();
	Position* getPosition() { return &mPos; }
	Size* getSize() { return &mSize; }
	void setNewPosition(Position pos);
	void setNewSize(Size size);
};