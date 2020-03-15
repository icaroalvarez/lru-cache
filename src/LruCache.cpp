#include "LruCache.h"

LruCache::LruCache(int capacity)
        :capacity{capacity}
{
}

void LruCache::put(const std::string& key, const std::string& value)
{
    if(elements.size() >= capacity)
    {
        keyInsertions.erase(insertions.front()->first);
        // average of O(1) time complexity for erase operation
        elements.erase(insertions.front());
        // pop front is constant time complexity for a list
        insertions.pop_front();
    }
    const auto itPair{elements.emplace(std::make_pair(key, value))};
    insertions.emplace_back(itPair.first);

    auto insertionIt{std::prev(insertions.end())};
    keyInsertions.emplace(std::make_pair(key, insertionIt));
}

std::string LruCache::get(const std::string& key)
{
    std::string value;
    const auto& it{elements.find(key)};
    //auto test_value = it->second;
    if(it not_eq elements.end())
    {
        value = elements.at(key);

        auto insertionsIt = keyInsertions.find(key);
        insertions.erase(insertionsIt->second);
        insertions.emplace_back(it);
        keyInsertions.erase(insertionsIt);

        auto insertionIt = std::prev(insertions.end());
        keyInsertions.emplace(std::make_pair(key, insertionIt));
    }
    return value;
}

