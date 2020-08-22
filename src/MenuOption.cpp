#include "MenuOption.h"

#include "PhysicsComponent.h"
#include "GraphicsComponent.h"

MenuOption::MenuOption(unsigned int id) : id(id)
{
	this->addComponent<PhysicsComponent*>(new PhysicsComponent(this, {0, 0}, {4 * 80, 1 * 80}));
	this->addComponent<GraphicsComponent*>(new GraphicsComponent(this, "../assets/play.png", {404, 430}));
	this->addComponent<EventComponent*>(new EventComponent(this, events));
}

void MenuOption::update() {}

void MenuOption::triggerEvent(int eventType) {

	PhysicsComponent* physComponent = this->getComponent<PhysicsComponent*>(3);
	std::cout << eventType << std::endl;
}