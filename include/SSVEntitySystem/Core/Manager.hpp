// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER
#define SSES_MANAGER

#include "SSVEntitySystem/Global/Typedefs.hpp"
#include "SSVEntitySystem/Core/Entity.hpp"
#include "SSVEntitySystem/Core/Internal/EntityIdManager.hpp"

namespace sses
{
	class Manager : ssvu::NoCopy
	{
		friend class Entity;
		friend class Component;

		private:
			Internal::EntityIdManager entityIdManager;
			ssvu::MemoryManager<Entity> entities;
			std::vector<Entity*> toSort;
			std::array<std::vector<Entity*>, maxGroups> groupedEntities;

			inline void addToGroup(Entity* mEntity, Group mGroup)	{ groupedEntities[mGroup].emplace_back(mEntity); }
			inline void del(Entity& mEntity) noexcept				{ entities.del(mEntity); }

		public:
			inline void clear() noexcept { entities.clear(); for(auto& v : groupedEntities) v.clear(); }
			inline void refresh();
			inline void update(FT mFT);
			inline void draw();

			inline Entity& createEntity() { return entities.create(entityIdManager.getFreeStat(), *this); }

			inline decltype(entities)& getEntities() noexcept				{ return entities; }
			inline std::vector<Entity*>& getEntities(Group mGroup) noexcept	{ return groupedEntities[mGroup]; }

			inline bool hasEntity(Group mGroup)								{ return !groupedEntities[mGroup].empty(); }
			inline std::size_t getEntityCount(Group mGroup) const noexcept	{ return groupedEntities[mGroup].size(); }
			inline bool isAlive(const EntityStat& mStat) const noexcept		{ return entityIdManager.isAlive(mStat); }
	};
}

#endif
