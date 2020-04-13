cmake_minimum_required(VERSION 3.17)

## Settings
set(CMAKE_CXX_STANDARD 11)
project(BadYTDLGui)

add_executable(${PROJECT_NAME} Main.cc)

## ZeroMQ
find_package(cppzmq REQUIRED)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} cppzmq)