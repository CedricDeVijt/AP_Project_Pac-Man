#include "Window.h"
#include "../util/Singleton.h"

Window::Window() {
    window =
        std::make_shared<sf::RenderWindow>(sf::VideoMode(1200, 720), "Pac-Man", sf::Style::Titlebar | sf::Style::Close);
}

shared_ptr<sf::RenderWindow> Window::getWindow() { return window; }