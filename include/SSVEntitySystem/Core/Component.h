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

			template<typename T = Entity> inline T& getEntityImpl() const { return *entity; }
			template<typename TM = Manager, typename TE = Entity> inline TM& getManagerImpl() const { return getEntityImpl<TE>().getManager(); }

		public:
			Component() = default;
			Component(const Component&) = delete; // non construction-copyable
			Component& operator=(const Component&) = delete; // non copyable
			virtual ~Component() { }

			virtual inline void init()			{ }
			virtual inline void update(float)	{ }
			virtual inline void draw()			{ }

			inline Entity& getEntity() const	{ return getEntityImpl(); }
			inline Manager& getManager() const	{ return getManagerImpl(); }
			inline TypeId getId() const			{ return id; }
	};
}

#endif
