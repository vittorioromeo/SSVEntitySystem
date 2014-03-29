// Copyright (c) 2013-2014 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSES_COMPONENT
#define SSES_COMPONENT

#include "SSVEntitySystem/Global/Typedefs.hpp"

namespace sses
{
	class Entity;
	class Manager;

	class Component : ssvu::NoCopy
	{
		friend class Entity;

		private:
			Entity* entity{nullptr};

			inline virtual void update(FT) { }
			inline virtual void draw() { }

		public:
			inline Component() noexcept = default;
			inline virtual ~Component() { }

			inline Entity& getEntity() const noexcept
			{
				SSVU_ASSERT(entity != nullptr);
				return *entity;
			}
			inline Manager& getManager() const noexcept;
	};
}

#endif
