// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_ENTITY
#define SSES_ENTITY

#include <vector>
#include <string>
#include "SSVEntitySystem/Utils/Utils.h"
#include "SSVEntitySystem/Utils/Repository.h"
#include "SSVEntitySystem/Core/Manager.h"

namespace sses
{
	class Component;
	
	class Entity
	{
		friend class Manager;

		private:
			Manager& manager;
			std::string id{""};
			int drawPriority{0};
			ssvu::MemoryManager<Component, Repository<Component*>, google::dense_hash_set<Component*>> memoryManager;
		
		public:
			Entity(Manager& mManager, const std::string& mId = "");
			Entity(const Entity&) = delete; // non construction-copyable
			Entity& operator=(const Entity&) = delete; // non copyable

			void update(float);
			void draw();
			void destroy();

			void setDrawPriority(int mDrawPriority);

			Manager& getManager();
			std::string getId();
			int getDrawPriority() const;
			std::vector<Component*>& getComponents();
			Repository<Component*>& getComponentRepo();

			template<typename T, typename... TArgs> T& createComponent(TArgs&&... mArgs)
			{
				T& result(memoryManager.create<T, Entity&, TArgs...>(*this, std::forward<TArgs>(mArgs)...));
				manager.addComponent(result); return result;
			}
			template<typename T> std::vector<T*> getComponents(const std::string& mId) { return memoryManager.getItems().getCasted<T*>(mId); }
	};
}
	
#endif
