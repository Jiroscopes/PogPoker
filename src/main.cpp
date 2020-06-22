#include <iostream>
#include "game.h"

Game* game = nullptr;

int main() 
{
	const int FPS = 60;
	const int FRAME_DELAY = 1000 / FPS; // 16.67

	Uint32 frameStart;
	int frameTime;
	float test = 0;
	game = new Game();
	game->init("PogPoker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
	int frames = 0;
	//double previous = SDL_GetTicks();

	while (game->running()) {

		// How long since SDL was init
		frameStart = SDL_GetTicks();

		game->handleEvents();

		game->update();

		game->render();
		//for (int i = 0; i < 100000000; i++);


		//How long it took to do all operations in one iteration
		frameTime = SDL_GetTicks() - frameStart;

		// If the loop is moving faster than the game should, delay
		if (FRAME_DELAY > frameTime) {
			SDL_Delay(FRAME_DELAY - frameTime);
		}

		//std::cout << 1 / ((SDL_GetTicks() - frameStart) / 1000.f) << std::endl;
	}

	game->clean();
    return 0;
}
