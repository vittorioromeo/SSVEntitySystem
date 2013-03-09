// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_UTILS
#define SSES_UTILS

#include <algorithm>
#include <vector>
#include <google/dense_hash_set>
#include <SSVStart.h>
#include "Utils/Repository.h"

namespace ssvs
{
	namespace Utils
	{
		namespace Traits
		{
			template<typename TItem> struct Container<sses::Repository<TItem>, TItem>
			{
				typedef sses::Repository<TItem> TContainer;

				static void init(TContainer&) { }
				static void clear(TContainer& mContainer) { mContainer.clear(); }
				static void add(TContainer& mContainer, const TItem& mItem) { mContainer.add(mItem->getId(), mItem); }
				static void del(TContainer& mContainer, const TItem& mItem) { mContainer.del(mItem->getId(), mItem); }
			};
		}
	}
}

namespace sses
{
	class Entity;

	template<typename T, typename V> void eraseRemove(T& mItems, const V& mValue) { mItems.erase(std::remove(std::begin(mItems), std::end(mItems), mValue), std::end(mItems)); }
	bool drawPrioritize(const Entity* mEntityA, const Entity* mEntityB);
}

#endif
