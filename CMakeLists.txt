cmake_minimum_required(VERSION 3.10)
project(number-interpreter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(number-interpreter)

if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
    message(STATUS "Building ${PROJECT_NAME} as the main project")

    option(BUILD_TESTS "Build tests" ON)
    option(BUILD_BENCHMARKS "Build benchmarks" ON)
    option(BUILD_EXAMPLE "Build example application" ON)

    if(BUILD_BENCHMARKS)
        add_subdirectory(benchmarks)
    endif()

    if(BUILD_EXAMPLE)
        set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g")
        set(CMAKE_CXX_FLAGS_RELEASE "-Wall -DNDEBUG")

        message(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
        message(STATUS "CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
        message(STATUS "CURRENT ENVIRONMENT: ${CMAKE_BUILD_TYPE}")

        add_executable(main main.cpp)
        target_link_libraries(main number-interpreter)
    endif()

else()
    message(STATUS "${PROJECT_NAME} is being included as a subdirectory in another project. Skipping tests, benchmarks and examples.")
endif()
