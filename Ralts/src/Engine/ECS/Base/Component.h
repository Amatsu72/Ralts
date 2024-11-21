#pragma once
#include "Type.h"

namespace Engine
{

    struct Component
    {
        Component() : m_entityID() {}
        virtual ~Component() {}
        inline const EntityID getID() const { return m_entityID; }

    private:
        friend class EntityManager;
        EntityID m_entityID;
    };
}