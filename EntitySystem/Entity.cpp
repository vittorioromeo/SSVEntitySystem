#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

#include "Entity.h"
#include "Component.h"
#include "Manager.h"
#include "PtrRepository.h"

using namespace std;

namespace sses
{
	Entity::Entity() : id{""} { }
	Entity::Entity(string mId) : id{mId} { }
	Entity::~Entity() { }

	void Entity::addComponent(Component* mComponentPtr)
	{
		mComponentPtr->entityPtr = this;
		componentRepo.add(mComponentPtr->id, mComponentPtr);
		managerPtr->addComponent(mComponentPtr);
		mComponentPtr->init();
	}
	void Entity::update(float mFrameTime) { for (auto componentPtr : componentRepo.getAll()) componentPtr->update(mFrameTime); }
	void Entity::draw() { for (auto componentPtr : componentRepo.getAll()) componentPtr->draw(); }
	void Entity::destroy() { managerPtr->delEntity(this); }

	Manager& Entity::getManager() { return *managerPtr; }
	PtrRepository<Component>& Entity::getComponentRepo() { return componentRepo; }
} /* namespace sses */
