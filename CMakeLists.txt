cmake_minimum_required(VERSION 3.20)

project(measure_duration)

add_library(measure_duration
    measure_duration.hpp
    measure_duration.cpp)

set_target_properties(measure_duration PROPERTIES CXX_STANDARD 23)
target_include_directories(measure_duration PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_measure_duration
    main.cpp)

set_target_properties(test_measure_duration PROPERTIES CXX_STANDARD 23)

target_link_libraries(test_measure_duration PUBLIC measure_duration)

