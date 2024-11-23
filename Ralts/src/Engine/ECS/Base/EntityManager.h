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

        void update();
        void render();

        const EntityID addNewEntity();
        void destroyEntity(const EntityID entityID);

        template <typename T, typename... Args>
        void addComponent(const EntityID entityID, Args &&...args);

        template <typename T>
        void removeComponent(const EntityID entityID);

        // template<typename T>
        // T& getComponent(const EntityID entityID) {
        //     assert(entityID < MAX_ENTITY_COUNT && "entityID out of range!");
        //     const ComponentTypeID compType = componentType<T>();
        //     // return

        // }

        template <typename T>
        bool hasComponent(const EntityID entityID) const;

    private:
        EntityID m_entityCount;
        std::queue<EntityID> m_availableEntities;
        std::map<EntityID, EntitySignature> m_entitiySignatures;
        std::map<SystemTypeID, std::unique_ptr<System>> m_registeredSystems;
        std::map<ComponentTypeID, std::shared_ptr<BaseCompList>> m_componentArrays;

    };
}