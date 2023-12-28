#include <iostream>
#include "Game.h"
#include "State.h"
#include <stdexcept>
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
        shared_ptr<State> state = stateManager->getCurrentState();
        state->update();
        window->clear(sf::Color::Black);
        state = stateManager->getCurrentState();
        state->update();
        state->draw(window);
        window->display();
    }
}

//void Game::setupGame() {
//    // Load sprites
//    sf::Image spritesImage;
//    try {
//        if (!spritesImage.loadFromFile("../src/Sprites.png")) {
//            throw std::runtime_error("Error loading sprites");
//        }
//    }
//    catch (const std::exception &e) {
//        std::cerr << "Exception: " << e.what() << std::endl;
//    }
//
//
//    // Load fonts
//
//    try {
//        if (!pacManFont.loadFromFile("../src/pacManFont.ttf")) {
//            throw std::runtime_error("Error loading font");
//        }
//        if (!pixelFont.loadFromFile("../src/pixelFont.ttf")) {
//            throw std::runtime_error("Error loading font");
//        }
//    }
//    catch (const std::exception &e) {
//        std::cerr << "Exception: " << e.what() << std::endl;
//    }
//
//
//
//
//
////    // Create states
////    shared_ptr <State> menuState = make_shared<MenuState>(MenuState(window, spritesImage, font));
////    shared_ptr <State> gameState = make_shared<GameState>(GameState(window, spritesImage, font));
////    shared_ptr <State> gameOverState = make_shared<GameOverState>(GameOverState(window, spritesImage, font));
////
////    // Add states to state manager
////    stateManager.addState(menuState);
////    stateManager.addState(gameState);
////    stateManager.addState(gameOverState);
////
////    // Set initial state
////    stateManager.changeState(sf::Keyboard::Enter);
//
//}
//

