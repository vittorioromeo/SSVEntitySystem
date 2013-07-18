// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_TYPEDEFS
#define SSES_TYPEDEFS

#include <typeinfo>
#include <memory>

namespace sses
{
	using TypeId = std::size_t;
	template<typename T> using Uptr = std::unique_ptr<T>;
	template<typename T> inline static TypeId getTypeId() { return typeid(T).hash_code(); }
}

#endif
