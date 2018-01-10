# Project configuration
cmake_minimum_required(VERSION 3.8)
project(cpp_rtype)
set(CMAKE_CXX_STANDARD 11)

# Common configuration
set(SOURCE_FILES_COMMON )
include_directories("inc/lib")
include_directories("inc/common")

# Server configuration
set(SOURCE_FILES_SERVER
        src/server/main.cpp inc/lib/Serializer.hpp)
include_directories("inc/server")
add_executable(r-type-server ${SOURCE_FILES_SERVER} ${SOURCE_FILES_COMMON})

# Client configuration
set(SOURCE_FILES_CLIENT
        src/client/main.cpp)
include_directories("inc/client")
add_executable(r-type-client ${SOURCE_FILES_CLIENT} ${SOURCE_FILES_COMMON})