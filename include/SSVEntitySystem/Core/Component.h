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
			TypeId id;

		public:
			Component() = default;
			Component(const Component&) = delete; // non construction-copyable
			Component& operator=(const Component&) = delete; // non copyable
			virtual inline ~Component() { }

			virtual inline void init()			{ }
			virtual inline void update(float)	{ }
			virtual inline void draw()			{ }

			inline Entity& getEntity() const	{ return *entity; }
			inline TypeId getId() const			{ return id; }
			inline Manager& getManager() const;
	};
}

#endif
