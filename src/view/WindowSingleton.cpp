#include "WindowSingleton.h"

// Define the static instance of the singleton
WindowSingleton::WindowSingleton() {
   window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1200, 1600), "Pac-Man", sf::Style::Titlebar | sf::Style::Close);
}

WindowSingleton& WindowSingleton::getInstance() {
    static WindowSingleton instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}

shared_ptr<sf::RenderWindow> WindowSingleton::getWindow() {
    return window;
}