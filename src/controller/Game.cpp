#include "Game.h"
#include "../view/SoundEffects.h"
#include "../view/WindowSingleton.h"
#include "State.h"
#include <iostream>

Game::Game() : stateManager(std::make_shared<StateManager>()) {
    window = WindowSingleton::getInstance().getWindow();
    window->setFramerateLimit(60);
}

Game::~Game() { window->close(); }

void Game::run() {
    SoundEffects::getInstance().playOpeningSong();
    // Main game loop
    while (window->isOpen()) {
        // Event handling loop
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                // Close the window if the close event is triggered
                window->close();
                break;
            case sf::Event::KeyPressed:
                // Process key presses and notify the current state
                stateManager->getCurrentState()->processInput(event.key.code);
                break;
            default:
                // Ignore other event types
                break;
            }
        }
        // Clear the window by setting a black background
        window->clear(sf::Color::Black);

        // Get the current state and update/draw it
        shared_ptr<State> state = stateManager->getCurrentState();
        state->update();
        state->draw(window);

        // Display the rendered frame
        window->display();
    }
}