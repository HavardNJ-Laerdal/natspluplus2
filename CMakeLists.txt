cmake_minimum_required(VERSION 3.22)

# Set the project name
project(natsplusplus2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

# Find the QtCore library
find_package(Qt5 COMPONENTS Core Network REQUIRED)

# Include the Qt5 directories
include_directories(${Qt5Core_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/qt-nats)

# Add an executable
add_executable(natsplusplus2 main.cpp NatsMessageBusThingy.cpp NatsMessageBusThingy.h MessageBusInterface.h qt-nats/natsclient.h)

# Link the QtCore library to the executable
target_link_libraries(natsplusplus2 Qt5::Core Qt5::Network ws2_32)
