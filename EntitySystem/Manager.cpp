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
#include "Repository.h"
#include "../Utils.h"
#include <algorithm>

namespace sses
{
	Manager::~Manager() { clear(); }

	void Manager::addComponent(Component* mComponent)
	{
		mComponent->managerPtr = this;
		components.add(mComponent->id, mComponent);
	}
	void Manager::addEntity(Entity* mEntity)
	{
		mEntity->managerPtr = this;
		entities.add(mEntity->id, mEntity);
	}
	void Manager::delEntity(Entity* mEntity) { entitiesToErase.push_back(mEntity); }
	void Manager::clear()
	{
		for (auto& componentPtr : components.getItems()) delete componentPtr;
		components.clear();

		for (auto& entityPtr : entities.getItems()) delete entityPtr;
		entities.clear();
	}

	void Manager::update(float mFrameTime)
	{
		for (auto& entityPtr : entities.getItems()) entityPtr->update(mFrameTime);

		for (auto& entityPtrToErase : entitiesToErase)
		{
			for (auto& componentPtr : entityPtrToErase->getComponentRepo().getItems())
			{
				components.del(componentPtr->id, componentPtr);
				delete componentPtr;
			}

			entities.del(entityPtrToErase->id, entityPtrToErase);
			delete entityPtrToErase;
		}

		entitiesToErase.clear();
	}
	void Manager::draw()
	{
		std::vector<Entity*> entityPtrsToSort{entities.getItems()};
		std::sort(std::begin(entityPtrsToSort), std::end(entityPtrsToSort), drawPrioritize);
		for (auto& entityPtr : entityPtrsToSort) entityPtr->draw();
	}

	std::vector<Entity*> Manager::getEntities(const std::string& mId) { return entities.get(mId); }
	std::vector<Component*> Manager::getComponents(const std::string& mId) { return components.get(mId); }

	// Shortcuts
	Manager& Manager::operator+=(Entity* mEntity) { addEntity(mEntity); return *this; }
	Manager& Manager::operator-=(Entity* mEntity) { delEntity(mEntity); return *this; }
}
