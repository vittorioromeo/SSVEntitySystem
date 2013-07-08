// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_ENTITY
#define SSES_ENTITY

#include <vector>
#include <string>
#include "SSVEntitySystem/Core/Manager.h"
#include "SSVEntitySystem/Core/Component.h"
#include "SSVEntitySystem/Global/Typedefs.h"

namespace sses
{
	class Component;

	class Entity
	{
		private:
			Manager& manager;
			std::string id;
			std::vector<Uptr<Component>> components;
			int drawPriority{0};
			bool alive{true};

		public:
			Entity(Manager& mManager, const std::string& mId = "") : manager(mManager), id{mId} { }
			Entity(const Entity&) = delete; // non construction-copyable
			Entity& operator=(const Entity&) = delete; // non copyable

			inline void update(float mFrameTime)	{ for(const auto& c : components) c->update(mFrameTime); }
			inline void draw()						{ for(const auto& c : components) c->draw(); }
			inline void destroy()					{ alive = false; }

			inline void setDrawPriority(int mDrawPriority)			{ drawPriority = mDrawPriority; }

			inline bool isAlive() const								{ return alive; }
			inline Manager& getManager() const						{ return manager; }
			inline const std::string& getId() const					{ return id; }
			inline int getDrawPriority() const						{ return drawPriority; }
			inline std::vector<Uptr<Component>>& getComponents()	{ return components; }

			template<typename T> inline T* getComponentSafe() const				{ for(const auto& c : components) if(getTypeId<T>() == c->getId()) return static_cast<T*>(c.get()); return nullptr; }
			template<typename T> inline T& getComponent() const					{ return *getComponentSafe<T>(); }
			template<typename T> inline unsigned int getComponentCount() const	{ unsigned int result{0}; for(const auto& c : components) if(getTypeId<T>() == c->getId()) ++result; return result; }
			template<typename T> inline bool hasComponent() const				{ return getComponentCount<T>() > 0; }
			template<typename T, typename... TArgs> T& createComponent(TArgs&&... mArgs)
			{
				auto result(new T(std::forward<TArgs>(mArgs)...));
				result->entity = this;
				result->id = getTypeId<T>();
				result->init();
				components.push_back(Uptr<Component>(result));
				return *result;
			}
	};
}

#endif
