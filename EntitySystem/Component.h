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
