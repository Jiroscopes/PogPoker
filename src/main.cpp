#include <iostream>
#include "game.h"

Game* game = nullptr;

int main() 
{
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
