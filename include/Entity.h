#pragma once
#include "Component.h"
#include <vector>
#include "SDL.h"

class Entity
{
private:
	std::vector<Component*> components;
	std::vector<int> componentLoc;
	float xPos = 0;
	float yPos = 0;
public:
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
	float getXPosition() { return xPos; }
	float getYPosition() { return yPos; }
	void setXPosition() {};
	void setYPosition() {};
	void update();
	void render(SDL_Renderer* renderer);
};