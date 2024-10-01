cmake_minimum_required(VERSION 3.10)

# Set the project name
project(NatsPlusPlus)

# Find the QtCore library
find_package(Qt5 COMPONENTS Core REQUIRED)

# Link the QtCore library to the executable
target_link_libraries(Qt5::Core)

# Add an executable
add_executable(main main.cpp)