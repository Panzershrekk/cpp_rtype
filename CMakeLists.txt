# Project configuration
cmake_minimum_required(VERSION 3.8)
project(cpp_rtype)
set(CMAKE_CXX_STANDARD 11)

# Server configuration
set(SOURCE_FILES_SERVER src/server/main.cpp)
add_executable(r-type-server ${SOURCE_FILES_SERVER})

# Client configuration
set(SOURCE_FILES_CLIENT src/client/main.cpp)
add_executable(r-type-client ${SOURCE_FILES_CLIENT})