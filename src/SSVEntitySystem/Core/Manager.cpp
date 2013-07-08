// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include <algorithm>
#include "SSVEntitySystem/Core/Manager.h"
#include "SSVEntitySystem/Core/Entity.h"

using namespace std;

namespace sses
{
	void Manager::clear() { groupedEntities.clear(); entities.clear(); }

	void Manager::update(float mFrameTime)
	{
		for(auto& p : groupedEntities)
		{
			auto& vec(groupedEntities[p.first]);
			vec.erase(remove_if(begin(vec), end(vec), [](const Entity* mEntity){ return !mEntity->alive; }), end(vec));
		}
		entities.erase(remove_if(begin(entities), end(entities), [](const Uptr<Entity>& mEntity){ return !mEntity->alive; }), end(entities));

		for(const auto& e : entities) e->update(mFrameTime);

		for(const auto& e : toAdd) { entities.push_back(Uptr<Entity>(e)); groupedEntities[e->getId()].push_back(e); }
		toAdd.clear();
	}
	void Manager::draw()
	{
		toSort.clear();
		for(const auto& e : entities) toSort.push_back(e.get());
		sort(begin(toSort), end(toSort), [](const Entity* mA, const Entity* mB){ return mA->getDrawPriority() > mB->getDrawPriority(); });
		for(const auto& e : toSort) e->draw();
	}

	Entity& Manager::createEntity(const string& mId) { auto result(new Entity{*this, mId}); toAdd.push_back(result); return *result; }
}

// TODO: transform std::string IDs in Uids like SSVSCollision!
