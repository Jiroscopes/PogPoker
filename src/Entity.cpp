#include "Entity.h"
#include <iostream>
#include <algorithm>
#include "GraphicsComponent.h"

//void Entity::addComponent(Component* component)
//{
//	componentLoc.push_back(component->id);
//	std::cout << "Added ID: " << component->id << std::endl;
//	components.push_back(component);
//}


void Entity::update()
{
	for (Component* comp : components)
	{
		comp->update();
	}
}

void Entity::render(SDL_Renderer* renderer)
{
	GraphicsComponent* gfx = this->getComponent<GraphicsComponent*>(1);
	gfx->render(renderer);
}
//
//template <typename T>
//T& Entity::getComponent(int id)
//{
//	int compID = std::find(componentLoc.begin(), componentLoc.end(), id);
//	return components[compID];
//}
