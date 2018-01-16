# Project configuration
cmake_minimum_required(VERSION 3.8)
project(cpp_rtype)
set(CMAKE_CXX_STANDARD 11)

# Server configuration
set(SOURCE_FILES_SERVER src/server/main.cpp)
add_executable(r-type-server ${SOURCE_FILES_SERVER})

# Client configuration
set(SOURCE_FILES_CLIENT src/client/main.cpp src/gameEngine/Physic.cpp inc/gameEngine/Physic.hpp src/gameEngine/Mathematics.cpp src/gameEngine/Position2D.cpp src/gameEngine/Rectangle.cpp inc/gameEngine/Color.hpp src/gameEngine/Color.cpp inc/gameEngine/Graphics.hpp src/gameEngine/Graphics.cpp inc/gameEngine/Sprite.hpp src/gameEngine/Sprite.cpp src/gameEngine/Texture.cpp inc/gameEngine/Texture.hpp inc/gameEngine/Window.hpp src/gameEngine/Window.cpp src/gameEngine/TimeManager.cpp inc/gameEngine/AIManager.hpp src/gameEngine/AIManager.cpp inc/gameEngine/ScriptManager.hpp src/gameEngine/ScriptManager.cpp inc/gameEngine/InputManager.hpp inc/gameEngine/Keyboard.hpp src/gameEngine/Keyboard.cpp inc/gameEngine/Mouse.hpp src/gameEngine/Mouse.cpp inc/gameEngine/Joystick.hpp src/gameEngine/Joystick.cpp inc/gameEngine/ColliderManager.hpp src/gameEngine/ColliderManager.cpp inc/gameEngine/Font.hpp src/gameEngine/Font.cpp inc/gameEngine/Text.hpp src/gameEngine/Text.cpp inc/client/menu/MenuWindow.hpp src/client/menu/MenuWindow.cpp inc/client/menu/MenuState.hpp inc/client/menu/MainMenu.hpp src/client/menu/MainMenu.cpp inc/client/menu/LoginMenu.hpp src/client/menu/LoginMenu.cpp src/client/menu/RoomListMenu.cpp inc/client/menu/RoomListMenu.hpp inc/client/menu/LobbyMenu.hpp src/client/menu/LobbyMenu.cpp inc/client/menu/IMenu.hpp)
include_directories(inc/)
include_directories(inc/client/menu)
include_directories(inc/gameEngine)
set(CMAKE_BUILD_TYPE Debug)
add_executable(r-type-client ${SOURCE_FILES_CLIENT})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(r-type-client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


