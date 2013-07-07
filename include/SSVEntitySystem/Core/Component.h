// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_COMPONENT
#define SSES_COMPONENT

#include <typeinfo>

namespace sses
{
	class Entity;
	class Manager;

	class Component
	{
		friend class Entity;
		friend class Manager;

		private:
			Entity* entity{nullptr};
			std::size_t id;

		public:
			Component() = default;
			Component(const Component&) = delete; // non construction-copyable
			Component& operator=(const Component&) = delete; // non copyable
			virtual ~Component();

			virtual void init();
			virtual void update(float mFrameTime);
			virtual void draw();

			// Getters
			Entity& getEntity() const;
			Manager& getManager() const;
			inline std::size_t getId() const { return id; }
	};
}

#endif
