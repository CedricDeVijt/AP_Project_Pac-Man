# Minimum required version
cmake_minimum_required(VERSION 3.22.1)

# Project name
project(AP_Project_Pac-Man)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Include the game logic library CMake file
include(src/model/CMakeLists.txt)

# Create the executable and link with the library
add_executable(AP_Project_Pac_Man
        main.cpp
        src/view/ConcreteFactory.cpp
        src/view/EntityView.cpp
        src/view/Camera.cpp
        src/view/FontFactory.cpp
        src/view/SpriteFactory.cpp
        src/view/Window.cpp
        src/view/SoundEffects.cpp
        src/view/SoundEffectObserver.cpp
        src/view/GhostView.cpp
        src/view/FruitView.cpp
        src/view/WallView.cpp
        src/view/CoinView.cpp
        src/view/PacManView.cpp

        src/controller/Game.cpp
        src/controller/State.cpp
        src/controller/MenuState.cpp
        src/controller/StateManager.cpp
        src/controller/LevelState.cpp
        src/controller/LevelState.h
        src/controller/PausedState.cpp
        src/controller/PausedState.h
        src/controller/VictoryState.cpp
        src/controller/VictoryState.h src/controller/GameOverState.cpp src/controller/GameOverState.h src/controller/IntermissionState.cpp src/controller/IntermissionState.h)

# Link the executable with the game logic library
target_link_libraries(AP_Project_Pac_Man GameLogicLib)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
if (SFML_FOUND)
    target_link_libraries(AP_Project_Pac_Man sfml-graphics sfml-window sfml-system sfml-audio)
else ()
    message(FATAL_ERROR "SFML not found")
endif ()