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
#include <SSVUtils/SSVUtils.h>

namespace sses
{
	static constexpr std::size_t maxEntities{1000000};
	static constexpr std::size_t maxGroups{32};
	static constexpr std::size_t maxComponents{32};

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
		static unsigned int lastTypeIdBitIdx{0};

		template<typename T> struct TypeIdStorage { static const TypeId typeId; static const std::size_t bitIdx; };
		template<typename T> const TypeId TypeIdStorage<T>::typeId{typeid(T).hash_code()};
		template<typename T> const std::size_t TypeIdStorage<T>::bitIdx{lastTypeIdBitIdx++};

		template<typename T> inline static void buildBitsetHelper(TypeIdsBitset& mBitset) noexcept { mBitset.set(Internal::TypeIdStorage<T>::bitIdx); }
		template<typename T1, typename T2, typename... TArgs> inline static void buildBitsetHelper(TypeIdsBitset& mBitset) noexcept { buildBitsetHelper<T1>(mBitset); buildBitsetHelper<T2, TArgs...>(mBitset); }
		template<typename... TArgs> inline static TypeIdsBitset getBuildBitset() noexcept { TypeIdsBitset result; buildBitsetHelper<TArgs...>(result); return result; }

		template<typename... TArgs> struct TypeIdsBitsetStorage{ static const TypeIdsBitset bitset; };
		template<typename... TArgs> const TypeIdsBitset TypeIdsBitsetStorage<TArgs...>::bitset{getBuildBitset<TArgs...>()};
	}

	template<typename T> inline constexpr const TypeId& getTypeId() noexcept					{ return Internal::TypeIdStorage<T>::typeId; }
	template<typename T> inline constexpr static const std::size_t& getTypeIdBitIdx() noexcept	{ return Internal::TypeIdStorage<T>::bitIdx; }
	template<typename T> inline static void appendTypeIdBit(TypeIdsBitset& mBitset) noexcept	{ Internal::buildBitsetHelper<T>(mBitset); }
}

#endif
