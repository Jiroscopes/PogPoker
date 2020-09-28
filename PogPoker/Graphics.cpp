#include "Graphics.h"
#include "TextureManager.h"
#include "EntityManager.h"
#include "Game.h"

Graphics::Graphics(const char* textureSheet, Vect2I textureSize) : textureScale(textureSize), filename(textureSheet), clock(new Timer()), renderFlag(true)
{
    currentTextureBoxPosition = { 0,0 };
}

bool Graphics::init() {

    entityTransformComponent = entity->getComponent<Transform>();

    Vect2I entityPosition = entityTransformComponent.position;
    Vect2I entityScale = entityTransformComponent.scale;

    objTexture = TextureManager::LoadTexture(filename);

    // mBox is size/position on screen
    mBox = {entityPosition.x, entityPosition.y, entityScale.x, entityScale.y};

    // tBox is texture size, and position on the texture sheet
    tBox = {0, 0, textureScale.x, textureScale.y};

    return true;
}

void Graphics::setTextureBoxPosition(Vect2I newPos)
{
    tempTexturePosition.x = newPos.x;
    tempTexturePosition.y = newPos.y;
    clock->start();
}

void Graphics::updateTextureBox()
{
    //tBox.x = Game::easingMan->easeOut(clock->getTicks(), tBox.x, (tempTexturePosition.x - tBox.x) + 1, 3000);
    //tBox.y = Game::easingMan->easeOut(clock->getTicks(), tBox.y, (tempTexturePosition.y - tBox.y) + 1, 3000);
    tBox.x = tempTexturePosition.x;
    tBox.y = tempTexturePosition.y;
    currentTextureBoxPosition = { tBox.x, tBox.y };
}

void Graphics::setRenderFlag(bool flagValue)
{
    renderFlag = flagValue;
}

bool Graphics::getRenderFlag()
{
    return renderFlag;
}

void Graphics::update()
{
    //Vect2I entityPos = entityTransformComponent.position;
    //Vect2I entityScale = entityTransformComponent.scale;
//    mBox.x = entityPos.x;
//    mBox.y = entityPos.y;
//    mBox.h = entityScale.y;
//    mBox.w = entityScale.x;
   // this->updateTextureBox();
}

void Graphics::render()
{
    // If the element is meant to be rendered
    if (renderFlag)
    {
        SDL_RenderCopy(Game::renderer, objTexture, &tBox, &mBox);
    }
}

