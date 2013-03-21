// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include "SSVEntitySystem/Core/Manager.h"
#include "SSVEntitySystem/Utils/Repository.h"
#include "SSVEntitySystem/Utils/Utils.h"
#include "SSVEntitySystem/Core/Entity.h"

using namespace std;

namespace sses
{
	Manager::~Manager() { clear(); }

	void Manager::addComponent(Component& mComponent) { components.add(mComponent.id, &mComponent); }
	void Manager::del(Entity& mEntity)
	{
		for(auto& component : mEntity.getComponentRepo()) components.del(component->getId(), component);
		memoryManager.del(&mEntity);
	}
	void Manager::clear() { components.clear(); memoryManager.clear(); }

	void Manager::update(float mFrameTime)
	{
		memoryManager.cleanUp();
		for(auto& entity : memoryManager.getItems()) entity->update(mFrameTime);
	}
	void Manager::draw()
	{
		vector<Entity*> entitiesToSort{memoryManager.getItems().getItems()};
		sort(begin(entitiesToSort), end(entitiesToSort), drawPrioritize);
		for(auto& entity : entitiesToSort) entity->draw();
	}

	Entity& Manager::createEntity(const string& mId) { return memoryManager.create(*this, mId); }

	vector<Entity*> Manager::getEntities(const string& mId) 		{ return memoryManager.getItems().get(mId); }
	vector<Component*> Manager::getComponents(const string& mId) 	{ return components.get(mId); }
}
