// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_TYPEDEFS
#define SSES_TYPEDEFS

#include <typeinfo>
#include <memory>
#include <bitset>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cassert>
#include <type_traits>
#include <SSVUtils/Global/Typedefs.h>
#include <SSVUtils/MemoryManager/MemoryManager.h>
#include <SSVUtils/Utils/UtilsContainers.h>

namespace sses
{
	class Component;

	static constexpr std::size_t maxEntities{1000000};
	static constexpr std::size_t maxGroups{32};
	static constexpr std::size_t maxComponents{64};

	using EntityId = std::size_t;
	using EntityIdUse = std::uint8_t;
	using EntityStat = std::pair<EntityId, EntityIdUse>;

	using TypeIdIdx = std::size_t;
	using TypeIdsBitset = std::bitset<maxComponents>;

	using Group = unsigned int;
	using GroupBitset = std::bitset<maxGroups>;

	template<typename T, typename TDeleter = std::default_delete<T>> using Uptr = ssvu::Uptr<T, TDeleter>;

	namespace Internal
	{
		inline TypeIdIdx getNextTypeIdBitIdx() noexcept { static TypeIdIdx lastIdx{0}; return lastIdx++; }
	}

	template<typename T> inline const TypeIdIdx& getTypeIdBitIdx() noexcept
	{
		static_assert(std::is_base_of<Component, T>::value, "Type must derive from Component");
		static TypeIdIdx idx{Internal::getNextTypeIdBitIdx()}; return idx;
	}

	namespace Internal
	{
		SSVU_DEFINE_HAS_MEMBER_CHECKER(HasInit, init);
		SSVU_DEFINE_HAS_MEMBER_INVOKER(callInit, init, (HasInit<T, void()>::Value));
	}
}

#endif
