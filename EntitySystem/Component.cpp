#include "Component.h"
#include "Entity.h"
#include "Manager.h"

namespace sses
{
	Component::Component() : id("") { }
	Component::Component(string mId) : id(mId) { }
	Component::~Component() { }

	void Component::init() { }
	void Component::update(float mFrameTime) { }
	void Component::draw() { }

	Manager& Component::getManager() { return *managerPtr; }
	Entity& Component::getEntity() { return *entityPtr; }
} /* namespace sses */
