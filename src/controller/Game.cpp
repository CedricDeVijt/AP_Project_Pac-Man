#include "Game.h"

#include <SFML/Graphics.hpp>

#include "../util/Singleton.h"
#include "../view/Window.h"
#include "State.h"

Game::Game() {
    window = Singleton<Window>::getInstance().getWindow();
    window->setFramerateLimit(60);
}

void Game::run() const {
    // Main game loop
    while (window->isOpen()) {
        // Event handling loop
        sf::Event event{};
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
        const shared_ptr<State> state = stateManager->getCurrentState();
        state->update();
        state->draw(window);

        // Display the rendered frame
        window->display();
    }
}