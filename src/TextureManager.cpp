#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	// Textures are handled on the GPU. Surfaces on the CPU
	//std::cout << texture << std::endl;
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

	// Free the memory and CPU 
	SDL_FreeSurface(tempSurface);

	if (tempSurface == nullptr)
	{
		std::cout << "Here" << std::endl;
		std::cout << SDL_GetError() << std::endl;
	}

	return tex;
}