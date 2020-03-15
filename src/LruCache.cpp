#include "LruCache.h"

LruCache::LruCache(int capacity)
        :capacity{capacity}
{
}

void LruCache::put(const std::string& key, const std::string& value)
{
    if(elements.size() >= capacity)
    {
        // average of O(1) time complexity for erase operation
        elements.erase(iterators.front());
        // pop front is constant time complexity for a list
        iterators.pop_front();
    }
    const auto itPair{elements.emplace(std::make_pair(key, value))};
    iterators.emplace_back(itPair.first);
}

std::string LruCache::get(const std::string& key)
{
    std::string value;
    const auto& it{elements.find(key)};
    if(it not_eq elements.end())
    {
        value = elements.at(key);
        iterators.remove(it);
        iterators.emplace_back(it);
    }
    return value;
}

