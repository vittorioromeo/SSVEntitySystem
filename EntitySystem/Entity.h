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

#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>
#include <string>
#include "Repository.h"

namespace sses
{
	class Component;
	class Manager;
	
	class Entity
	{
		friend class Manager;

		private:
			int drawPriority{0};
			std::string id{""};
			Repository<Component*> components; // not owned, manager owns everything!
			Manager* manager{nullptr}; // not owned, just pointed to

			void addComponent(Component* mComponent);
			
		public:
			Entity(); // default id "" ctor
			Entity(const std::string& mId);
			Entity(const Entity&) = delete; // non construction-copyable
			Entity& operator=(const Entity&) = delete; // non copyable
			~Entity();

			void update(float);
			void draw();
			void destroy();

			void setDrawPriority(int mDrawPriority);
			int getDrawPriority() const;

			Manager& getManager(); // returns a reference to the parent manager
			Repository<Component*>& getComponentRepo();

			template<typename T> std::vector<T*> getComponents(const std::string& mId) { return components.getCasted<T*>(mId); }

			// Shortcuts
			Entity& operator+=(Component* mComponent);
	};
} /* namespace sses */
	
#endif /* ENTITY_H_ */
