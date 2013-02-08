// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include <string>
#include <vector>
#include <map>
#include <sparsehash/dense_hash_set>
#include "Entity.h"
#include "Component.h"
#include "Repository.h"

namespace sses
{
	class Manager
	{
		friend class Entity;
		friend class Component;

		private:
			Repository<Entity*> entities; // owned!
			Repository<Component*> components; // owned!
			google::dense_hash_set<Entity*> entitiesToErase; // not owned

			void add(Entity* mEntity);
			void del(Entity* mEntity);
			void addComponent(Component* mComponent);

		public:
			Manager();
			Manager(const Manager&) = delete; // non construction-copyable
			Manager& operator=(const Manager&) = delete; // non copyable
			~Manager();
			
			void clear();
			void update(float mFrameTime);
			void draw();

			std::vector<Entity*> getEntities(const std::string& mId);
			std::vector<Component*> getComponents(const std::string& mId);
			template<typename T> std::vector<T*> getComponents(const std::string& mId) { return components.getCasted<T*>(mId); }

			Entity* createEntity(std::string mId = "", std::vector<Component*> mComponents = {});
			template<typename T, typename... Args> T* createComponent(Args&&... args) { return new T(std::forward<Args>(args)...); }
	};
} /* namespace sses */
#endif /* ENTITYMANAGER_H_ */
