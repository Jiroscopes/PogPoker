#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	// Textures are handled on the GPU. Surfaces on the CPU
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

	if (tex == NULL)
	{
		fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
	}

	// Free the memory and CPU 
	SDL_FreeSurface(tempSurface);

	if (tempSurface == nullptr)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_ClearError();
	}
	return tex;
}