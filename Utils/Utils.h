// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_UTILS
#define SSES_UTILS

#include <algorithm>
#include <vector>
#include <google/dense_hash_set>
#include <SSVUtils.h>
#include "Utils/Repository.h"

namespace ssvu
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

		#ifndef SSVU_TRAITS_DENSEHASHSET
		#define SSVU_TRAITS_DENSEHASHSET
		template<typename TItem> struct Container<google::dense_hash_set<TItem>, TItem>
		{
			typedef google::dense_hash_set<TItem> TContainer;

			static void init(TContainer& mContainer) { mContainer.set_empty_key(nullptr); }
			static void clear(TContainer& mContainer) { mContainer.clear(); }
			static void add(TContainer& mContainer, const TItem& mItem) { mContainer.insert(mItem); }
			static void del(TContainer&, const TItem&) { }
		};
		#endif
	}
}

namespace sses
{
	class Entity;

	bool drawPrioritize(const Entity* mEntityA, const Entity* mEntityB);
}

#endif
