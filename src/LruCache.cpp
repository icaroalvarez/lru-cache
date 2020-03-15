#include "LruCache.h"

LruCache::LruCache(int capacity)
        :capacity{capacity}
{
}

void LruCache::put(const std::string& key, const std::string& value)
{
    if(elements.size() >= capacity)
    {
        elements.erase(insertions.front()); // O(1)
        insertions.pop_front(); // O(1)
    }
    insertions.emplace_back(key); // O(1)
    const auto lastIterator{std::prev(insertions.end())};
    auto valueInsertionIterator{std::make_pair(value, lastIterator)};
    auto element{std::make_pair(key, std::move(valueInsertionIterator))};
    elements.emplace(std::move(element)); // average O(1), worst case O(N)
}

std::string LruCache::get(const std::string& key)
{
    std::string value;
    const auto& it{elements.find(key)}; // average O(1), worst case O(N)
    if(it not_eq elements.end())
    {
        auto& elementPair{elements.at(key)};
        value = elementPair.first;

        insertions.erase(elementPair.second); // O(1)
        insertions.emplace_back(key); // O(1)
        const auto& insertionIt{std::prev(insertions.end())};
        elementPair.second = insertionIt;
    }
    return value;
}

