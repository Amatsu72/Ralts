#include "CompArray.h"

namespace Engine {

    template <typename T>
    void CompList<T>::insert(const T &component) {
        auto comp = std::find_if(data.begin(), data.end(), [&](const T &c) { return c.getID() == component.getID(); });

        if (comp != data.end())
        {
            data.push_back(component);
        }
    }

    template <typename T>
    T& CompList<T>::get(const EntityID entity)
    {
        auto comp = std::find_if(data.begin(), data.end(), [&](const T &c)
                                    { return c.getID() == entity; });
        assert(comp != data.end() && "try to get a non-existing component!");
        return *comp;
    }
    template <typename T>
    void CompList<T>::erase(const EntityID entity) {
        auto comp = std::find_if(data.begin(), data.end(), [&](const T &c) { return c.getID() == entity; });
        if (comp != data.end())
        {
            data.erase(comp);
        }
    }   
}