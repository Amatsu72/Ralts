#include "EntityManager.h"


namespace Engine {

    void EntityManager::update() {
        for (auto& system : m_registeredSystems) {
            system.second->update();
        }
    }

    void EntityManager::render() {
        for (auto& system : m_registeredSystems) {
            system.second->render();
        }
    }

    const EntityID EntityManager::addNewEntity() {
        const EntityID entityID = m_availableEntities.front();
        m_availableEntities.pop();
        ++m_entityCount;
        return entityID;
    }

    void EntityManager::destroyEntity(const EntityID entityID) {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        m_entitiySignatures.erase(entityID);
        for (auto& array : m_componentArrays) {
            array.second->erase(entityID);
        }

        for(auto& system : m_registeredSystems) {
            system.second->removeEntity(entityID);
        }

        --m_entityCount;
        m_availableEntities.push(entityID);
    }

    template<typename T, typename... Args>
    void EntityManager::addComponent(const EntityID entityID, Args&&... args) {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        assert(m_entitiySignatures[entityID].size() < MAX_COMPONENT_COUNT && "component cout limit reached!");

        T component(std::forward<Args>(args)...);
        component.entityID = entityID;
        //getcomponentarray
        const ComponentTypeID compType = componentType<T>();
        m_entitiySignatures.at(entityID).insert(compType);
        //attach entity to system
    }

    template<typename T>
    void EntityManager::removeComponent(const EntityID entityID) {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        const ComponentTypeID compType = componentType<T>();
        m_entitiySignatures.at(entityID).erase(compType);
        //get component array
    }

    template<typename T>
    bool EntityManager::hasComponent(const EntityID entityID) const {
        assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        const EntitySignature& signature = m_entitiySignatures.at(entityID);
        const ComponentTypeID compType = componentType<T>();
        
        return (signature.count(compType) > 0);
    }

}