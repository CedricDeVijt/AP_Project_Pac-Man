CMAKE_MINIMUM_REQUIRED(VERSION 3.22.1)
project(AP_Project_Pac-Man)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP_Project_Pac_Man
        main.cpp
        LogicLibrary/Wall.cpp
        LogicLibrary/Wall.h
        LogicLibrary/Subject.cpp
        LogicLibrary/EntityModel.cpp
        LogicLibrary/Ghost.cpp
        LogicLibrary/Collectable.cpp
        LogicLibrary/Collectable.h
        LogicLibrary/PacMan.cpp
        LogicLibrary/PacMan.h
        LogicLibrary/Observer.cpp
        LogicLibrary/Observer.h
        LogicLibrary/Score.cpp
        LogicLibrary/Score.h
        LogicLibrary/World.cpp
        LogicLibrary/World.h
        LogicLibrary/Stopwatch.cpp
        LogicLibrary/Stopwatch.h
        LogicLibrary/Camera.cpp
        LogicLibrary/Camera.h
        LogicLibrary/Random.cpp
        LogicLibrary/Random.h
        LogicLibrary/AbstractFactory.cpp
        LogicLibrary/AbstractFactory.h
        GameRepresentation/EntityView.cpp
        GameRepresentation/EntityView.h
        GameRepresentation/ConcreteFactory.cpp
        GameRepresentation/ConcreteFactory.h
        GameRepresentation/State.cpp
        GameRepresentation/State.h
        GameRepresentation/Game.cpp
        GameRepresentation/Game.h
        GameRepresentation/StateManager.cpp
        GameRepresentation/StateManager.h)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
if(SFML_FOUND)
    target_link_libraries(AP_Project_Pac_Man sfml-graphics sfml-window sfml-system)
else()
    message(FATAL_ERROR "SFML not found")
endif()
