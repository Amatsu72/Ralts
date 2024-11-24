#pragma once

#include "EntityManager.h"

namespace Engine
{

    class Entity
    {
    public:
        Entity(const EntityID id, EntityManager *manager);
        ~Entity() = default;

        const EntityID getID() const { return m_id; }

        template <typename T, typename... Args>
        void addComponent(Args &&...args);

        template <typename T>
        void addComponent(T &component);

        template <typename T>
        inline T &getComponent() { return m_manager->getComponent<T>(m_id); }

        template <typename T>
        inline void removeComponent() { m_manager->removeComponent<T>(m_id); }

        template <typename T>
        inline bool hasComponent() const { return m_manager->hasComponent<T>(m_id); }

        void destroy();

    private:
        EntityID m_id;
        EntityManager *m_manager;
    };
}
