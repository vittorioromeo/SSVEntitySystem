// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_ENTITY
#define SSES_ENTITY

#include "SSVEntitySystem/Core/Manager.h"
#include "SSVEntitySystem/Core/Component.h"
#include "SSVEntitySystem/Global/Typedefs.h"

namespace sses
{
	class Entity : public ssvu::MemoryManageable
	{
		private:
			EntityStat stat;
			Manager& manager;
			Bitset groups;
			std::vector<Uptr<Component>> components;
			int drawPriority{0};

		public:
			Entity(const EntityStat& mStat, Manager& mManager) noexcept : stat{mStat}, manager(mManager) { }
			Entity(const Entity&) = delete; // non construction-copyable
			Entity& operator=(const Entity&) = delete; // non copyable

			inline ~Entity() { manager.entityIdManager.reclaim(stat); }

			inline void update(float mFT)	{ for(const auto& c : components) c->update(mFT); }
			inline void draw()				{ for(const auto& c : components) c->draw(); }
			inline void destroy() noexcept	{ manager.del(*this); }

			inline void setDrawPriority(int mDrawPriority)	{ drawPriority = mDrawPriority; }

			inline const EntityStat& getStat() const noexcept		{ return stat; }
			inline Manager& getManager() const noexcept				{ return manager; }
			inline int getDrawPriority() const noexcept				{ return drawPriority; }
			inline decltype(components)& getComponents() noexcept	{ return components; }

			template<typename T> inline T* getComponentSafe() const				{ for(const auto& c : components) if(getTypeId<T>() == c->getComponentTypeId()) return static_cast<T*>(c.get()); return nullptr; }
			template<typename T> inline T& getComponent() const					{ return *getComponentSafe<T>(); }
			template<typename T> inline std::size_t getComponentCount() const	{ std::size_t result{0}; for(const auto& c : components) if(getTypeId<T>() == c->getComponentTypeId()) ++result; return result; }
			template<typename T> inline bool hasComponent() const				{ for(const auto& c : components) if(getTypeId<T>() == c->getComponentTypeId()) return true; return false;  }
			template<typename T, typename... TArgs> inline T& createComponent(TArgs&&... mArgs)
			{
				auto result(new T{std::forward<TArgs>(mArgs)...});
				result->entity = this;
				result->componentTypeId = getTypeId<T>();
				result->init();
				components.emplace_back(result);
				return *result;
			}

			// Groups
			inline void addGroups(Group mGroup)	noexcept													{ groups[mGroup] = true; manager.addToGroup(this, mGroup); }
			inline void delGroups(Group mGroup)	noexcept													{ groups[mGroup] = false; manager.delFromGroup(this, mGroup); }
			template<typename... TGroups> inline void addGroups(Group mGroup, TGroups... mGroups) noexcept	{ groups[mGroup] = true; manager.addToGroup(this, mGroup); addGroups(mGroups...); }
			template<typename... TGroups> inline void delGroups(Group mGroup, TGroups... mGroups) noexcept	{ groups[mGroup] = false; manager.delFromGroup(this, mGroup); delGroups(mGroups...); }
			inline void addGroup(Group mGroup) noexcept														{ addGroups(mGroup); }
			inline void delGroup(Group mGroup) noexcept														{ delGroups(mGroup); }
			inline bool hasGroup(Group mGroup) const noexcept												{ return groups[mGroup]; }
			inline bool hasAnyGroup(const Bitset& mGroups) const noexcept									{ return (groups & mGroups).any(); }
			inline void clearGroups() noexcept																{ for(Group i{0}; i < groups.size(); ++i) if(groups[i]) manager.delFromGroup(this, i); groups.reset(); }
			inline const Bitset& getGroups() const noexcept													{ return groups; }
	};
}

#endif
