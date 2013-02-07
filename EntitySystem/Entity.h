// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

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
			Manager& manager;
			std::string id{""};
			int drawPriority{0};
			Repository<Component*> components; // not owned, manager owns everything!			

			void addComponent(Component* mComponent);
			
		public:
			Entity(Manager& mManager, const std::string& mId = "");
			Entity(const Entity&) = delete; // non construction-copyable
			Entity& operator=(const Entity&) = delete; // non copyable

			void update(float);
			void draw();
			void destroy();

			void setDrawPriority(int mDrawPriority);
			int getDrawPriority() const;

			Manager& getManager(); // returns a reference to the parent manager
			Repository<Component*>& getComponentRepo();
			std::string getId();

			template<typename T> std::vector<T*> getComponents(const std::string& mId) { return components.getCasted<T*>(mId); }

			// Shortcuts
			Entity& operator+=(Component* mComponent);
	};
} /* namespace sses */
	
#endif /* ENTITY_H_ */
