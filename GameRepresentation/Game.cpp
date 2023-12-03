#include <iostream>
#include "Game.h"

Game::Game(): window(sf::VideoMode(800, 600), "Pac-Man Game"){}

Game::~Game() {}

void Game::run() {
    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Game logic and rendering go here

        window.clear(); // Clear the window

        // Draw your game objects here

        window.display(); // Display the rendered frame
    }
}


