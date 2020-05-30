#include "card.h"
#include <string>

//const char* Card::SUITS[] = {"Diamond", "Club", "Heart", "Spade"};
//const int Card::RANKS[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; 
int card;
int suit;
int rank;

GameObject* cardObj;

Card::Card() 
{
    card = 0;
}

Card::Card(int cardNum) 
{
	rank = (cardNum % 13) + 1;
	suit = cardNum / 13;

	std::string suitAsString;

	switch (suit)
	{
	case 0:
		suitAsString = "diamonds";
		break;
	case 1:
		suitAsString = "clubs";
		break;
	case 2:
		suitAsString = "hearts";
		break;
	case 3:
		suitAsString = "spades";
		break;
	default:
		break;
	}

	std::string fileName;

	if (rank == 1) 
	{
		fileName.append("ace");
	}
	else if (rank == 11)
	{
		fileName.append("jack");
	}
	else if (rank == 12)
	{
		fileName.append("queen");
	}
	else if (rank == 13)
	{
		fileName.append("king");
	} 
	else
	{
		fileName = fileName.append(std::to_string(rank));
	}


	fileName.append("_of_");
	fileName.append(suitAsString);
	fileName.append(".png");

	std::string test = "../assets/cards/" + fileName;
	const char* temp = test.c_str();
	// Card img size is currently 726x500
	cardObj = new GameObject(temp, 0, 0, 726, 500);
}

int Card::getRank() {
    return rank;
}

int Card::getSuit() {
    return suit;
}



