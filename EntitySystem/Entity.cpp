// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include "Entity.h"
#include "Component.h"
#include "Manager.h"

using namespace std;

namespace sses
{
	Entity::Entity(Manager& mManager, const std::string& mId) : manager(mManager), id{mId} { }

	void Entity::addComponent(Component* mComponent)
	{
		mComponent->entity = this;
		components.add(mComponent->id, mComponent);
		manager.addComponent(mComponent);
		mComponent->init();
	}
	void Entity::update(float mFrameTime) { for (auto& component : components.getItems()) component->update(mFrameTime); }
	void Entity::draw() { for (auto& component : components.getItems()) component->draw(); }
	void Entity::destroy() { manager.del(this); }

	void Entity::setDrawPriority(int mDrawPriority) { drawPriority = mDrawPriority; }
	int Entity::getDrawPriority() const { return drawPriority; }

	Manager& Entity::getManager() { return manager; }
	Repository<Component*>& Entity::getComponentRepo() { return components; }
	string Entity::getId() { return id; }

	// Shortcuts
	Entity& Entity::operator+=(Component* mComponent) { addComponent(mComponent); return *this; }
} /* namespace sses */
