#include <iostream>
#include "game.h"


//Card randomCard(Deck deck) 
//{
//    unsigned seed = time(0);
//    srand(seed);
//    int v1 = rand() % 51;
//
////    cout << v1;
////    cout << "\n";
//    // printf("%d of %s\n", deck.deck[v1].getRank(), deck.deck[v1].getSuit());
//     cout << deck.deck[v1].getSuit();
//     cout << "\n";
//     cout << deck.deck[v1].getRank();
//    return deck.deck[v1];
//}

Game* game = nullptr;

int main() 
{
    //Deck testDeck;
    //randomCard(testDeck);
	//SDL_Init(SDL_INIT_EVERYTHING);
	//SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	//SDL_RenderClear(renderer);

	//SDL_RenderPresent(renderer);
	//SDL_Delay(3000);

	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS; // 16.67

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("PogPoker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (game->running()) {

		// How long since SDL was init
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		//How long it took to do all operations in one iteration
		frameTime = SDL_GetTicks() - frameStart;

		// If the loop is moving faster than the game should, delay
		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}
	}

	game->clean();
    return 0;
}
