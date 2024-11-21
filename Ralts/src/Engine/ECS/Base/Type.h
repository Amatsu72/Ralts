#pragma once
// #include <cstddef>
#include "../../../pch.h"

namespace Engine
{

    struct Component;
    struct System;

    const size_t MAX_ENTITY_COUNT = 5000;
    const size_t MAX_COMPONENT_COUNT = 32;

    using EntityID = size_t;
    using ComponentTypeID = size_t;
    using SystemTypeID = size_t;
    using EntitySignature = std::set<ComponentTypeID>;

    inline static const ComponentTypeID getRuntimeComponentTypeID()
    {
        static ComponentTypeID typeID = 0u;
        return typeID++;
    }

    inline static const SystemTypeID getRuntimeSystemTypeID()
    {
        static SystemTypeID typeID = 0u;
        return typeID++;
    }

    template <typename T>
    inline static const ComponentTypeID componentType() noexcept
    {
        static_assert((std::is_base_of_v<Component, T> && !std::is_same<Component, T>::value), "invalid template type!");
        static const ComponentTypeID typeID = getRuntimeComponentTypeID();
        return typeID;
    }

    template <typename T>
    inline static const SystemTypeID systemType() noexcept
    {
        static_assert((std::is_base_of_v<System, T> && !std::is_same<System, T>::value), "invalid template type!");
        static const SystemTypeID typeID = getRuntimeSystemTypeID();
        return typeID;
    }

}