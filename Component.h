// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_COMPONENT
#define SSES_COMPONENT

#include <string>

namespace sses
{
	class Entity;
	class Manager;
	
	class Component
	{
		friend class Entity;
		friend class Manager;

		private:
			std::string id{""};
			Manager* manager{nullptr}; // manager not owned, just pointed to
			Entity* entity{nullptr}; // entity not owned, just pointed to
			
		public:
			Component(const std::string& mId = "");
			Component(const Component&) = delete; // non construction-copyable
			Component& operator=(const Component&) = delete; // non copyable
			virtual ~Component();

			virtual void init();
			virtual void update(float mFrameTime);
			virtual void draw();

			Entity& getEntity(); // returns a reference to the parent entity
			Manager& getManager(); // returns a reference to the parent manager
	};
}
	
#endif
