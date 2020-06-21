#include "CardComponent.h"
#include <string>

CardComponent::CardComponent(int cardNum) 
{
	card = cardNum;
	rank = (cardNum % 13) + 1;
	suit = cardNum / 13;

	filename = std::to_string(cardNum) + ".png";
}

int CardComponent::getRank() {
    return rank;
}

int CardComponent::getSuit() {
    return suit;
}

int CardComponent::getCardNum()
{
	return card;
}

std::string CardComponent::getFilename()
{
	return filename;
}
void CardComponent::update()
{}


