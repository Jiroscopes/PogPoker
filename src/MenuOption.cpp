#include "MenuOption.h"


#include "GraphicsComponent.h"

MenuOption::MenuOption(unsigned int id, const char* texturePath, Position pos) : id(id), texturePath(texturePath), position(pos)
{
	this->addComponent<PhysicsComponent*>(new PhysicsComponent(this, position, { 4 * 80, 1 * 80 }));
	this->addComponent<GraphicsComponent*>(new GraphicsComponent(this, texturePath, {400, 80}));
	this->addComponent<EventComponent*>(new EventComponent(this, events));
}

void MenuOption::update() {}

void MenuOption::triggerEvent(int eventType) {

	PhysicsComponent* physComponent = this->getComponent<PhysicsComponent*>(3);
	GraphicsComponent* gfxComponent = this->getComponent<GraphicsComponent*>(2);

	if (eventType == 0)
	{
		int x, y;
		Position currentPos = *physComponent->getPosition();

		Size currentSize = *physComponent->getSize();
		SDL_GetMouseState(&x, &y);

		if ((x >= currentPos.x && x <= (currentPos.x + currentSize.width)) && (y >= currentPos.y && y <= (currentPos.y + currentSize.height))) {
			//std::cout << "INSIDE" << std::endl;

			// If the mouse was not already inside when the move event was detected
			if (!mouseInside)
			{
				gfxComponent->setTextureBoxPosition({0, 80});
				mouseInside = true;
			}
		}
		else
		{
			// If it was inside, but no longer is reset the position
			if (mouseInside) {
				gfxComponent->setTextureBoxPosition({ 0, 0 });
				mouseInside = false;
			}
		}
	}
}