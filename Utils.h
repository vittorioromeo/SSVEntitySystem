#ifndef UTILS_H_SSES
#define UTILS_H_SSES

#include <vector>
#include <string>
#include <sstream>

using namespace std;

namespace sses
{
	template <class T>
	void delFromVector(vector<T>& mVector, T mItem)
	{
		mVector.erase(remove(mVector.begin(), mVector.end(), mItem), mVector.end());
	}

	template<class T>
	string toStr(const T &t)
	{
		ostringstream oss;
		oss << t;
		return string(oss.str());
	}
}

#endif /* UTILS_H_SSES */
