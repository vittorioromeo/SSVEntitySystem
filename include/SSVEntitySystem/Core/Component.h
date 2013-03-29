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
			Entity& entity;
			Manager& manager;
			std::string id{""};
			
		public:
			Component(Entity& mEntity, const std::string& mId = "");
			Component(const Component&) = delete; // non construction-copyable
			Component& operator=(const Component&) = delete; // non copyable
			virtual ~Component();

			virtual void update(float mFrameTime);
			virtual void draw();

			// Getters
			Entity& getEntity();
			Manager& getManager();
			std::string getId();
	};
}
	
#endif
