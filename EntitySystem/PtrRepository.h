#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <vector>
#include <map>
#include <string>
#include "../Utils.h"

using namespace std;

namespace sses
{
	template <class T>
	class PtrRepository
	{
		private:
			vector<T*> ptrs;
			map<string, vector<T*>> idPtrs;

		public:
			vector<T*>& getAll() { return ptrs; }
			vector<T*>& getById(string mId) { return idPtrs[mId]; }
			void add(string mId, T* mPtr)
			{
				ptrs.push_back(mPtr);
				idPtrs[mId].push_back(mPtr);
			}
			void del(string mId, T* mPtr)
			{
				delFromVector<T*>(ptrs, mPtr);
				delFromVector<T*>(idPtrs[mId], mPtr);
			}

			template <class U>
			vector<U*> getByIdCasted(string mId)
			{
				vector<T*> ptrsToCast(getById(mId));
				vector<U*> result;

				for (auto ptrToCast : ptrsToCast)
					result.push_back(static_cast<U*>(ptrToCast));

				return result;
			}
	};
} /* namespace sses */
#endif /* REPOSITORY_H_ */
