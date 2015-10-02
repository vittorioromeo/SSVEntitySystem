// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_COMPONENT_INL
#define SSES_COMPONENT_INL

namespace sses
{
inline auto& Component::getManager() const noexcept
{
    return entity.getManager();
}
}

#endif
