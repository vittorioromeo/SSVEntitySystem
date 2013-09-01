// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_INTERNAL_ENTITYIDMANAGER
#define SSES_INTERNAL_ENTITYIDMANAGER

#include "SSVEntitySystem/Global/Typedefs.h"
#include "SSVEntitySystem/Core/Entity.h"

namespace sses
{
	namespace Internal
	{
		class EntityIdManager
		{
			private:
				EntityId lastEntityId{0};
				std::stack<EntityId, std::vector<EntityId>> freeIds;
				std::vector<EntityIdUse> entityIdUses;

			public:
				EntityIdManager() { entityIdUses.resize(getMaxEntities(), 0); }

				inline EntityStat getFreeStat()
				{
					EntityId id;

					if(freeIds.empty())
					{
						assert(lastEntityId < getMaxEntities());
						id = lastEntityId++;
					}
					else { id = freeIds.top(); freeIds.pop(); }

					return {id, entityIdUses[id]};
				}
				inline bool isAlive(const EntityStat& mStat) const { return entityIdUses[mStat.first] == mStat.second; }
				inline void reclaim(const EntityStat& mStat) { freeIds.push(mStat.first); ++entityIdUses[mStat.first]; }
		};
	}
}

#endif
