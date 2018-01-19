# PROJECT CONFIGURATION
cmake_minimum_required(VERSION 3.8.2)
project(cpp_rtype)
SET(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES_SERVER
        src/common/gameManager/AEntity.cpp
        src/common/gameManager/Character.cpp
        src/common/gameManager/Enemy.cpp
        src/server/gameManager/GameManager.cpp
        src/common/gameManager/Projectile.cpp
        src/common/gameManager/Room.cpp
        src/server/rtype/CommandManager.cpp
        src/server/rtype/ServerPrompt.cpp
        src/server/ServerCore.cpp
        src/server/main.cpp
        src/server/network/TcpConnections.cpp
        src/server/network/TcpServer.cpp
        src/server/network/TcpHandler.cpp)

set(SOURCE_FILES_CLIENT

        src/client/game/AEntityRenderer.cpp
        src/client/game/EnemyRenderer.cpp
        src/client/game/GameRenderer.cpp
        src/client/game/PlayablePlayer.cpp
        src/client/menu/MainMenu.cpp
        src/client/menu/IMenu.cpp
        src/client/menu/LobbyMenu.cpp
        src/client/menu/LoginMenu.cpp
        src/client/menu/ItemRoomListMenu.cpp
        src/client/menu/RoomListMenu.cpp
        src/client/menu/MenuWindow.cpp
        src/client/game/ProjectileRenderer.cpp
        src/client/game/Star.cpp
        src/client/game/Starfield.cpp
        src/client/main.cpp)

set(SOURCE_FILES_COMMON
        src/common/network/core/Endpoint.cpp
        src/common/network/core/Error.cpp
        src/common/game/MainSystem.cpp
        src/common/game/Renderer.cpp
        src/common/game/RenderSystem.cpp
        src/common/gameManager/Room.cpp
        src/common/gameManager/Projectile.cpp
        src/common/gameManager/Player.cpp
        src/common/gameManager/Character.cpp
        src/common/gameManager/AEntity.cpp
        )

set(SOURCE_FILES_GAME_ENGINE
        src/gameEngine/AIManager.cpp
        src/gameEngine/ColliderManager.cpp
        src/gameEngine/Color.cpp
        src/gameEngine/Font.cpp
        src/gameEngine/Graphics.cpp
        src/gameEngine/Joystick.cpp
        src/gameEngine/Keyboard.cpp
        src/gameEngine/Mathematics.cpp
        src/gameEngine/Mouse.cpp
        src/gameEngine/Music.cpp
        src/gameEngine/MusicManager.cpp
        src/gameEngine/Physic.cpp
        src/gameEngine/Position2D.cpp
        src/gameEngine/Rectangle.cpp
        src/gameEngine/ScriptManager.cpp
        src/gameEngine/SoundSystem.cpp
        src/gameEngine/Sprite.cpp
        src/gameEngine/Image.cpp
        src/gameEngine/Text.cpp
        src/gameEngine/Texture.cpp
        src/gameEngine/TimeManager.cpp
        src/gameEngine/Window.cpp)


set(HEADER_FILES_SERVER
        inc/server/CommandManager.hpp
        inc/server/GameManager.hpp
        inc/server/ServerCore.hpp
        inc/server/ServerPrompt.hpp
        inc/server/network/TcpConnections.hpp
        inc/server/network/TcpServer.hpp
        inc/server/network/TcpHandler.hpp)

set(HEADER_FILES_CLIENT
        inc/client/game/AEntityRenderer.hpp
        inc/client/game/EnemyRenderer.hpp
        inc/client/game/GameRenderer.hpp
        inc/client/game/PlayablePlayer.hpp
        inc/client/menu/MainMenu.hpp
        inc/client/menu/IMenu.hpp
        inc/client/menu/ItemRoomListMenu.hpp
        inc/client/menu/LobbyMenu.hpp
        inc/client/menu/LoginMenu.hpp
        inc/client/menu/MenuState.hpp
        inc/client/menu/MenuWindow.hpp
        inc/client/menu/RoomListMenu.hpp
        inc/client/Entity.hpp
        inc/client/ISystem.hpp
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
        inc/common/network/core/Serializer.hpp
        inc/common/network/packets/APacket.hpp
        inc/common/network/packets/PacketPlayer.hpp
        inc/common/network/packets/PacketRoom.hpp
        inc/common/gameManager/AEntity.hpp
        inc/common/gameManager/Character.hpp
        inc/common/gameManager/Enemy.hpp
        inc/common/gameManager/Room.hpp
        inc/common/gameManager/Projectile.hpp
        inc/common/gameManager/Player.hpp
        )

set(HEADER_FILES_GAME_ENGINE
        inc/gameEngine/AIManager.hpp
        inc/gameEngine/ColliderManager.hpp
        inc/gameEngine/Color.hpp
        inc/gameEngine/Font.hpp
        inc/gameEngine/Graphics.hpp
        inc/gameEngine/IAudio.hpp
        inc/gameEngine/InputManager.hpp
        inc/gameEngine/Joystick.hpp
        inc/gameEngine/Keyboard.hpp
        inc/gameEngine/Mathematics.hpp
        inc/gameEngine/Mouse.hpp
        inc/gameEngine/Music.hpp
        inc/gameEngine/MusicManager.hpp
        inc/gameEngine/Physic.hpp
        inc/gameEngine/Position2D.hpp
        inc/gameEngine/Rectangle.hpp
        inc/gameEngine/ScriptManager.hpp
        inc/gameEngine/SoundSystem.hpp
        inc/gameEngine/Sprite.hpp
        inc/gameEngine/Image.hpp
        inc/gameEngine/Text.hpp
        inc/gameEngine/Texture.hpp
        inc/gameEngine/TimeManager.hpp
        inc/gameEngine/Window.hpp)

include_directories("inc/")
include_directories("inc/gameEngine")
include_directories("inc/common")
include_directories("inc/server")
include_directories("inc/client")
include_directories("inc/client/menu")
include_directories("inc/client/game")
include_directories("inc/common/gameManager")
include_directories("inc/server/network")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

add_executable(r-type-server ${SOURCE_FILES_SERVER} ${HEADER_FILES_SERVER} ${SOURCE_FILES_COMMON} ${HEADER_FILES_COMMON} ${HEADER_FILES_GAME_ENGINE} ${SOURCE_FILES_GAME_ENGINE})
add_executable(r-type-client ${SOURCE_FILES_CLIENT} ${HEADER_FILES_CLIENT} ${SOURCE_FILES_COMMON} ${HEADER_FILES_COMMON} ${HEADER_FILES_GAME_ENGINE} ${SOURCE_FILES_GAME_ENGINE})

# Detect and add Boost

set(Boost_USE_STATIC_LIBS       ON)
set(Boost_USE_MULTITHREADED     ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.66 COMPONENTS system serialization)
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