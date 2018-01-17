# Project configuration
cmake_minimum_required(VERSION 3.8)
project(cpp_rtype)
set(CMAKE_CXX_STANDARD 14)

#GameEngineConfiguration
set(SOURCE_FILES_ENGINE src/gameEngine/Physic.cpp
        inc/gameEngine/Physic.hpp
        src/gameEngine/Mathematics.cpp
        src/gameEngine/Position2D.cpp
        src/gameEngine/Rectangle.cpp
        inc/gameEngine/Color.hpp
        src/gameEngine/Color.cpp
        inc/gameEngine/Graphics.hpp
        src/gameEngine/Graphics.cpp
        inc/gameEngine/Sprite.hpp
        src/gameEngine/Sprite.cpp
        src/gameEngine/Texture.cpp
        inc/gameEngine/Texture.hpp
        inc/gameEngine/Window.hpp
        src/gameEngine/Window.cpp
        src/gameEngine/TimeManager.cpp
        inc/gameEngine/AIManager.hpp
        src/gameEngine/AIManager.cpp
        inc/gameEngine/ScriptManager.hpp
        src/gameEngine/ScriptManager.cpp
        inc/gameEngine/InputManager.hpp
        inc/gameEngine/Keyboard.hpp
        src/gameEngine/Keyboard.cpp
        inc/gameEngine/Mouse.hpp
        src/gameEngine/Mouse.cpp
        inc/gameEngine/Joystick.hpp
        src/gameEngine/Joystick.cpp
        inc/gameEngine/ColliderManager.hpp
        src/gameEngine/ColliderManager.cpp
        inc/gameEngine/Font.hpp
        src/gameEngine/Font.cpp
        inc/gameEngine/Text.hpp
        src/gameEngine/Text.cpp
        src/gameEngine/Music.cpp
        src/gameEngine/MusicManager.cpp
        src/gameEngine/SoundSystem.cpp)
include_directories(inc/gameEngine/)

# Server configuration
set(SOURCE_FILES_SERVER src/server/main.cpp
        inc/common/Character.hpp
        inc/common/Player.hpp
        src/common/game/Player.cpp
        inc/common/Enemy.hpp
        src/common/game/Enemy.cpp
        src/common/game/Character.cpp
        inc/common/Projectile.hpp
        src/common/game/MainSystem.cpp
        src/common/game/RenderSystem.cpp
        src/common/game/Renderer.cpp
        inc/server/GameManager.hpp
        src/server/gameManager/GameManager.cpp
        inc/common/AEntity.hpp
        src/common/game/AEntity.cpp
        src/common/game/Projectile.cpp)
include_directories(inc/server/)
include_directories(inc/common/)
add_executable(r-type-server ${SOURCE_FILES_SERVER} ${SOURCE_FILES_ENGINE})

# Client configuration
set(SOURCE_FILES_CLIENT
        src/client/main.cpp
        src/common/game/MainSystem.cpp
        src/common/game/RenderSystem.cpp
        src/common/game/Renderer.cpp
        src/client/menu/MainMenu.cpp
        src/client/menu/MenuWindow.cpp
        inc/client/game/GameRenderer.hpp
        src/client/game/GameRenderer.cpp inc/client/game/PlayablePlayer.hpp src/client/game/PlayablePlayer.cpp)
include_directories(inc/client/)
include_directories(inc/client/menu/)
include_directories(inc/server/)
include_directories(inc/common/)
include_directories(inc/client/game/)

set(CMAKE_BUILD_TYPE Debug)
add_executable(r-type-client ${SOURCE_FILES_CLIENT} ${SOURCE_FILES_ENGINE})

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


