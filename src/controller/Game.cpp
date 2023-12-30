#include <iostream>
#include "Game.h"
#include "State.h"
#include "../view/ConcreteFactory.h"
#include "../view/WindowSingleton.h"


Game::Game() : world(std::make_shared<World>(std::make_shared<ConcreteFactory>())),
               stateManager(std::make_shared<StateManager>()) {
    window = WindowSingleton::getInstance().getWindow();
    window->setFramerateLimit(60); // TODO remove this to improve speed
}

Game::~Game() {
    window->close();
}

void Game::run() {
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
        // Clear the window with a black background
        window->clear(sf::Color::Black);

        // Get the current state and update/draw it
        shared_ptr<State> state = stateManager->getCurrentState();
        state->update();
        state->draw(window);

        // Display the rendered frame
        window->display();
    }
}