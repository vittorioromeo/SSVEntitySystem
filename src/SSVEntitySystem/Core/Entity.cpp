// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include <vector>
#include <string>
#include <algorithm>
#include "SSVEntitySystem/Core/Entity.h"
#include "SSVEntitySystem/Core/Component.h"

using namespace std;

namespace sses
{
	Entity::Entity(Manager& mManager, const std::string& mId) : manager(mManager), id{mId} { }

	void Entity::update(float mFrameTime)
	{
		memoryManager.cleanUp();
		for(const auto& c : memoryManager) c->update(mFrameTime);
	}
	void Entity::draw()		{ for(const auto& c : memoryManager) c->draw(); }
	void Entity::destroy()	{ manager.del(*this); }
}
