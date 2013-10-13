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
#include <SSVUtils/Global/Typedefs.h>
#include <SSVUtils/MemoryManager/MemoryManager.h>
#include <SSVUtils/Utils/UtilsContainers.h>

namespace sses
{
	static constexpr std::size_t maxEntities{1000000};
	static constexpr std::size_t maxGroups{32};
	static constexpr std::size_t maxComponents{64};

	using EntityId = std::size_t;
	using EntityIdUse = std::uint8_t;
	using EntityStat = std::pair<EntityId, EntityIdUse>;

	using TypeId = std::size_t;
	using TypeIdsBitset = std::bitset<maxComponents>;

	using Group = unsigned int;
	using GroupBitset = std::bitset<maxGroups>;

	template<typename T, typename TDeleter = std::default_delete<T>> using Uptr = ssvu::Uptr<T, TDeleter>;

	namespace Internal
	{
		inline std::size_t getNextTypeId() { static std::size_t lastTypeIdBitIdx{0}; return lastTypeIdBitIdx++; }

		template<typename T> struct TypeIdStorage { static const std::size_t bitIdx; };
		template<typename T> const std::size_t TypeIdStorage<T>::bitIdx{getNextTypeId()};

		template<typename T> inline void buildBitsetHelper(TypeIdsBitset& mBitset) noexcept { mBitset.set(Internal::TypeIdStorage<T>::bitIdx); }
		template<typename T1, typename T2, typename... TArgs> inline void buildBitsetHelper(TypeIdsBitset& mBitset) noexcept { buildBitsetHelper<T1>(mBitset); buildBitsetHelper<T2, TArgs...>(mBitset); }
		template<typename... TArgs> inline TypeIdsBitset getBuildBitset() noexcept { TypeIdsBitset result; buildBitsetHelper<TArgs...>(result); return result; }
	}

	template<typename T> inline constexpr const std::size_t& getTypeIdBitIdx() noexcept	{ return Internal::TypeIdStorage<T>::bitIdx; }
}

#endif
