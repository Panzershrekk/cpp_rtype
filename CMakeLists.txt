# PROJECT CONFIGURATION
cmake_minimum_required(VERSION 3.8.2)
project(cpp_rtype)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

# Server configuration
set(SOURCE_FILES_SERVER
        src/server/gameManager/AEntity.cpp
        src/server/gameManager/Character.cpp
        src/server/gameManager/Enemy.cpp
        src/server/gameManager/GameManager.cpp
        src/server/gameManager/Player.cpp
        src/server/gameManager/Projectile.cpp
        src/server/rtype/commandManager.cpp
        src/server/rtype/Room.cpp
        src/server/rtype/ServerPrompt.cpp
        src/server/ServerCore.cpp
        src/server/main.cpp)

# Client configuration
set(SOURCE_FILES_CLIENT
        src/client/main.cpp
        src/client/menu/MenuWindow.cpp
        src/client/menu/MainMenu.cpp
        src/client/menu/IMenu.cpp
        src/client/menu/LoginMenu.cpp
        src/client/menu/RoomListMenu.cpp
        src/client/menu/LobbyMenu.cpp
        src/gameEngine/Physic.cpp
        src/gameEngine/Mathematics.cpp
        src/gameEngine/Position2D.cpp
        src/gameEngine/Rectangle.cpp
        src/gameEngine/Color.cpp
        src/gameEngine/Graphics.cpp
        src/gameEngine/Sprite.cpp
        src/gameEngine/Texture.cpp
        src/gameEngine/Window.cpp
        src/gameEngine/Text.cpp
        src/gameEngine/Mouse.cpp
        src/gameEngine/Font.cpp
        src/client/menu/ItemRoomListMenu.cpp)
set(INCLUDE_FILE_CLIENT
        inc/client/MainSystem.hpp
        inc/client/Renderer.hpp
        inc/client/RenderSystem.hpp
        inc/client/game/Star.hpp
        inc/client/game/Starfield.hpp
        inc/client/game/ProjectileRenderer.hpp)

set(HEADER_FILES_COMMON
       inc/common/network/core/Endpoint.hpp
       inc/common/network/core/Error.hpp
       inc/common/network/core/Exception.hpp
        inc/common/network/core/UdpConnection.hpp
        inc/common/network/serialization/Serializer.hpp
        )

set(HEADER_FILES_GAME_ENGINE
        inc/gameEngine/AIManager.hpp
        inc/gameEngine/ColliderManager.hpp
        inc/gameEngine/Color.hpp
        inc/gameEngine/Graphics.hpp
        inc/gameEngine/Sprite.hpp
        inc/gameEngine/Texture.hpp
        inc/gameEngine/TimeManager.hpp
        inc/gameEngine/Window.hpp inc/gameEngine/Image.hpp src/gameEngine/Image.cpp
        inc/gameEngine/Window.hpp
        inc/gameEngine/Mouse.hpp
        inc/gameEngine/Text.hpp
        inc/gameEngine/Font.hpp
        inc/client/menu/ItemRoomListMenu.hpp)
include_directories(inc/client
        inc/gameEngine
        inc/client/menu)
add_executable(r-type-client ${SOURCE_FILES_CLIENT} ${INCLUDE_FILE_CLIENT})


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
add_executable(r-type-server ${SOURCE_FILES_SERVER} ${HEADER_FILES_SERVER} ${HEADER_FILES_GAME_ENGINE} ${SOURCE_FILES_GAME_ENGINE} ${SOURCE_FILES_COMMON} ${HEADER_FILES_COMMON})
add_executable(r-type-client ${SOURCE_FILES_CLIENT} ${HEADER_FILES_CLIENT} ${HEADER_FILES_GAME_ENGINE} ${SOURCE_FILES_GAME_ENGINE} ${SOURCE_FILES_COMMON} ${HEADER_FILES_COMMON})

# Detect and add Boost

set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_MULTITHREADED     ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.66 COMPONENTS system thread)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(r-type-client ${Boost_LIBRARIES})
    target_link_libraries(r-type-server ${Boost_LIBRARIES})
endif()

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(r-type-client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(r-type-server ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()