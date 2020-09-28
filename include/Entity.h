#pragma once
#include "Component.h"
#include "SDL.h"
#include "ECS.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

class Entity
{
private:
	
	ComponentList compList;
	ComponentBitset compBitset;
	std::vector<std::unique_ptr<Component>> components;
	bool active;

public:

	Entity() = default;
	~Entity() = default;

	template <typename T, typename... TArgs>
	inline T& addComponent(TArgs&&... args)
	{
		// Create new component with the supplied args
		T* comp(new T(std::forward<TArgs>(args)...));\

		std::unique_ptr<Component> uptr { comp };

		// Add the pointer to vec of components
		components.emplace_back(std::move(uptr));

		// assign the owner
		comp->entity = this;

		if (comp->init())
		{
			compList[getComponentTypeID<T>()] = comp;
			compBitset[getComponentTypeID<T>()] = comp;

			return *comp;
		}

		// Return nullptr if fails
		return *static_cast<T*>(nullptr);
	}


	template<typename T>
	inline T& getComponent() const
	{
		auto ptr = compList[getComponentTypeID<T>()];
		return *static_cast<T*>(ptr);
	}

	virtual void triggerEvent(int eventType) = 0;

	inline bool isActive() const
	{
		return active;
	}

	inline void destroy()
	{
		active = false;
	}

	inline void render()
	{
		for (auto& comp : components)
			comp->render();
	}

	inline void update()
	{
		for (auto& comp : components)
			comp->update();
	}
};