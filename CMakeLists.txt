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
add_executable(main main.cpp)
target_link_libraries(main PRIVATE list_manager)

# Add test executable
enable_testing()
add_executable(test_list_manager test/test_list_manager.cpp)
target_link_libraries(test_list_manager PRIVATE list_manager)

# Add test
add_test(NAME ListManagerTests COMMAND test_list_manager)
