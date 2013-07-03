// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "SSVEntitySystem/Utils/Utils.h"
#include "SSVEntitySystem/Core/Entity.h"

namespace sses
{
	bool drawPrioritize(const Entity* mA, const Entity* mB) { return mA->getDrawPriority() > mB->getDrawPriority(); }
}
