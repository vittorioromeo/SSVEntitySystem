// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_GLOBAL_GROUPMANAGER
#define SSES_GLOBAL_GROUPMANAGER

#include <unordered_map>
#include <string>
#include "SSVEntitySystem/Global/Typedefs.h"

namespace sses
{
	class GroupManager
	{
		private:
			Group lastGroup{0};
			std::unordered_map<std::string, Group> groups;

		public:
			inline Group get(const std::string& mLabel)
			{
				if(groups.find(mLabel) == end(groups)) groups[mLabel] = lastGroup++;
				return groups[mLabel];
			}
	};
}

#endif

// TODO: unify this with SSVSCollision somehow
