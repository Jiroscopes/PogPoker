#pragma once
#include "Scene.h"
#include <memory>
#include <unordered_map>

class SceneStateMachine
{
private:
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene = nullptr;
    unsigned int insertedSceneID;	// Gets incremented with each new scene
public:
    SceneStateMachine();

    // Pass-through functions, these call the scenes corresponding functions
    //void processInput();
    //void update();
    void render();

    unsigned int addScene(std::shared_ptr<Scene> scene);
    void switchToScene(unsigned int id);
    void removeScene(unsigned int id);
};