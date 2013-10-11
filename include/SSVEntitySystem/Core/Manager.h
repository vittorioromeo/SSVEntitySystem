// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER
#define SSES_MANAGER

#include "SSVEntitySystem/Global/Typedefs.h"
#include "SSVEntitySystem/Core/Entity.h"
#include "SSVEntitySystem/Core/Internal/EntityIdManager.h"

namespace sses
{
	class Manager
	{
		friend class Entity;
		friend class Component;

		private:
			Internal::EntityIdManager entityIdManager;
			ssvu::MemoryManager<Entity> entities;
			std::vector<Entity*> toSort;
			std::array<std::vector<Entity*>, maxGroups> groupedEntities;

			inline void addToGroup(Entity* mEntity, Group mGroup)	{ groupedEntities[mGroup].push_back(mEntity); }
			inline void delFromGroup(Entity* mEntity, Group mGroup)	{ ssvu::eraseRemove(groupedEntities[mGroup], mEntity); }
			inline void del(Entity& mEntity) noexcept				{ entities.del(mEntity); }

		public:
			Manager() = default;
			Manager(const Manager&) = delete; // non construction-copyable
			Manager& operator=(const Manager&) = delete; // non copyable

			inline void clear() { entities.clear(); for(auto& v : groupedEntities) v.clear(); }
			inline void update(float mFT);
			inline void draw();

			inline Entity& createEntity() { return entities.create(entityIdManager.getFreeStat(), *this); }

			inline decltype(entities)::Container& getEntities()	noexcept	{ return entities.getItems(); }
			inline std::vector<Entity*>& getEntities(Group mGroup) noexcept	{ return groupedEntities[mGroup]; }

			inline bool hasEntity(Group mGroup)								{ return !groupedEntities[mGroup].empty(); }
			inline std::size_t getEntityCount(Group mGroup) const noexcept	{ return groupedEntities[mGroup].size(); }
			inline bool isAlive(const EntityStat& mStat) const noexcept		{ return entityIdManager.isAlive(mStat); }
	};
}

#endif
