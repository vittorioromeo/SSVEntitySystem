// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER_INL
#define SSES_MANAGER_INL

namespace sses
{
	inline void Manager::update(float mFT)
	{
		for(auto& v : groupedEntities) ssvu::eraseRemoveIf(v, &entities.isDead<Entity*>);
		entities.refresh();
		for(const auto& e : entities) e->update(mFT);
	}
	inline void Manager::draw()
	{
		toSort.clear();
		for(const auto& e : entities) toSort.push_back(e.get());
		ssvu::sortStable(toSort, [](const Entity* mA, const Entity* mB){ return mA->getDrawPriority() > mB->getDrawPriority(); });
		for(const auto& e : toSort) e->draw();
	}
}

#endif
