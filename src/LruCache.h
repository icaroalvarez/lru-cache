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
    std::unordered_map<std::string, std::string> elements;
    using ElementsIterator = std::unordered_map<std::string, std::string>::iterator;
    using Insertions = std::list<ElementsIterator>;
    Insertions insertions;
    std::unordered_map<std::string, Insertions::iterator> keyInsertions;
};

