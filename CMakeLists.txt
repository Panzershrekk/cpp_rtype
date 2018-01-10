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
set(SOURCE_FILES_CLIENT src/client/main.cpp)
add_executable(r-type ${SOURCE_FILES_CLIENT})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(r-type ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

