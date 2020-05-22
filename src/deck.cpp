#include "deck.h"
#include "GameObject.h"

const int Deck::DECK_SIZE = 52;

std::vector<Card> deck(Deck::DECK_SIZE);


Deck::Deck()
{
    int i;

    for (i=0; i<DECK_SIZE; i++) 
    {
		Card* newCard = new Card(i);
        deck.push_back(*newCard);
    }
}

void Deck::shuffle()
{
	srand(time(0));

	for (int i = 0; i < DECK_SIZE; i++)
	{
		//std::cout << i << std::endl;
		int r = i + (rand() % (52 - i));
		std::swap(deck[i], deck[r]);
	}

}

Card* Deck::deal()
{
	// Take two cards out
	// make them game objects
	// display them

	Card hand[2];

	if (!deck.empty()) {
		Card cardOne = deck.back();
		deck.pop_back();
		Card cardTwo = deck.back();
		deck.pop_back();
		hand[0] = cardOne;
		hand[1] = cardTwo;
	}
	else {
		std::cout << "Deck is empty ??" << std::endl;
	}

	return hand;
}

