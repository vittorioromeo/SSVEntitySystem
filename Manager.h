// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER
#define SSES_MANAGER

#include <string>
#include <vector>
#include <google/dense_hash_set>
#include <SSVStart.h>
#include "Component.h"
#include "Utils/Repository.h"

namespace sses
{
	class Entity;

	class Manager
	{
		friend class Entity;
		friend class Component;

		private:
			ssvs::Utils::MemoryManager<Entity, Repository<Entity*>, google::dense_hash_set<Entity*>> memoryManager;
			Repository<Component*> components; // not owned

			void del(Entity& mEntity);
			void addComponent(Component& mComponent);

		public:
			Manager() = default;
			~Manager();
			Manager(const Manager&) = delete; // non construction-copyable
			Manager& operator=(const Manager&) = delete; // non copyable
			
			void clear();
			void update(float mFrameTime);
			void draw();

			Entity& createEntity(const std::string& mId = "");

			std::vector<Entity*> getEntities(const std::string& mId);
			std::vector<Component*> getComponents(const std::string& mId);
			template<typename T> std::vector<T*> getComponents(const std::string& mId) { return components.getCasted<T*>(mId); }
	};
}

#endif
