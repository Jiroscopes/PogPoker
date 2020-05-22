#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	//std::cout << texture << std::endl;
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (tempSurface == nullptr)
	{
		//std::cout << SDL_GetError() << std::endl;
	}

	return tex;
}