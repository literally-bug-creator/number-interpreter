set(BENCHMARK_USE_BUNDLED_GTEST OFF)
set(BENCHMARK_ENABLE_TESTING OFF)

add_subdirectory(third-party/benchmark)
include_directories(${benchmark_SOURCE_DIR}/include)


file(GLOB_RECURSE BENCHMARK_SOURCES "./benchmarks/*.cpp")
add_executable(run_benchmark ${BENCHMARK_SOURCES})

target_link_libraries(run_benchmark benchmark::benchmark number-interpreter)

add_test(NAME run_benchmark COMMAND run_benchmark)
