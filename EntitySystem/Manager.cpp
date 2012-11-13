#include "Manager.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include "PtrRepository.h"
#include "../Utils.h"
#include <algorithm>

namespace sses
{
	bool drawPrioritize(const Entity* a, const Entity* b) { return a->drawPriority > b->drawPriority; }

	Manager::~Manager() { clear(); }

	void Manager::addComponent(Component* mComponentPtr)
	{
		mComponentPtr->managerPtr = this;
		componentRepo.add(mComponentPtr->id, mComponentPtr);
	}
	void Manager::addEntity(Entity* mEntityPtr)
	{
		mEntityPtr->managerPtr = this;
		entityRepo.add(mEntityPtr->id, mEntityPtr);
	}
	void Manager::delEntity(Entity* mEntityPtr) { entityPtrsToErase.push_back(mEntityPtr); }
	void Manager::clear()
	{
		for (auto componentPtr : componentRepo.getAll()) delete componentPtr;
		componentRepo.clear();

		for (auto entityPtr : entityRepo.getAll()) delete entityPtr;
		entityRepo.clear();
	}

	void Manager::update(float mFrameTime)
	{
		for (auto entityPtr : entityRepo.getAll()) entityPtr->update(mFrameTime);

		for (auto entityPtrToErase : entityPtrsToErase)
		{
			for (auto componentPtr : entityPtrToErase->componentRepo.getAll())
			{
				componentRepo.del(componentPtr->id, componentPtr);
				delete componentPtr;
			}

			entityRepo.del(entityPtrToErase->id, entityPtrToErase);
			delete entityPtrToErase;
		}

		entityPtrsToErase.clear();
	}
	void Manager::draw()
	{
		vector<Entity*> entityPtrsToSort{entityRepo.getAll()};
		sort(entityPtrsToSort.begin(), entityPtrsToSort.end(), drawPrioritize);
		for (auto entityPtr : entityPtrsToSort) entityPtr->draw();
	}

	vector<Entity*> Manager::getEntityPtrsById(string mId) { return entityRepo.getById(mId); }
	vector<Component*> Manager::getComponentPtrsById(string mId) { return componentRepo.getById(mId); }
} /* namespace sses */
