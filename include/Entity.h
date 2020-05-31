#pragma once
#include <vector>
#include "Component.h"

class Entity
{
private:
	std::vector<Component*> components;
	int xPos;
	int yPos;
public:
	template <class T> T addComponent(T* comp);
	int getXPosition() { return xPos; }
	int getYPosition() { return yPos; }
	void setXPosition() {};
	void setYPosition() {};
	void update();
	void render();
};