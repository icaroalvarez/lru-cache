#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch2/catch.hpp>
#include <LruCache.h>

using namespace std::string_literals;

TEST_CASE("Inserting new element when cache is full with 1000 elements")
{
    constexpr auto totalElements{1000};

    LruCache cache{totalElements};
    for(int i=0; i < totalElements; i++)
    {
        cache.put(std::to_string(i), std::to_string(i));
    }

    BENCHMARK("inserting new element with cache not full")
                {
                    return cache.put("element_key", "element_value");
                };

    BENCHMARK("inserting new element with cache full")
                {
                    return cache.put("new_element_key", "new_element_value");
                };

    BENCHMARK("get element")
                {
                    return cache.get("500");
                };
}