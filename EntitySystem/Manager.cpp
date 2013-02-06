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

using namespace std;

namespace sses
{
	Manager::Manager() { entitiesToErase.set_empty_key(nullptr); }
	Manager::~Manager() { clear(); }

	void Manager::addComponent(Component* mComponent) { mComponent->manager = this; components.add(mComponent->id, mComponent); }
	void Manager::add(Entity* mEntity) { mEntity->manager = this; entities.add(mEntity->id, mEntity); }
	void Manager::del(Entity* mEntity) { entitiesToErase.insert(mEntity); }
	void Manager::clear()
	{
		for (auto& componentPtr : components.getItems()) delete componentPtr;
		components.clear();

		for (auto& entity : entities.getItems()) delete entity;
		entities.clear();
	}

	void Manager::update(float mFrameTime)
	{
		for (auto& entityToErase : entitiesToErase)
		{
			for (auto& componentPtr : entityToErase->getComponentRepo().getItems())
			{
				components.del(componentPtr->id, componentPtr);
				delete componentPtr;
			}

			entities.del(entityToErase->id, entityToErase);
			delete entityToErase;
		}
		entitiesToErase.clear();

		for (auto& entity : entities.getItems()) entity->update(mFrameTime);		
	}
	void Manager::draw()
	{
		vector<Entity*> entitiesToSort{entities.getItems()};
		sort(begin(entitiesToSort), end(entitiesToSort), drawPrioritize);
		for (auto& entity : entitiesToSort) entity->draw();
	}

	vector<Entity*> Manager::getEntities(const string& mId) { return entities.get(mId); }
	vector<Component*> Manager::getComponents(const string& mId) { return components.get(mId); }

	// Shortcuts
	Manager& Manager::operator-=(Entity* mEntity) { del(mEntity); return *this; }

	Entity* Manager::createEntity(string mId) { Entity* result{new Entity(mId)}; add(result); return result; }
}
