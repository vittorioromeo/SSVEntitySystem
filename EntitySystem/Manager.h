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

#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include <string>
#include <vector>
#include <map>
#include "Entity.h"
#include "Component.h"
#include "Repository.h"

namespace sses
{
	class Manager
	{
		friend class Entity;
		friend class Component;

		private:
			Repository<Entity*> entities; // owned!
			Repository<Component*> components; // owned!
			std::vector<Entity*> entitiesToErase; // not owned

			void addEntity(Entity* mEntity);
			void delEntity(Entity* mEntity);
			void addComponent(Component* mComponent);

		public:
			Manager() = default;
			Manager(const Manager&) = delete; // non construction-copyable
			Manager& operator=(const Manager&) = delete; // non copyable
			~Manager();
			
			void clear();
			void update(float mFrameTime);
			void draw();

			std::vector<Entity*> getEntities(const std::string& mId);
			std::vector<Component*> getComponents(const std::string& mId);
			template<typename T> std::vector<T*> getComponents(const std::string& mId) { return components.getCasted<T*>(mId); }

			// Shortcuts
			Manager& operator+=(Entity* mEntity);
			Manager& operator-=(Entity* mEntity);
	};
} /* namespace sses */
#endif /* ENTITYMANAGER_H_ */
