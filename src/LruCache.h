#include <unordered_map>
#include <list>

class LruCache
{
public:
    LruCache(int capacity);

    void put(const std::string& key, const std::string& value);

    std::string get(const std::string& key);

private:
    int capacity;
    std::unordered_map<std::string, std::string> elements;
    std::list<std::unordered_map<std::string, std::string>::iterator> iterators;
};
