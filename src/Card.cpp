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
		Size currentSize = *physComponent->getSize();
		SDL_GetMouseState(&x, &y);
		//std::cout << "X POS: " << x << " Y POS: " << y << std::endl;
		if ((x >= currentPos.x && x <= (currentPos.x + currentSize.width)) && (y >= currentPos.y && y <= (currentPos.y + currentSize.height))) {
			std::cout << "INSIDE" << std::endl;

			if (!mouseInside)
			{
				mouseInside = true;
				physComponent->setNewPosition({ currentPos.x, (currentPos.y - 40) }); // speed is frames per tick, ie 10 is 10 units moved in 1 tick
			}
		}
		else
		{
			// If it was inside, but no longer is reset the position
			if (mouseInside) {
				mouseInside = false;
				physComponent->setNewPosition({ currentPos.x, (currentPos.y + 40) });
			}
		}
	}

}


