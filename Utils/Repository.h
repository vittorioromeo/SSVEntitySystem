// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_REPOSITORY
#define SSES_REPOSITORY

#include <vector>
#include <map>
#include <string>
#include <SSVUtils.h>

namespace sses
{
	template<typename T> class Repository
	{
		private:
			typedef typename std::vector<T>::iterator iterator;
			typedef typename std::vector<T>::const_iterator const_iterator;

			std::vector<T> items;
			std::map<std::string, std::vector<T>> itemMap;

		public:
			std::vector<T>& getItems() { return items; }
			std::vector<T>& get(const std::string& mId) { return itemMap[mId]; }
			void add(const std::string& mId, T mPtr) { items.push_back(mPtr); itemMap[mId].push_back(mPtr); }
			void del(const std::string& mId, T mPtr) { ssvu::Utils::eraseRemove(items, mPtr); ssvu::Utils::eraseRemove(itemMap[mId], mPtr); }
			void clear(){ items.clear(); itemMap.clear(); }

			template<typename U> std::vector<U> getCasted(const std::string& mId)
			{
				std::vector<U> result;
				for (auto& ptrToCast : get(mId)) result.push_back(static_cast<U>(ptrToCast));
				return result;
			}

			iterator begin() 				{ return items.begin(); }
			const_iterator begin() const 	{ return items.begin(); }
			const iterator cbegin() const	{ return items.cbegin(); }
			iterator end() 					{ return items.end(); }
			const_iterator end() const 		{ return items.end(); }
			const iterator cend() const 	{ return items.cend(); }
	};
}

#endif
