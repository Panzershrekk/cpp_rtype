# Project configuration
cmake_minimum_required(VERSION 3.8)
project(cpp_rtype)
set(CMAKE_CXX_STANDARD 11)

# Server configuration
set(SOURCE_FILES_SERVER src/server/main.cpp)
add_executable(r-type-server ${SOURCE_FILES_SERVER})

# Client configuration
set(SOURCE_FILES_CLIENT src/client/main.cpp src/gameEngine/Physic.cpp inc/gameEngine/Physic.hpp src/gameEngine/Mathematics.cpp src/gameEngine/Position2D.cpp src/gameEngine/Rectangle.cpp src/gameEngine/TimeManager.cpp src/gameEngine/Time.cpp)
include_directories(inc/gameEngine/)
add_executable(r-type-client ${SOURCE_FILES_CLIENT})

set(SOURCE_FILE main.cpp inc/gameEngine/Mathematics.hpp inc/gameEngine/Position2D.hpp inc/gameEngine/Rectangle.hpp inc/gameEngine/TimeManager.hpp inc/gameEngine/Time.hpp)
add_executable(r-type ${SOURCE_FILE})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(r-type ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

