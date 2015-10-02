// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_COMPONENT
#define SSES_COMPONENT

namespace sses
{
class Component
{
    friend Entity;

private:
    Entity& entity;

    inline virtual void update(FT) {}
    inline virtual void draw() {}

public:
    inline Component(Entity& mE) noexcept : entity{mE} {}

    inline Component(const Component&) = delete;
    inline Component& operator=(const Component&) = delete;

    inline virtual ~Component() {}

    inline auto& getEntity() const noexcept { return entity; }
    inline auto& getManager() const noexcept;
};
}

#endif
