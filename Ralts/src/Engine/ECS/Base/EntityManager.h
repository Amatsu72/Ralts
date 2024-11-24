#pragma once

#include "Component.h"
#include "System.h"
#include "CompArray.h"

namespace Engine
{

    class EntityManager
    {
    public:
        EntityManager() : m_entityCount(0)
        {
            for (EntityID entity = 0u; entity < MAX_ENTITY_COUNT; ++entity)
            {
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

        template <typename T, typename... Args>
        void addComponent(const EntityID entityID, T &component);

        template <typename T>
        void removeComponent(const EntityID entityID);

        template <typename T>
        T &getComponent(const EntityID entityID);

        template <typename T>
        bool hasComponent(const EntityID entityID);
        
        template <typename T>
        void registerSystem();

        template <typename T>
        void unregisterSystem();
    private:
        template <typename T>
        void addCompList();
        template <typename T>
        std::shared_ptr<CompList<T>> &getCompList();

        void addEntitySignature(const EntityID entityID);
        std::shared_ptr<Signature> &getEntitySignature(const EntityID entityID);
        void updateEnityTargetSystem(const EntityID entityID);
        void addEntiyToSystem(const EntityID entityID, System &system);
        bool belongtoSystem(const EntityID entityID, const Signature &systemSignature);

        EntityID m_entityCount;
        std::queue<EntityID> m_availableEntities;
        std::map<EntityID, std::shared_ptr<Signature>> m_entitiySignatures;
        std::map<SystemTypeID, std::unique_ptr<System>> m_registeredSystems;
        std::map<ComponentTypeID, std::shared_ptr<BaseCompList>> m_componentArrays;
    };
}