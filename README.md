# lru-cache
C++ implementation of a Least Recent Used Cache (LRU Cache)

## Building the project

### Using CMake

To compile any target in the project, you can directly use CMake. Create a build directory manually and generate the 
Makefiles in it. 

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
```

### Running tests
```bash
./test/test_lru_cache
```

### Running benchmark tests
```bash
./test_benchmarks/test_benchmarks
```

### TODO
* Generalize with key and value templates (now only <std::string, std::string> key values are supported).
