// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER_INL
#define SSES_MANAGER_INL

namespace sses
{
	inline void Manager::refresh()
	{
		for(auto i(0u); i < maxGroups; ++i) ssvu::eraseRemoveIf(groupedEntities[i], [i](const Entity* mEntity){ return ssvu::MemoryManager<Entity>::isDead(mEntity) || !mEntity->hasGroup(i); });
		entities.refresh();
	}
	inline void Manager::update(FT mFT)
	{
		refresh();
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
