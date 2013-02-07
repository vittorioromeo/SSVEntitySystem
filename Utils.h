// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef UTILS_H_SSES
#define UTILS_H_SSES

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

namespace sses
{
	class Entity;

	template<typename T, typename V> void eraseRemove(T& mItems, const V& mValue) { mItems.erase(std::remove(std::begin(mItems), std::end(mItems), mValue), std::end(mItems)); }
	bool drawPrioritize(const Entity* mEntityA, const Entity* mEntityB);
}

#endif /* UTILS_H_SSES */
