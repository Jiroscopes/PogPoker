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
		if (x >= currentPos.x && x <= (currentPos.x + currentSize.width)) {
			std::cout << "INSIDE" << std::endl;
		}
	}

}


