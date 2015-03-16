// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_INTERNAL_ENTITYIDMANAGER
#define SSES_INTERNAL_ENTITYIDMANAGER

namespace sses
{
	namespace Impl
	{
		class EntityIdManager
		{
			private:
				std::vector<EntityId> freeIds;
				std::array<EntityIdCtr, maxEntities> idCtrs;

			public:
				inline EntityIdManager() : freeIds(maxEntities)
				{
					ssvu::iota(freeIds, 0);
					ssvu::fill(idCtrs, 0);
				}

				inline auto getFreeStat() { EntityId id{freeIds.back()}; freeIds.pop_back(); return EntityStat{id, idCtrs[id]}; }
				inline bool isAlive(const EntityStat& mStat) const noexcept { return idCtrs[mStat.id] == mStat.ctr; }
				inline void reclaim(const EntityStat& mStat) { freeIds.emplace_back(mStat.id); ++idCtrs[mStat.id]; }
		};
	}
}

#endif
