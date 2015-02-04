// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_TYPEDEFS
#define SSES_TYPEDEFS

namespace sses
{
	// Forward declarations
	class Component;
	class Entity;
	class Manager;

	// SSVU Typedefs
	using SizeT = ssvu::SizeT;

	// Constants
	static constexpr SizeT maxEntities{1'000'000};
	static constexpr SizeT maxGroups{32};
	static constexpr SizeT maxComponents{64};

	// Entity typedefs
	using EntityId = int;
	using EntityIdCtr = int;
	struct EntityStat { EntityId id; EntityIdCtr ctr; };

	// Type index typedefs
	using TypeIdx = SizeT;
	using TypeIdxBitset = std::bitset<maxComponents>;

	// Group typedefs
	using Group = unsigned int;
	using GroupBitset = std::bitset<maxGroups>;

	// SSVUtils typedefs
	using FT = ssvu::FT;

	// Recycler typedefs
	using ComponentRecycler = ssvu::PolyFixedRecycler<Component, maxComponents>;
	using ComponentRecyclerPtr = ComponentRecycler::PtrType;

	namespace Impl
	{
		// Returns the next unique bit index for a type
		inline auto getLastTypeIdx() noexcept
		{
			static TypeIdx lastIdx{0};
			SSVU_ASSERT(lastIdx < maxComponents);
			return lastIdx++;
		}

		// Stores a specific bit index for a Component type
		template<typename T> struct TypeIdxInfo { static TypeIdx idx; };
		template<typename T> TypeIdx TypeIdxInfo<T>::idx{getLastTypeIdx()};

		// Shortcut to get the bit index of a Component type
		template<typename T> inline auto getTypeIdx() noexcept
		{
			SSVU_ASSERT_STATIC(ssvu::isBaseOf<Component, T>(), "`T` must derive from `Component`");
			return TypeIdxInfo<T>::idx;
		}
	}

	inline auto getNullEntityStat() noexcept { return EntityStat{-1, -1}; }
	inline bool isNullEntityStat(const EntityStat& mEntityStat) noexcept { return mEntityStat.ctr == -1 && mEntityStat.id == -1; }
}

#endif
