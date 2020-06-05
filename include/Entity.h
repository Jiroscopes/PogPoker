#pragma once
#include "Component.h"
#include <vector>


class Entity
{
private:
	std::vector<Component*> components;
	int xPos;
	int yPos;
public:
	//template <class T> void addComponent(T comp);
	void addComponent(Component* component);
	template<typename T> T& getComponent(Entity* entity);
	int getXPosition() { return xPos; }
	int getYPosition() { return yPos; }
	void setXPosition() {};
	void setYPosition() {};
	void update();
	void render();
};