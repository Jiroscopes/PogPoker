#include "MenuOption.h"

#include "PhysicsComponent.h"
#include "GraphicsComponent.h"

MenuOption::MenuOption(unsigned int id) : id(id)
{
	this->addComponent<PhysicsComponent*>(new PhysicsComponent(this, { 4 * 80 }, { 7 * 80}));
	this->addComponent<GraphicsComponent*>(new GraphicsComponent("../assets/play.png", this));
	this->addComponent<EventComponent*>(new EventComponent(this, events));
}

void MenuOption::update() {}

void MenuOption::triggerEvent(int eventType) {

	PhysicsComponent* physComponent = this->getComponent<PhysicsComponent*>(3);
	std::cout << eventType << std::endl;
}