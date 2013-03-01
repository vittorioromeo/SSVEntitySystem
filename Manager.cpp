// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "Manager.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include "Utils/Repository.h"
#include "Utils/Utils.h"

using namespace std;

namespace sses
{
	Manager::Manager() { entitiesToErase.set_empty_key(nullptr); }
	Manager::~Manager() { clear(); }

	void Manager::addComponent(Component* mComponent) { mComponent->manager = this; components.add(mComponent->id, mComponent); }
	void Manager::add(Entity* mEntity) { entities.add(mEntity->id, mEntity); }
	void Manager::del(Entity* mEntity) { entitiesToErase.insert(mEntity); }
	void Manager::clear()
	{
		for(auto& componentPtr : components.getItems()) delete componentPtr;
		components.clear();

		for(auto& entity : entities.getItems()) delete entity;
		entities.clear();
	}

	void Manager::update(float mFrameTime)
	{
		for(auto& entityToErase : entitiesToErase)
		{
			for(auto& componentPtr : entityToErase->getComponentRepo().getItems())
			{
				components.del(componentPtr->id, componentPtr);
				delete componentPtr;
			}

			entities.del(entityToErase->id, entityToErase);
			delete entityToErase;
		}
		entitiesToErase.clear();

		for(auto& entity : entities.getItems()) entity->update(mFrameTime);
	}
	void Manager::draw()
	{
		vector<Entity*> entitiesToSort{entities.getItems()};
		sort(begin(entitiesToSort), end(entitiesToSort), drawPrioritize);
		for(auto& entity : entitiesToSort) entity->draw();
	}

	vector<Entity*> Manager::getEntities(const string& mId) { return entities.get(mId); }
	vector<Component*> Manager::getComponents(const string& mId) { return components.get(mId); }

	Entity& Manager::createEntity(string mId, vector<Component*> mComponents) { Entity* result{new Entity(*this, mId)}; add(result); *result += mComponents; return *result; }
}
