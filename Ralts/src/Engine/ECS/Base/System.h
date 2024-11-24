#pragma once
#include "Type.h"

namespace Engine
{
    struct System
    {
        System() = default;
        virtual ~System() = default;

        virtual void start() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void destroy() = 0;

        void addEntity(const EntityID entity)
        {
            m_entities.insert(entity);
        }

        void removeEntity(const EntityID entity)
        {
            m_entities.erase(entity);
        }

        const Signature &getSignature() const
        {
            return m_signature;
        }

        template <typename T>
        void addComponentSignature()
        {
            m_signature.insert(componentType<T>());
        }

    private:
        friend class EntityManager;
        Signature m_signature;
        std::set<EntityID> m_entities;
    };
}