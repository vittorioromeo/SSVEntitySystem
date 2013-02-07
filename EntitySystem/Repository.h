// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef REPOSITOR2Y_H_
#define REPOSITOR2Y_H_

#include <vector>
#include <map>
#include <string>
#include "../Utils.h"

namespace sses
{
	template<typename T> class Repository
	{
		private:
			std::vector<T> items;
			std::map<std::string, std::vector<T>> itemMap;

		public:
			std::vector<T>& getItems() { return items; }
			std::vector<T>& get(const std::string& mId) { return itemMap[mId]; }
			void add(const std::string& mId, T mPtr) { items.push_back(mPtr); itemMap[mId].push_back(mPtr); }
			void del(const std::string& mId, T mPtr) { eraseRemove(items, mPtr); eraseRemove(itemMap[mId], mPtr); }
			void clear(){ items.clear(); itemMap.clear(); }

			template<typename U> std::vector<U> getCasted(const std::string& mId)
			{
				std::vector<U> result;
				for (auto& ptrToCast : get(mId)) result.push_back(static_cast<U>(ptrToCast));
				return result;
			}
	};
} /* namespace sses */
#endif /* REPOSITOR2Y_H_ */
