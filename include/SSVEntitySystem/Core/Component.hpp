// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_COMPONENT
#define SSES_COMPONENT

#include <vrm/pp.hpp>

// TODO: refactor, add to vrm_core and ssvu

#define TEMP_NAMESPACE VRM_PP_CAT(temp_namespace, __LINE__)

#define TEMP_NAMESPACE_END

#define TEMP_MARK_NONFINAL(base)                               \
    namespace TEMP_NAMESPACE                                   \
    {                                                          \
        struct SSVU_ATTRIBUTE(unused) temp_marker final : base \
        {                                                      \
        };                                                     \
    }

#define TEMP_MARK_NONFINAL_METHOD(base, return_type, method)             \
    namespace TEMP_NAMESPACE                                             \
    {                                                                    \
        struct SSVU_ATTRIBUTE(unused) temp_marker final : base           \
        {                                                                \
            inline return_type SSVU_ATTRIBUTE(unused) method override {} \
        };                                                               \
    }


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

TEMP_MARK_NONFINAL(sses::Component)
TEMP_MARK_NONFINAL_METHOD(sses::Component, void, update(sses::FT))
TEMP_MARK_NONFINAL_METHOD(sses::Component, void, draw())

#endif
