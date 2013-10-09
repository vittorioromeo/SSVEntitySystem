// Copyright (c) 2013 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_COMPONENT
#define SSES_COMPONENT

#include "SSVEntitySystem/Global/Typedefs.h"

namespace sses
{
	class Entity;
	class Manager;

	class Component
	{
		friend class Entity;

		private:
			Entity* entity{nullptr};

		public:
			Component() noexcept = default;
			Component(const Component&) = delete; // non construction-copyable
			Component& operator=(const Component&) = delete; // non copyable
			inline virtual ~Component() { }

			inline virtual void init()			{ }
			inline virtual void update(float)	{ }
			inline virtual void draw()			{ }

			inline Entity& getEntity() const noexcept { return *entity; }
			inline Manager& getManager() const noexcept;
	};
}

#endif
