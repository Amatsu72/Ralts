#pragma once
#include "Type.h"

namespace Engine
{
    class BaseCompList
    {
    public:
        BaseCompList() = default;
        virtual ~BaseCompList() = default;
        virtual void erase(const EntityID entity) {}
    };

    template <typename T>
    class CompList : public BaseCompList
    {
    public:
        CompList() = default;
        virtual ~CompList() = default;

        void insert(const T &component);
        T &get(const EntityID entity);
        void erase(const EntityID entity) override;

        std::vector<T> data;
    };
    
}