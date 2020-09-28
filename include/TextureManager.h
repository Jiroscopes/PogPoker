#pragma once
#include <SDL.h>

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    //static inline void void DestroyTexture();
};