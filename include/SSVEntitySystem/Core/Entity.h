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
			GroupBitset groups;
			std::vector<Uptr<Component>> components;
			std::array<Component*, maxComponents> componentPtrs;
			TypeIdsBitset typeIdsBitset;
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

			template<typename T> inline bool hasComponent() const noexcept	{ return typeIdsBitset[getTypeIdBitIdx<T>()]; }
			template<typename T> inline T& getComponent() noexcept			{ assert(hasComponent<T>()); return reinterpret_cast<T&>(*componentPtrs[getTypeIdBitIdx<T>()]); }
			template<typename T, typename... TArgs> inline T& createComponent(TArgs&&... mArgs)
			{
				assert(!hasComponent<T>());
				auto result(new T{std::forward<TArgs>(mArgs)...});
				result->entity = this; Internal::callInit(*result);
				componentPtrs[getTypeIdBitIdx<T>()] = result;
				typeIdsBitset[getTypeIdBitIdx<T>()] = true;
				components.emplace_back(result);
				return *result;
			}

			// Groups
			inline void setGroups(bool mOn, Group mGroup) noexcept { groups[mGroup] = mOn; if(mOn) manager.addToGroup(this, mGroup); }
			inline void addGroups(Group mGroup) noexcept { groups[mGroup] = true; manager.addToGroup(this, mGroup); }
			inline void delGroups(Group mGroup) noexcept { groups[mGroup] = false; }
			inline void clearGroups() noexcept { groups.reset(); }
			template<typename... TGroups> inline void setGroups(bool mOn, Group mGroup, TGroups... mGroups) noexcept { setGroups(mOn, mGroup); setGroups(mOn, mGroups...); }
			template<typename... TGroups> inline void addGroups(Group mGroup, TGroups... mGroups) noexcept	{ addGroups(mGroup); addGroups(mGroups...); }
			template<typename... TGroups> inline void delGroups(Group mGroup, TGroups... mGroups) noexcept	{ delGroups(mGroup); delGroups(mGroups...); }
			inline bool hasGroup(Group mGroup) const noexcept												{ return groups[mGroup]; }
			inline bool hasAnyGroup(const GroupBitset& mGroups) const noexcept								{ return (groups & mGroups).any(); }
			inline bool hasAllGroups(const GroupBitset& mGroups) const noexcept								{ return (groups & mGroups).all(); }
			inline const GroupBitset& getGroups() const noexcept											{ return groups; }
	};
}

#endif
