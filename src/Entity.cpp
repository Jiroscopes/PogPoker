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

void Entity::render()
{
	GraphicsComponent* gfx = this->getComponent<GraphicsComponent*>(2);
	//std::cout << gfx->id << std::endl;
	gfx->render();
}
//
//template <typename T>
//T& Entity::getComponent(int id)
//{
//	int compID = std::find(componentLoc.begin(), componentLoc.end(), id);
//	return components[compID];
//}
