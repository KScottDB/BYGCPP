cmake_minimum_required(VERSION 3.17)

## Settings
set(CMAKE_CXX_STANDARD 17)
project(BadYTDLGui)

add_executable(${PROJECT_NAME} YoutubeDL.cc Main.cc)

## ZeroMQ
find_package(cppzmq REQUIRED)

## Boost
find_package(Boost REQUIRED)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# magic
TARGET_LINK_LIBRARIES(${PROJECT_NAME} cppzmq ${Boost_Libraries} boost_filesystem boost_system)