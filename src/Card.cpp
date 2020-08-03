#include <iostream>
#include "Card.h"
#include "PhysicsComponent.h"

Card::Card(int cardNum)
{
	cardNum = cardNum;
	rank = (cardNum % 13) + 1;
	suit = cardNum / 13;
	filename = filename.append(std::to_string(cardNum) + ".png");
}

int Card::getRank() {
	return rank;
}

int Card::getSuit() {
	return suit;
}

int Card::getCardNum()
{
	return cardNum;
}

std::string Card::getFilename()
{
	return filename;
}

void Card::update()
{}

void Card::triggerEvent(int eventType)
{
	PhysicsComponent* physComponent = this->getComponent<PhysicsComponent*>(3);

	if (eventType == 0)
	{
		int x, y;
		Position currentPos = *physComponent->getPosition();
		Position homePos = physComponent->getHomePosition(); // acts like a boundary

		physComponent->setSpeed(2.5);

		Size currentSize = *physComponent->getSize();
		SDL_GetMouseState(&x, &y);

		if ((x >= currentPos.x && x <= (currentPos.x + currentSize.width)) && (y >= currentPos.y && y <= (currentPos.y + currentSize.height))) {
			std::cout << "INSIDE" << std::endl;

			// If the mouse was not already inside when the move event was detected
			if (!mouseInside)
			{
				mouseInside = true;
				physComponent->setNewPosition({ homePos.x, (homePos.y - 160) }); // speed is frames per tick, ie 10 is 10 units moved in 1 tick
			}
		}
		else
		{
			// If it was inside, but no longer is reset the position
			if (mouseInside) {
				mouseInside = false;
				physComponent->setNewPosition(homePos);
			}
		}
	}

}


