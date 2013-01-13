/* The MIT License (MIT)
 * Copyright (c) 2012 Vittorio Romeo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef REPOSITOR2Y_H_
#define REPOSITOR2Y_H_

#include <vector>
#include <map>
#include <string>
#include "../Utils.h"

namespace sses
{
	template <typename T> class Repository
	{
		private:
			std::vector<T> items;
			std::map<std::string, std::vector<T>> itemMap;

		public:
			std::vector<T>& getItems() { return items; }
			std::vector<T>& get(const std::string& mId) { return itemMap[mId]; }
			void add(const std::string& mId, T mPtr)
			{
				items.push_back(mPtr);
				itemMap[mId].push_back(mPtr);
			}
			void del(const std::string& mId, T mPtr)
			{
				easyErase<T>(items, mPtr);
				easyErase<T>(itemMap[mId], mPtr);
			}
			void clear()
			{
				items.clear();
				itemMap.clear();
			}

			template <typename U> std::vector<U> getCasted(const std::string& mId)
			{
				std::vector<U> result;
				for (auto& ptrToCast : get(mId)) result.push_back(static_cast<U>(ptrToCast));
				return result;
			}
	};
} /* namespace sses */
#endif /* REPOSITOR2Y_H_ */
