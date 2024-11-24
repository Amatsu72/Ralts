#include "Entity.h"

namespace Engine
{
    Entity::Entity(const EntityID id, EntityManager *manager) : m_id(id), m_manager(manager)
    {
    }

    template <typename T, typename... Args>
    void Entity::addComponent(Args &&...args)
    {
        m_manager->addComponent<T>(m_id, std::forward<Args>(args)...);
    }
    template <typename T>
    void Entity::addComponent(T &component)
    {
        m_manager->addComponent<T>(m_id, component);
    }

    void Entity::destroy()
    {
        m_manager->destroyEntity(m_id);
    }
}