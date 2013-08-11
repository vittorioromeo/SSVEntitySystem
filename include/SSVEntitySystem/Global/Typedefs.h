// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_TYPEDEFS
#define SSES_TYPEDEFS

#include <typeinfo>
#include <memory>
#include <bitset>

namespace sses
{
	using Group = unsigned int;
	using Bitset = std::bitset<64>;
	using TypeId = std::size_t;
	template<typename T, typename TDeleter = std::default_delete<T>> using Uptr = std::unique_ptr<T, TDeleter>;
	template<typename T> inline static TypeId getTypeId() { return typeid(T).hash_code(); }
}

#endif
