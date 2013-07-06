// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include "SSVEntitySystem/Core/Component.h"
#include "SSVEntitySystem/Core/Entity.h"
#include "SSVEntitySystem/Core/Manager.h"

using namespace std;

namespace sses
{
	Component::Component(const std::string& mId) : id{mId} { }
	Component::~Component() { }

	void Component::init() {  }
	void Component::update(float) { }
	void Component::draw() { }

	// Getters
	Entity& Component::getEntity() const	{ return *entity; }
	Manager& Component::getManager() const	{ return entity->getManager(); }
	const string& Component::getId() const	{ return id; }
}
