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
	void Manager::clear() { groupedEntities.clear(); entities.clear(); }

	void Manager::update(float mFrameTime)
	{
		for(auto& p : groupedEntities)
		{
			vector<Entity*>& groupVector(groupedEntities[p.first]);
			auto itr(remove_if(begin(groupVector), end(groupVector), [](const Entity* mEntity){ return !mEntity->alive; }));
			groupVector.erase(itr, end(groupVector));
		}

		auto itr(remove_if(begin(entities), end(entities), [](const unique_ptr<Entity>& mEntity){ return !mEntity->alive; }));
		entities.erase(itr, end(entities));

		for(const auto& e : entities) e->update(mFrameTime);

		for(const auto& e : toAdd)
		{
			entities.push_back(unique_ptr<Entity>(e));
			groupedEntities[e->getId()].push_back(e);
		}

		toAdd.clear();
	}
	void Manager::draw()
	{
		toSort.clear();
		for(const auto& e : entities) toSort.push_back(e.get());
		sort(begin(toSort), end(toSort), [](const Entity* mA, const Entity* mB){ return mA->getDrawPriority() > mB->getDrawPriority(); });
		for(const auto& e : toSort) e->draw();
	}

	Entity& Manager::createEntity(const string& mId)
	{
		auto result(new Entity{*this, mId});
		toAdd.push_back(result);
		//entities.push_back(unique_ptr<Entity>(result));
		//groupedEntities[mId].push_back(result);
		return *result;
	}
}

// TODO: transform std::string IDs in Uids like SSVSCollision!
