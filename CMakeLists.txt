CMAKE_MINIMUM_REQUIRED(VERSION 3.22.1)
project(AP_Project_Pac-Man)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP_Project_Pac_Man
        main.cpp
        src/model/AbstractFactory.cpp
        src/view/Camera.cpp
        src/model/Collectable.cpp
        src/model/EntityModel.cpp
        src/model/Ghost.cpp
        src/model/PacMan.cpp
        src/model/Random.cpp
        src/model/Observer.cpp
        src/model/Score.cpp
        src/controller/Stopwatch.cpp
        src/model/Subject.cpp
        src/model/Wall.cpp
        src/model/World.cpp

        src/view/ConcreteFactory.cpp
        src/view/EntityView.cpp
        src/controller/Game.cpp
        src/controller/State.cpp
        src/controller/StateManager.cpp
        src/view/SpriteFactory.cpp
        src/view/WindowSingleton.cpp
        src/model/Direction.cpp
)
# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
if(SFML_FOUND)
    target_link_libraries(AP_Project_Pac_Man sfml-graphics sfml-window sfml-system)
else()
    message(FATAL_ERROR "SFML not found")
endif()
