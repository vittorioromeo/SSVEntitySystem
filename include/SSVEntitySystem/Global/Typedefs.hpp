// Copyright (c) 2013-2014 Vittorio Romeo
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
#include <SSVUtils/Core/Core.hpp>
#include <SSVUtils/MemoryManager/MemoryManager.hpp>

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

	using FT = ssvu::FT;

	template<typename T, typename TDeleter = std::default_delete<T>> using Uptr = ssvu::Uptr<T, TDeleter>;

	namespace Internal
	{
		inline TypeIdIdx getNextTypeIdBitIdx() noexcept { static TypeIdIdx lastIdx{0}; return lastIdx++; }

		SSVU_DEFINE_MEMFN_CALLER(callInit, init, void()); // `callInit(...)` only calls `T::init` if it exists

		template<typename T> inline const TypeIdIdx& getTypeIdBitIdx() noexcept
		{
			SSVU_ASSERT_STATIC(ssvu::isBaseOf<Component, T>(), "Type must derive from Component");
			static TypeIdIdx idx{getNextTypeIdBitIdx()}; return idx;
		}
	}
}

#endif
