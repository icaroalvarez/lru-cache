#include <unordered_map>
#include <list>

class LruCache
{
public:
    explicit LruCache(int capacity);

    void put(const std::string& key, const std::string& value);

    std::string get(const std::string& key);

private:
    int capacity;
    using Insertions = std::list<std::string>;
    Insertions insertions;
    using ValueInsertionIterator = std::pair<std::string, Insertions::iterator>;
    std::unordered_map<std::string, ValueInsertionIterator> elements;
};

