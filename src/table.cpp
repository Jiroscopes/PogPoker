#include "table.h"
#include "game.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"

Table::Table()
{
	this->addComponent<PhysicsComponent*>(new PhysicsComponent(this, { 1 * 80, 1 * 80 }, { 14 * 80, 7 * 80 }));
	this->addComponent<GraphicsComponent*>(new GraphicsComponent(this, "../assets/table-3.png", { 1120, 560 }));
}

void Table::triggerEvent(int eventType)
{}

void Table::update()
{}
