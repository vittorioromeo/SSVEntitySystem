// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_INTERNAL_ENTITYIDMANAGER
#define SSES_INTERNAL_ENTITYIDMANAGER

#include "SSVEntitySystem/Global/Typedefs.hpp"

namespace sses
{
	namespace Internal
	{
		class EntityIdManager
		{
			private:
				std::vector<EntityId> freeIds;
				std::array<EntityIdUse, maxEntities> entityIdUses;

			public:
				inline EntityIdManager() : freeIds(maxEntities)
				{
					std::iota(std::begin(freeIds), std::end(freeIds), 0);
					std::fill(std::begin(entityIdUses), std::end(entityIdUses), 0);
				}

				inline EntityStat getFreeStat()	{ EntityId id{freeIds.back()}; freeIds.pop_back(); return {id, entityIdUses[id]}; }
				inline bool isAlive(const EntityStat& mStat) const noexcept { return entityIdUses[mStat.first] == mStat.second; }
				inline void reclaim(const EntityStat& mStat) { freeIds.push_back(mStat.first); ++entityIdUses[mStat.first]; }
		};
	}
}

#endif
