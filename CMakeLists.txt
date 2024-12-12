cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add project sources
add_library(list_manager
    src/list_manager.cpp
    src/list_manager.h
)

# Add executable for the main application
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE list_manager)

# Include AddCatch2.cmake from the cmake directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(AddCatch2)

# Add test executable
add_executable(test_list_manager test/test_list_manager.cpp)
target_link_libraries(test_list_manager PRIVATE list_manager Catch2::Catch2WithMain)

# Enable testing and register tests with Catch2
enable_testing()
include(Catch)
catch_discover_tests(test_list_manager)
