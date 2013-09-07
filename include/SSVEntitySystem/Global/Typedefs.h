// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_TYPEDEFS
#define SSES_TYPEDEFS

#include <typeinfo>
#include <memory>
#include <bitset>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <SSVUtils/SSVUtils.h>

namespace sses
{
	using Group = unsigned int;
	using Bitset = std::bitset<64>;
	using EntityId = std::size_t;
	using EntityIdUse = std::uint8_t;
	using EntityStat = std::pair<EntityId, EntityIdUse>;
	using TypeId = std::size_t;
	template<typename T, typename TDeleter = std::default_delete<T>> using Uptr = ssvu::Uptr<T, TDeleter>;

	inline std::size_t getMaxEntities() noexcept { static std::size_t maxEntities{1000000}; return maxEntities; }
	template<typename T> inline static TypeId getTypeId() noexcept { return typeid(T).hash_code(); }
}

#endif
