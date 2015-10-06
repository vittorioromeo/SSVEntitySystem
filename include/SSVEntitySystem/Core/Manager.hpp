// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_MANAGER
#define SSES_MANAGER

namespace sses
{
    class Manager
    {
        friend Entity;
        friend Component;

    private:
        Impl::EntityIdManager entityIdManager;
        ssvu::MonoManager<Entity> entities;
        std::vector<Entity*> toSort;
        std::array<std::vector<Entity*>, maxGroups> groupedEntities;
        ComponentRecycler componentRecycler;

        inline void addToGroup(Entity* mEntity, Group mGroup)
        {
            SSVU_ASSERT(!ssvu::contains(groupedEntities[mGroup], mEntity));
            groupedEntities[mGroup].emplace_back(mEntity);
        }
        inline void del(Entity& mEntity) noexcept { entities.del(mEntity); }
        inline void refresh();

    public:
        inline Manager() = default;

        inline Manager(const Manager&) = delete;
        inline Manager& operator=(const Manager&) = delete;

        inline ~Manager() { clear(); }

        inline void clear() noexcept
        {
            entities.clear();
            for(auto& v : groupedEntities) v.clear();
        }
        inline void update(FT mFT);
        inline void draw();

        inline auto& createEntity()
        {
            return entities.create(entityIdManager.getFreeStat(), *this);
        }

        inline auto& getEntities() noexcept { return entities; }
        inline auto& getEntities(Group mGroup) noexcept
        {
            return groupedEntities[mGroup];
        }

        inline bool hasEntity(Group mGroup)
        {
            return !groupedEntities[mGroup].empty();
        }
        inline auto getEntityCount(Group mGroup) const noexcept
        {
            return groupedEntities[mGroup].size();
        }

        inline bool isAlive(const EntityStat& mStat) const noexcept
        {
            SSVU_ASSERT(!isNullEntityStat(mStat));
            return entityIdManager.isAlive(mStat);
        }
    };
}

#endif
