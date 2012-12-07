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

#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <vector>
#include <map>
#include <string>
#include "../Utils.h"

namespace sses
{
	template <typename T> class PtrRepository
	{
		private:
			std::vector<T*> ptrs;
			std::map<std::string, std::vector<T*>> idPtrs;

		public:
			std::vector<T*> getAll() { return ptrs; }
			std::vector<T*> getById(std::string mId) { return idPtrs[mId]; }
			void add(std::string mId, T* mPtr)
			{
				ptrs.push_back(mPtr);
				idPtrs[mId].push_back(mPtr);
			}
			void del(std::string mId, T* mPtr)
			{
				easyErase<T*>(ptrs, mPtr);
				easyErase<T*>(idPtrs[mId], mPtr);
			}
			void clear()
			{
				ptrs.clear();
				idPtrs.clear();
			}

			template <typename U> std::vector<U*> getByIdCasted(std::string mId)
			{
				std::vector<U*> result;
				for (auto ptrToCast : getById(mId)) result.push_back(static_cast<U*>(ptrToCast));
				return result;
			}
	};
} /* namespace sses */
#endif /* REPOSITORY_H_ */
