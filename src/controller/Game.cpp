#include <iostream>
#include "Game.h"
#include "State.h"
#include "../view/ConcreteFactory.h"
#include "../view/WindowSingleton.h"


Game::Game() : world(std::make_shared<World>(std::make_shared<ConcreteFactory>())),
               stateManager(std::make_shared<StateManager>()) {
    window = WindowSingleton::getInstance().getWindow();
    window->setFramerateLimit(60);
}

Game::~Game() {
    window->close();
}

void Game::run() {
    // Main game loop
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyPressed:
                    // update met input
                    stateManager->getCurrentState()->processInput(event.key.code);
                    break;
                default:
                    break;
            }
        }
        window->clear(sf::Color::Black);
        shared_ptr<State> state = stateManager->getCurrentState();
        state->update();
        state->draw(window);
        window->display();
    }
}