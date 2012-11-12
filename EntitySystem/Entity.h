#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>
#include <string>
#include "PtrRepository.h"

using namespace std;

namespace sses
{
	class Component;
	class Manager;
	
	class Entity
	{
		friend class Manager;

		private:
			string id;

			Entity(const Entity&); // non construction-copyable
			Entity& operator=(const Entity&); // non copyable

			PtrRepository<Component> componentRepo; // not owned, manager owns everything!
			Manager* managerPtr { nullptr }; // not owned, just pointed to
			
		public:
			Entity(); // default id "" ctor
			Entity(string);
			~Entity();

			void addComponent(Component*);
			void update(float);
			void draw();
			void destroy();

			Manager& getManager(); // returns a reference to the parent manager
			PtrRepository<Component>& getComponentRepo();

			template <class T>
			vector<T*> getComponentPtrsByIdCasted(string mId) { return componentRepo.getByIdCasted<T>(mId); }

			int drawPriority{0};
	};
} /* namespace sses */
	
#endif /* ENTITY_H_ */
