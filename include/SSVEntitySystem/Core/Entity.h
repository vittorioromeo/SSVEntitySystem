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
			std::string id;
			int drawPriority{0};
			ssvu::MemoryManager<Component, Repository<Component*, std::size_t>, google::dense_hash_set<Component*>> memoryManager;

		public:
			Entity(Manager& mManager, const std::string& mId = "");
			Entity(const Entity&) = delete; // non construction-copyable
			Entity& operator=(const Entity&) = delete; // non copyable

			void update(float);
			void draw();
			void destroy();

			// Setters
			inline void setDrawPriority(int mDrawPriority)					{ drawPriority = mDrawPriority; }

			// Getters
			inline Manager& getManager() const								{ return manager; }
			inline const std::string& getId() const							{ return id; }
			inline int getDrawPriority() const								{ return drawPriority; }
			inline std::vector<Component*>& getComponents()					{ return memoryManager.getItems().getItems(); }
			inline Repository<Component*, std::size_t>& getComponentRepo()	{ return memoryManager.getItems(); }

			template<typename T, typename... TArgs> T& createComponent(TArgs&&... mArgs)
			{
				T& result(*(new T(std::forward<TArgs>(mArgs)...)));
				result.entity = this; result.id = Component::getHash<T>();
				memoryManager.adopt<T>(result);
				manager.addComponent(result); result.init(); ssvu::log(ssvu::toStr(getComponents<T>().size())); return result;
			}
			template<typename T> std::vector<T*> getComponents()	{ return memoryManager.getItems().getCasted<T*>(Component::getHash<T>()); }
			template<typename T> T& getFirstComponent()				{ return *(memoryManager.getItems().getCasted<T*>(Component::getHash<T>())[0]); }
			template<typename T> T* getFirstComponentSafe()
			{
				const auto& components(memoryManager.getItems().getCasted<T*>(Component::getHash<T>()));
				return components.empty() ? nullptr : components[0];
			}
	};
}

#endif
