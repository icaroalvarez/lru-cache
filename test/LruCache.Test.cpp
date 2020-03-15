#include "catch2/catch.hpp"
#include "LruCache.h"

TEST_CASE("Remove the first element inserted when the capacity reach the maximum")
{
    constexpr auto maxCapacity{3};
    LruCache cache(maxCapacity);
    cache.put("1", "one");
    cache.put("2", "two");
    cache.put("3", "three");
    cache.put("4", "four");

    REQUIRE(cache.get("1") == "");
    REQUIRE(cache.get("2") == "two");
    REQUIRE(cache.get("3") == "three");
    REQUIRE(cache.get("4") == "four");
}

TEST_CASE("Remove the first not used element when the capacity reach the maximum")
{
    constexpr auto maxCapacity{3};
    LruCache cache(maxCapacity);
    cache.put("1", "one");
    cache.put("2", "two");
    cache.put("3", "three");
    cache.get("1");
    cache.put("4", "four");

    REQUIRE(cache.get("1") == "one");
    REQUIRE(cache.get("2") == "");
    REQUIRE(cache.get("3") == "three");
    REQUIRE(cache.get("4") == "four");
}