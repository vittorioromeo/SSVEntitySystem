// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "Component.h"
#include "Entity.h"
#include "Manager.h"

using namespace std;

namespace sses
{
	Component::Component(Entity& mEntity, const std::string& mId) : entity(mEntity), manager(entity.getManager()), id{mId} { }
	Component::~Component() { }

	void Component::update(float) { }
	void Component::draw() { }

	Entity& Component::getEntity() 		{ return entity; }
	Manager& Component::getManager() 	{ return manager; }
	string Component::getId() 			{ return id; }
}
