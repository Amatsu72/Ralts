#include "EntityManager.h"

namespace Engine
{

    void EntityManager::update()
    {
        for (auto &system : m_registeredSystems)
        {
            system.second->update();
        }
    }

    void EntityManager::render()
    {
        for (auto &system : m_registeredSystems)
        {
            system.second->render();
        }
    }

    const EntityID EntityManager::addNewEntity()
    {
        const EntityID entityID = m_availableEntities.front();
        m_availableEntities.pop();
        ++m_entityCount;
        return entityID;
    }

    void EntityManager::destroyEntity(const EntityID entityID)
    {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        m_entitiySignatures.erase(entityID);
        for (auto &array : m_componentArrays)
        {
            array.second->erase(entityID);
        }

        for (auto &system : m_registeredSystems)
        {
            system.second->removeEntity(entityID);
        }

        --m_entityCount;
        m_availableEntities.push(entityID);
    }

    template <typename T, typename... Args>
    void EntityManager::addComponent(const EntityID entityID, Args &&...args)
    {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        assert(getEntitySignature(entityID)->size() < MAX_COMPONENT_COUNT && "component cout limit reached!");

        T component(std::forward<Args>(args)...);
        component.entityID = entityID;
        getEntitySignature(entityID)->insert(componentType<T>());
        getCompList<T>()->insert(component);
        updateEnityTargetSystem(entityID);
    }

    template <typename T, typename... Args>
    void EntityManager::addComponent(const EntityID entityID, T &component)
    {
        getEntitySignature(entityID)->insert(componentType<T>());
        getCompList<T>()->insert(component);
        updateEnityTargetSystem(entityID);
    }

    template <typename T>
    void EntityManager::removeComponent(const EntityID entityID)
    {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        const ComponentTypeID compType = componentType<T>();
        getEntitySignature(entityID)->erase(compType);
        getCompList<T>()->erase(entityID);
        updateEnityTargetSystem(entityID);
    }

    template <typename T>
    bool EntityManager::hasComponent(const EntityID entityID)
    {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        return (getEntitySignature(entityID)->count(componentType<T>()) > 0);
    }

    template <typename T>
    void EntityManager::registerSystem()
    {
        const SystemTypeID systemID = systemType<T>();
        assert(m_registeredSystems.count(systemID) == 0 && "system already registered!");
        auto system = std::make_shared<T>();

        for (EntityID entityID = 0; entityID < m_entityCount; ++entityID)
        {
            addEntiyToSystem(entityID, *system.get());
        }
        system->start();
        m_registeredSystems[systemID] = std::move(system);
    }

    template <typename T>
    void EntityManager::unregisterSystem()
    {
        const SystemTypeID systemID = systemType<T>();
        assert(m_registeredSystems.count(systemID) != 0 && "system not registered!");
        m_registeredSystems.erase(systemID);
    }

    template <typename T>
    T &EntityManager::getComponent(const EntityID entityID)
    {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        return getCompList<T>()->get(entityID);
    }

    template <typename T>
    void EntityManager::addCompList()
    {
        const ComponentTypeID compType = componentType<T>();
        assert(m_componentArrays.find(compType) == m_componentArrays.end() && "component array already registered!");
        m_componentArrays[compType] = std::move(std::make_shared<CompList<T>>());
    }

    template <typename T>
    std::shared_ptr<CompList<T>> &EntityManager::getCompList()
    {
        const ComponentTypeID compType = componentType<T>();
        if (m_componentArrays.count(compType) == 0)
        {
            addCompList<T>();
        }
        return std::static_pointer_cast<CompList<T>>(m_componentArrays.at(compType));
    }

    void EntityManager::addEntitySignature(const EntityID entityID)
    {
        assert(m_entitiySignatures.find(entityID) == m_entitiySignatures.end() && " signature not found");
        m_entitiySignatures[entityID] = std::move(std::make_shared<Signature>());
    }

    std::shared_ptr<Signature> &EntityManager::getEntitySignature(const EntityID entityID)
    {
        assert(m_entitiySignatures.find(entityID) != m_entitiySignatures.end() && " signature not found");
        return m_entitiySignatures.at(entityID);
    }
    void EntityManager::updateEnityTargetSystem(const EntityID entityID)
    {
        for (auto &system : m_registeredSystems)
        {
            addEntiyToSystem(entityID, *system.second.get());
        }
    }
    void EntityManager::addEntiyToSystem(const EntityID entityID, System &system)
    {
        if (belongtoSystem(entityID, system.m_signature))
        {
            system.m_entities.insert(entityID);
        }
        else
        {
            system.m_entities.erase(entityID);
        }
    }
    bool EntityManager::belongtoSystem(const EntityID entityID, const Signature &systemSignature)
    {
        for (const auto &compType : systemSignature)
        {
            if (getEntitySignature(entityID)->count(compType) == 0)
            {
                return false;
            }
        }
        return true;
    }
}