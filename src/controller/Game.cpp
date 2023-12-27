#include <iostream>
#include "Game.h"
#include "State.h"
#include <stdexcept>
#include "../view/ConcreteFactory.h"


Game::Game() : window(std::make_shared<sf::RenderWindow>(sf::VideoMode(600, 800), "Pac-Man",
                                                         sf::Style::Titlebar | sf::Style::Close)),
               world(std::make_shared<World>(std::make_shared<ConcreteFactory>())),
               stateManager(std::make_shared<StateManager>()) {
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
        shared_ptr<State> state = stateManager->getCurrentState();
        state->update();
        window->clear(sf::Color::Black);
        state->draw(window);
        window->display();
    }
}
