// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER
#define SSES_MANAGER

#include <string>
#include <vector>
#include <unordered_map>
#include <SSVUtils/SSVUtils.h>
#include "SSVEntitySystem/Global/Typedefs.h"
#include "SSVEntitySystem/Global/GroupManager.h"

namespace sses
{
	class Entity;

	class Manager
	{
		friend class Entity;
		friend class Component;

		private:
			ssvu::MemoryManager<Entity> memoryManager;
			std::vector<Entity*> toSort;
			GroupManager groupManager;
			std::unordered_map<Group, std::vector<Entity*>> groupedEntities; // TODO: is this necessary now? Run some benchmarks

			inline void addToGroup(Entity* mEntity, Group mGroup)	{ groupedEntities[mGroup].push_back(mEntity); }
			inline void delFromGroup(Entity* mEntity, Group mGroup)	{ ssvu::eraseRemove(groupedEntities[mGroup], mEntity); }
			inline void del(Entity& mEntity)						{ memoryManager.del(mEntity); }

		public:
			Manager() = default;
			Manager(const Manager&) = delete; // non construction-copyable
			Manager& operator=(const Manager&) = delete; // non copyable

			inline void clear() { memoryManager.clear(); groupedEntities.clear(); }
			void update(float mFrameTime);
			void draw();

			inline Entity& createEntity() { return memoryManager.create(*this); }

			// Getters
			inline Group getGroup(const std::string& mLabel)				{ return groupManager.get(mLabel); }
			inline ssvu::MemoryManager<Entity>::Container& getEntities()	{ return memoryManager.getItems(); }
			inline std::vector<Entity*>& getEntities(Group mGroup)			{ return groupedEntities[mGroup]; }
			inline bool hasEntity(Group mGroup) 							{ return !groupedEntities[mGroup].empty(); }
			inline unsigned int getEntityCount(Group mGroup)				{ return groupedEntities[mGroup].size(); }
	};
}

#endif
