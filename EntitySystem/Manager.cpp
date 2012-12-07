/* The MIT License (MIT)
 * Copyright (c) 2012 Vittorio Romeo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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
		std::vector<Entity*> entityPtrsToSort{entityRepo.getAll()};
		std::sort(std::begin(entityPtrsToSort), std::end(entityPtrsToSort), drawPrioritize);
		for (auto entityPtr : entityPtrsToSort) entityPtr->draw();
	}

	std::vector<Entity*> Manager::getEntityPtrsById(std::string mId) { return entityRepo.getById(mId); }
	std::vector<Component*> Manager::getComponentPtrsById(std::string mId) { return componentRepo.getById(mId); }
} /* namespace sses */
