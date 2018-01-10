# PROJECT CONFIGURATION
cmake_minimum_required(VERSION 3.8.2)
project(cpp_rtype)
set(CMAKE_CXX_STANDARD 11)

# SERVER FILES
set(SOURCE_FILES_SERVER
        src/server/main.cpp)

# CLIENT FILES
set(SOURCE_FILES_CLIENT src/client/main.cpp)

# COMMON FILES NETWORK CORE
set(SOURCE_FILES_COMMON_NETWORK_CORE
        src/common/network/core/UdpConnection.cpp
        src/common/network/core/Endpoint.cpp)

# EXECUTABLES
add_executable(r-type-server ${SOURCE_FILES_SERVER} ${SOURCE_FILES_COMMON_NETWORK_CORE})
add_executable(r-type ${SOURCE_FILES_CLIENT} ${SOURCE_FILES_COMMON_NETWORK_CORE})

# INCLUDES
include_directories("inc")

# Detect and add Boost into server and r-type
set(Boost_USE_STATIC_LIBS       ON) # only find static libs
set(Boost_USE_MULTITHREADED     ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.65.1 COMPONENTS system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(r-type ${Boost_LIBRARIES})
    target_link_libraries(r-type-server ${Boost_LIBRARIES})
endif()


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(r-type ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

