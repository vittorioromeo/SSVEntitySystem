#ifndef ENTITYMANAGER_H_
#define ENTITYMANAGER_H_

#include <string>
#include <vector>
#include <map>
#include "Entity.h"
#include "Component.h"
#include "PtrRepository.h"

using namespace std;

namespace sses
{
	class Manager
	{
		friend class Entity;
		friend class Component;

		private:
			Manager(const Manager&); // non construction-copyable
			Manager& operator=(const Manager&); // non copyable

			PtrRepository<Entity> entityRepo; // owned!
			PtrRepository<Component> componentRepo; // owned!
			vector<Entity*> entityPtrsToErase; // not owned

			void addComponent(Component*);

		public:
			Manager() = default;
			~Manager();

			void addEntity(Entity*);
			void delEntity(Entity*);
			void update(float);
			void draw();

			vector<Entity*>& getEntityPtrsById(string);
			vector<Component*>& getComponentPtrsById(string);

			template <class T>
			vector<T*> getEntityPtrsByIdCasted(string mId) { return entityRepo.getByIdCasted<T>(mId); }
			template <class T>
			vector<T*> getComponentPtrsByIdCasted(string mId) { return componentRepo.getByIdCasted<T>(mId); }
	};
} /* namespace sses */
#endif /* ENTITYMANAGER_H_ */
