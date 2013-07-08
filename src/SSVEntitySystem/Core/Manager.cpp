// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include <algorithm>
#include "SSVEntitySystem/Core/Manager.h"
#include "SSVEntitySystem/Core/Entity.h"

using namespace std;

namespace sses
{
	bool EntityDeleter::operator()(const Uptr<Entity>& mEntity) const { return !mEntity->isAlive(); }

	void Manager::clear() { memoryManager.clear(); groupedEntities.clear(); }

	void Manager::update(float mFrameTime)
	{
		for(auto& p : groupedEntities)
		{
			auto& vec(groupedEntities[p.first]);
			vec.erase(remove_if(begin(vec), end(vec), [](const Entity* mEntity){ return !mEntity->isAlive(); }), end(vec));
		}

		memoryManager.cleanUp();
		for(const auto& e : memoryManager) e->update(mFrameTime);
		memoryManager.populate();
	}
	void Manager::draw()
	{
		toSort.clear();
		for(const auto& e : memoryManager) toSort.push_back(e.get());
		sort(begin(toSort), end(toSort), [](const Entity* mA, const Entity* mB){ return mA->getDrawPriority() > mB->getDrawPriority(); });
		for(const auto& e : toSort) e->draw();
	}

	Entity& Manager::createEntity(const string& mId) { auto& result(memoryManager.create(*this, mId)); groupedEntities[mId].push_back(&result); return result; }
}

// TODO: transform std::string IDs in Uids like SSVSCollision!
