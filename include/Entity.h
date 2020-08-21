#pragma once
#include "Component.h"
#include <vector>
#include "SDL.h"
#include <iostream>

class Entity
{
private:
	std::vector<Component*> components;
	std::vector<int> componentLoc;
public:
	Entity();

	template <typename T>
	void addComponent(T component)
	{
		componentLoc.push_back(component->id);
		components.push_back(component);
	}

	template<typename T> T getComponent(int id) {
		std::vector<int>::iterator compID = std::find(componentLoc.begin(), componentLoc.end(), id);
		if (compID == componentLoc.end())
		{
			std::cout << "FUCK" << std::endl;
			return 0;
		}
		int index = std::distance(componentLoc.begin(), compID);
		T temp = (T)components[index];
		return temp; 
	}

	virtual void triggerEvent(int eventType) = 0;
	void update();
	void render();
};