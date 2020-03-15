cmake_minimum_required(VERSION 3.5)

set(test_source_files
        main.test.cpp
        Benchmark.Test.cpp
        )

add_executable(test_benchmarks
        ${test_source_files}
        )

target_link_libraries(test_benchmarks PRIVATE
        lru_cache
        catch2
        )