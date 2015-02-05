// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_ENTITY
#define SSES_ENTITY

namespace sses
{
	class Entity
	{
		friend Manager;

		private:
			EntityStat stat;
			Manager& manager;
			GroupBitset groups;
			std::vector<ComponentRecyclerPtr> components;
			std::array<Component*, maxComponents> componentPtrs;
			TypeIdxBitset typeIdsBitset;
			int drawPriority{0};

			inline void update(FT mFT)	{ for(const auto& c : components) c->update(mFT); }
			inline void draw()			{ for(const auto& c : components) c->draw(); }

		public:
			inline Entity(const EntityStat& mStat, Manager& mManager) noexcept : stat(mStat), manager(mManager) { }
			inline ~Entity() { manager.entityIdManager.reclaim(stat); }

			inline Entity(const Entity&) = delete;
			inline Entity& operator=(const Entity&) = delete;

			inline void destroy() noexcept { manager.del(*this); }

			inline void setDrawPriority(int mDrawPriority) { drawPriority = mDrawPriority; }

			inline const auto& getStat() const noexcept	{ return stat; }
			inline auto& getManager() const noexcept	{ return manager; }
			inline int getDrawPriority() const noexcept	{ return drawPriority; }
			inline auto& getComponents() noexcept		{ return components; }

			template<typename T> inline bool hasComponent() const noexcept	{ return typeIdsBitset[Impl::getTypeIdx<T>()]; }
			template<typename T> inline T& getComponent() noexcept			{ SSVU_ASSERT(hasComponent<T>()); return ssvu::castUp<T>(*componentPtrs[Impl::getTypeIdx<T>()]); }
			template<typename T, typename... TArgs> inline T& createComponent(TArgs&&... mArgs)
			{
				SSVU_ASSERT(!hasComponent<T>());

				auto& result(manager.componentRecycler.getCreateEmplace<T>(components, *this, FWD(mArgs)...));

				componentPtrs[Impl::getTypeIdx<T>()] = &result;
				typeIdsBitset[Impl::getTypeIdx<T>()] = true;
				return result;
			}

			// Groups
			inline void setGroups(bool mOn, Group mGroup) noexcept { groups[mGroup] = mOn; if(mOn) manager.addToGroup(this, mGroup); }
			inline void addGroups(Group mGroup) noexcept { groups[mGroup] = true; manager.addToGroup(this, mGroup); }
			inline void delGroups(Group mGroup) noexcept { groups[mGroup] = false; }
			inline void clearGroups() noexcept { groups.reset(); }
			template<typename... TGroups> inline void setGroups(bool mOn, Group mGroup, TGroups... mGroups) noexcept	{ setGroups(mOn, mGroup); setGroups(mOn, mGroups...); }
			template<typename... TGroups> inline void addGroups(Group mGroup, TGroups... mGroups) noexcept				{ addGroups(mGroup); addGroups(mGroups...); }
			template<typename... TGroups> inline void delGroups(Group mGroup, TGroups... mGroups) noexcept				{ delGroups(mGroup); delGroups(mGroups...); }
			inline bool hasGroup(Group mGroup) const noexcept					{ return groups[mGroup]; }
			inline bool hasAnyGroup(const GroupBitset& mGroups) const noexcept	{ return (groups & mGroups).any(); }
			inline bool hasAllGroups(const GroupBitset& mGroups) const noexcept	{ return (groups & mGroups).all(); }
			inline const auto& getGroups() const noexcept						{ return groups; }
	};
}

#endif
