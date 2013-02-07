// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "Component.h"
#include "Entity.h"
#include "Manager.h"

namespace sses
{
	Component::Component(const std::string& mId) : id{mId} { }
	Component::~Component() { }

	void Component::init() { }
	void Component::update(float) { }
	void Component::draw() { }

	Manager& Component::getManager() { return *manager; }
	Entity& Component::getEntity() { return *entity; }
} /* namespace sses */
