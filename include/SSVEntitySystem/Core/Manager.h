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
			std::unordered_map<std::string, std::vector<Entity*>> groupedEntities;

			void del(Entity& mEntity);

		public:
			Manager() = default;
			Manager(const Manager&) = delete; // non construction-copyable
			Manager& operator=(const Manager&) = delete; // non copyable

			inline void clear() { memoryManager.clear(); groupedEntities.clear(); }
			void update(float mFrameTime);
			void draw();

			Entity& createEntity(const std::string& mId = "");

			// Getters
			inline ssvu::MemoryManager<Entity>::Container& getEntities()		{ return memoryManager.getItems(); }
			inline std::vector<Entity*>& getEntities(const std::string& mId)	{ return groupedEntities[mId]; }
			inline bool hasEntity(const std::string& mId)						{ return groupedEntities[mId].size() > 0; }
			inline unsigned int getEntityCount(const std::string& mId)			{ return groupedEntities[mId].size(); }
	};
}

#endif
