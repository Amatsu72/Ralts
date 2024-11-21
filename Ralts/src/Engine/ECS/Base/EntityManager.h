#pragma once

#include "Component.h"
#include "System.h"
#include "CompArray.h"

namespace Engine {

    class EntityManager {
    public:
        EntityManager(): m_entityCount(0) {
            for (EntityID entity = 0u; entity < MAX_ENTITY_COUNT; ++entity) {
                m_availableEntities.push(entity);
            }
        }
        ~EntityManager() {}

        void update() {
            for (auto& system : m_registeredSystems) {
                system.second->update();
            }
        }

        void render() {
            for (auto& system : m_registeredSystems) {
                system.second->render();
            }
        }

        const EntityID addNewEntity() {
            const EntityID entityID = m_availableEntities.front();
            m_availableEntities.pop();
            ++m_entityCount;
            return entityID;
        }

        void destroyEntity(const EntityID entityID) {
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
        void addComponent(const EntityID entityID, Args&&... args) {
            assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
            assert(m_entitiySignaturesp[entityID].size() < MAX_COMPONENT_COUNT && "component cout limit reached!");

            T component(std::forward<Args>(args)...);
            component.entityID = entityID;
            //getcomponentarray
            const ComponentTypeID compType = componentType<T>();
            m_entitiySignatures.at(entityID).insert(compType);
            //attach entity to system
        }

        template<typename T>
        void removeComponent(const EntityID entityID) {
            assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
            const ComponentTypeID compType = componentType<T>();
            m_entitiySignatures.at(entityID).erase(compType);
            //get component array
            
        }

        // template<typename T>
        // T& getComponent(const EntityID entityID) {
        //     assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        //     const ComponentTypeID compType = componentType<T>();
        //     // return

        // }

        template<typename T>
        bool hasComponent(const EntityID entityID) const {
            assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
            const EntitySignature& signature = m_entitiySignatures.at(entityID);
            const ComponentTypeID compType = componentType<T>();
            
            return (signature.cout(compType) > 0);
        }

    private:
        EntityID m_entityCount;
        std::queue<EntityID> m_availableEntities;
        std::map<EntityID, EntitySignature> m_entitiySignatures;
        std::map<SystemTypeID, std::unique_ptr<System>> m_registeredSystems;
        std::map<ComponentTypeID, std::shared_ptr<BaseCompList>> m_componentArrays;

    };
}