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
#include "Entity.h"

using namespace std;

namespace sses
{
	Manager::~Manager() { clear(); }

	void Manager::addComponent(Component& mComponent) { mComponent.manager = this; components.add(mComponent.id, &mComponent); }
	void Manager::del(Entity& mEntity)
	{
		for(auto& component : mEntity.getComponentRepo()) components.del(component->getId(), component);
		entityMemoryManager.del(&mEntity);
	}
	void Manager::clear() { components.clear(); entityMemoryManager.clear(); }

	void Manager::update(float mFrameTime)
	{
		entityMemoryManager.cleanUp();
		for(auto& entity : entityMemoryManager.getItems()) entity->update(mFrameTime);
	}
	void Manager::draw()
	{
		vector<Entity*> entitiesToSort{entityMemoryManager.getItems().getItems()};
		sort(begin(entitiesToSort), end(entitiesToSort), drawPrioritize);
		for(auto& entity : entitiesToSort) entity->draw();
	}

	Entity& Manager::createEntity(const string& mId) { return entityMemoryManager.create(*this, mId); }

	vector<Entity*> Manager::getEntities(const string& mId) 		{ return entityMemoryManager.getItems().get(mId); }
	vector<Component*> Manager::getComponents(const string& mId) 	{ return components.get(mId); }
}
