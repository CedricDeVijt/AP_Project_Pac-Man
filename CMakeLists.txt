CMAKE_MINIMUM_REQUIRED(VERSION 3.22.1)
project(AP_Project_Pac-Man)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP_Project_Pac_Man
        main.cpp
        LogicLibrary/AbstractFactory.cpp
        LogicLibrary/Camera.cpp
        LogicLibrary/Collectable.cpp
        LogicLibrary/EntityModel.cpp
        LogicLibrary/Ghost.cpp
        LogicLibrary/PacMan.cpp
        LogicLibrary/Random.cpp
        LogicLibrary/Observer.cpp
        LogicLibrary/Score.cpp
        LogicLibrary/State.cpp
        LogicLibrary/Stopwatch.cpp
        LogicLibrary/Subject.cpp
        LogicLibrary/Wall.cpp
        LogicLibrary/World.cpp

        GameRepresentation/ConcreteFactory.cpp
        GameRepresentation/EntityView.cpp
        GameRepresentation/Game.cpp
        GameRepresentation/State.cpp
        GameRepresentation/StateManager.cpp
)
# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
if(SFML_FOUND)
    target_link_libraries(AP_Project_Pac_Man sfml-graphics sfml-window sfml-system)
else()
    message(FATAL_ERROR "SFML not found")
endif()
