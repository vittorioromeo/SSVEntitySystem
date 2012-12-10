#include "Utils.h"
#include "EntitySystem/Entity.h"

namespace sses
{
	bool drawPrioritize(const Entity* mEntityA, const Entity* mEntityB) { return mEntityA->getDrawPriority() > mEntityB->getDrawPriority(); }
}
