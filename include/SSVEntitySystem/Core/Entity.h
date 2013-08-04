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

	class Entity : public ssvu::MemoryManageable
	{
		private:
			Manager& manager;
			Bitset groups;
			std::vector<Uptr<Component>> components;
			int drawPriority{0};

		public:
			Entity(Manager& mManager) : manager(mManager) { }
			Entity(const Entity&) = delete; // non construction-copyable
			Entity& operator=(const Entity&) = delete; // non copyable

			inline void addGroup(Group mGroup)								{ groups.set(mGroup); manager.addToGroup(this, mGroup); }
			inline void delGroup(Group mGroup)								{ groups.set(mGroup, false); manager.delFromGroup(this, mGroup); }
			inline void clearGroups()										{ for(Group i{0}; i < groups.size(); ++i) if(groups.test(i)) manager.delFromGroup(this, i); groups.reset(); }
			inline bool hasGroup(Group mGroup) const						{ return groups.test(mGroup); }
			inline const Bitset& getGroups() const							{ return groups; }
			inline void addGroups(const std::vector<std::string>& mLabels)	{ for(const auto& l : mLabels) addGroup(manager.getGroup(l)); }

			inline void update(float mFrameTime)	{ for(const auto& c : components) c->update(mFrameTime); }
			inline void draw()						{ for(const auto& c : components) c->draw(); }
			inline void destroy()					{ manager.del(*this); }

			inline void setDrawPriority(int mDrawPriority)			{ drawPriority = mDrawPriority; }

			inline Manager& getManager() const						{ return manager; }
			inline int getDrawPriority() const						{ return drawPriority; }
			inline std::vector<Uptr<Component>>& getComponents()	{ return components; }

			template<typename T> inline T* getComponentSafe() const				{ for(const auto& c : components) if(getTypeId<T>() == c->getId()) return static_cast<T*>(c.get()); return nullptr; }
			template<typename T> inline T& getComponent() const					{ return *getComponentSafe<T>(); }
			template<typename T> inline unsigned int getComponentCount() const	{ unsigned int result{0}; for(const auto& c : components) if(getTypeId<T>() == c->getId()) ++result; return result; }
			template<typename T> inline bool hasComponent() const				{ return getComponentCount<T>() > 0; }
			template<typename T, typename... TArgs> inline T& createComponent(TArgs&&... mArgs)
			{
				auto result(new T{std::forward<TArgs>(mArgs)...});
				result->entity = this;
				result->id = getTypeId<T>();
				result->init();
				components.push_back(Uptr<Component>(result));
				return *result;
			}
	};
}

#endif
