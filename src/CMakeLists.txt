cmake_minimum_required(VERSION 3.5)

set(source_files
        LruCache
        )

add_library(lru_cache
        ${source_files}
        )

target_include_directories(lru_cache INTERFACE .)