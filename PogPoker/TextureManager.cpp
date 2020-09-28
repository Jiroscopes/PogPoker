#include "TextureManager.h"
#include <SDL_image.h>
#include "Game.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    // Textures are handled on the GPU. Surfaces on the CPU

    SDL_Surface* tempSurface = IMG_Load(texture);

    if(!tempSurface) {
        fprintf(stderr, "IMG_Load: %s\n", IMG_GetError());
        // handle error
    }

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