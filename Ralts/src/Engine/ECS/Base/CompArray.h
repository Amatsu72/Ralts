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

        void insert(const T &component)
        {
            auto comp = std::find_if(data.begin(), data.end(), [&](const T &c)
                                     { return c.getID() == component.getID(); });

            if (comp != data.end())
            {
                data.push_back(component);
            }
        }

        T &get(const EntityID entity)
        {
            auto comp = std::find_if(data.begin(), data.end(), [&](const T &c)
                                     { return c.getID() == entity; });
            assert(comp != data.end() && "try to get a non-existing component!");
            return *comp;
        }

        void erase(const EntityID entity) override
        {
            auto comp = std::find_if(data.begin(), data.end(), [&](const T &c)
                                     { return c.getID() == entity; });
            if (comp != data.end())
            {
                data.erase(comp);
            }
        }

        std::vector<T> data;
    };
}