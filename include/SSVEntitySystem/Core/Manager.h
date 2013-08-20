// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER
#define SSES_MANAGER

#include "SSVEntitySystem/Global/Typedefs.h"
#include "SSVEntitySystem/Core/Entity.h"

namespace sses
{
	class Manager
	{
		friend class Entity;
		friend class Component;

		private:
			ssvu::MemoryManager<Entity> entities;
			std::vector<Entity*> toSort;
			std::unordered_map<Group, std::vector<Entity*>> groupedEntities; // TODO: is this necessary now? Run some benchmarks

			inline void addToGroup(Entity* mEntity, Group mGroup)	{ groupedEntities[mGroup].push_back(mEntity); }
			inline void delFromGroup(Entity* mEntity, Group mGroup)	{ ssvu::eraseRemove(groupedEntities[mGroup], mEntity); }
			inline void del(Entity& mEntity)						{ entities.del(mEntity); }

		public:
			Manager() = default;
			Manager(const Manager&) = delete; // non construction-copyable
			Manager& operator=(const Manager&) = delete; // non copyable

			inline void clear() { entities.clear(); groupedEntities.clear(); }
			inline void update(float mFrameTime);
			inline void draw();

			inline Entity& createEntity() { return entities.create(*this); }

			inline decltype(entities)::Container& getEntities()		{ return entities.getItems(); }
			inline std::vector<Entity*>& getEntities(Group mGroup)	{ return groupedEntities[mGroup]; }
			inline bool hasEntity(Group mGroup) 					{ return !groupedEntities[mGroup].empty(); }
			inline std::size_t getEntityCount(Group mGroup)			{ return groupedEntities[mGroup].size(); }
	};
}

#endif
