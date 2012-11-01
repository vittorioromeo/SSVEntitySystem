#include "Manager.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include "PtrRepository.h"
#include "../Utils.h"


namespace sses
{
	Manager::~Manager()
	{
		for (auto &entityPtr : entityRepo.getAll())
		{
			for (auto &componentPtr : entityPtr->componentRepo.getAll())
			{
				componentRepo.del(componentPtr->id, componentPtr);
				delete componentPtr;
			}

			entityRepo.del(entityPtr->id, entityPtr);
			delete entityPtr;
		}
	}

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

	void Manager::update(float mFrameTime)
	{
		for (auto &entityPtr : entityRepo.getAll())
			entityPtr->update(mFrameTime);

		for (auto &entityPtrToErase : entityPtrsToErase)
		{
			for (auto &componentPtr : entityPtrToErase->componentRepo.getAll())
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
		for (auto &entityPtr : entityRepo.getAll())
			entityPtr->draw();
	}

	vector<Entity*>& Manager::getEntityPtrsById(string mId) { return entityRepo.getById(mId); }
	vector<Component*>& Manager::getComponentPtrsById(string mId) { return componentRepo.getById(mId); }
} /* namespace sses */
