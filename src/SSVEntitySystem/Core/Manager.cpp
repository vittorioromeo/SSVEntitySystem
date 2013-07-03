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
#include <SSVUtils/SSVUtils.h>

using namespace std;

namespace sses
{
	Manager::~Manager() { clear(); }

	void Manager::addComponent(Component& mComponent) { components.add(mComponent.id, &mComponent); }
	void Manager::del(Entity& mEntity)
	{
		for(const auto& c : mEntity.getComponentRepo()) components.del(c->getId(), c);
		memoryManager.del(&mEntity);
	}
	void Manager::clear() { components.clear(); memoryManager.clear(); }

	void Manager::update(float mFrameTime)
	{
		memoryManager.cleanUp();
		vector<Entity*> toUpdate{memoryManager.getItems().getItems()};
		for(const auto& e : toUpdate) e->update(mFrameTime);
	}
	void Manager::draw()
	{
		vector<Entity*> toSort{memoryManager.getItems().getItems()};
		sort(begin(toSort), end(toSort), drawPrioritize); // TODO: only sort when needed (check before->after count? add needToSort bool?)
		for(const auto& e : toSort) e->draw();
	}

	Entity& Manager::createEntity(const string& mId) { return memoryManager.create(*this, mId); }

	// Getters
	vector<Entity*>& Manager::getEntities()							{ return memoryManager.getItems().getItems(); }
	vector<Entity*>& Manager::getEntities(const string& mId) 		{ return memoryManager.getItems().get(mId); }
	vector<Component*>& Manager::getComponents(const string& mId) 	{ return components.get(mId); }
}

// TODO: transform std::string IDs in Uids like SSVSCollision!
