#include "SceneStateMachine.h"
#include <iostream>

SceneStateMachine::SceneStateMachine() : scenes(0) {}

//void SceneStateMachine::processInput()
//{
//	if (currentScene)
//	{
//		currentScene->processInput();
//	}
//}

//void SceneStateMachine::update()
//{
//	if (currentScene)
//	{
//		currentScene->update();
//	}
//}

void SceneStateMachine::render()
{
    if (currentScene)
    {
        currentScene->renderMap();
    }
    else
    {
        fprintf(stderr, "No current scene\n");
    }
}

unsigned int SceneStateMachine::addScene(std::shared_ptr<Scene> scene)
{
    auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene)); // this returns std::pair<iter, bool>

    inserted.first->second->onCreate(); // gets the iterator, then we get <sceneID, scene> and we want scene, hence ->second

    return insertedSceneID++;
}

void SceneStateMachine::removeScene(unsigned int id)
{
    auto it = scenes.find(id);

    if (it != scenes.end())
    {
        if (currentScene)
        {
            // If the scene we are removing is the current scene,
            // we also want to set that to a null pointer so the scene
            // is no longer updated.
            currentScene = nullptr;
        }

        it->second->onDestroy();

        scenes.erase(it);
    }
}

void SceneStateMachine::switchToScene(unsigned int id)
{
    auto it = scenes.find(id);
    if (it != scenes.end())
    {
        if (currentScene)
        {
            // If we have a current scene, we call its OnDeactivate method.
            currentScene->onDeactivate();
            std::cout << "Deactivated current scene" << std::endl;
        }

        // Setting the current scene ensures that it is updated and drawn.
        currentScene = it->second;

        currentScene->onActivate();
    }
}


