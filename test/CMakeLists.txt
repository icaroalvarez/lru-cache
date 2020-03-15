cmake_minimum_required(VERSION 3.5)

set(test_source_files
        main.test.cpp
        LruCache.Test.cpp
        )

add_executable(test_lru_cache
        ${test_source_files}
        )

target_link_libraries(test_lru_cache PRIVATE
        lru_cache
        catch2
        )