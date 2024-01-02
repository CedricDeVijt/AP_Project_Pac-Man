# Minimum required version
cmake_minimum_required(VERSION 3.22.1)

# Project name
project(GameLogicLib)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)

# Create the game logic library
add_library(GameLogicLib STATIC
        src/model/AbstractFactory.cpp
        src/model/Collectable.cpp
        src/model/EntityModel.cpp
        src/model/Ghost.cpp
        src/model/PacMan.cpp
        src/model/Random.cpp
        src/model/Observer.cpp
        src/model/Score.cpp
        src/model/Subject.cpp
        src/model/Wall.cpp
        src/model/World.cpp
        src/model/Direction.cpp
        src/model/Stopwatch.cpp
)

# Specify include directories for the library
target_include_directories(GameLogicLib PUBLIC src/model)
