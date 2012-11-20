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

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>

using namespace std;

namespace sses
{
	class Entity;
	class Manager;
	
	class Component
	{
		friend class Entity;
		friend class Manager;

		private:
			string id;

			Component(const Component&); // non construction-copyable
			Component& operator=(const Component&); // non copyable

			Manager* managerPtr { nullptr }; // manager not owned, just pointed to
			Entity* entityPtr { nullptr }; // entity not owned, just pointed to
			
		public:
			Component(); // default id "" ctor
			Component(string);
			virtual ~Component();

			virtual void init();
			virtual void update(float);
			virtual void draw();

			Entity& getEntity(); // returns a reference to the parent entity
			Manager& getManager(); // returns a reference to the parent manager
	};
} /* namespace sses */
	
#endif /* COMPONENT_H_ */
