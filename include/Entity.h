#pragma once
#include "Component.h"
#include <vector>


class Entity
{
private:
	std::vector<Component*> components;
	std::vector<int> componentLoc;
	int xPos;
	int yPos;
public:
	//template <class T> void addComponent(T comp);
	void addComponent(Component* component);

	template<typename T> T getComponent(int id) {
		std::vector<int>::iterator compID = std::find(componentLoc.begin(), componentLoc.end(), id);
		if (compID == componentLoc.end())
		{
			std::cout << "FUCK" << std::endl;
			return 0;
		}
		int index = std::distance(componentLoc.begin(), compID);
		std::cout << index << std::endl;
		T temp = (T)components[index];
		return temp; 
	}
	int getXPosition() { return xPos; }
	int getYPosition() { return yPos; }
	void setXPosition() {};
	void setYPosition() {};
	void update();
	void render();
};