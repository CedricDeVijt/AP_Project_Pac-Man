#include <iostream>
#include "Game.h"
#include "../model/State.h"
#include <stdexcept>


Game::Game() : window(sf::VideoMode(600, 800), "Pac-Man", sf::Style::Titlebar | sf::Style::Close){
    window.setFramerateLimit(60);

//    setupGame();
}

Game::~Game() {}

void Game::run() {
    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    // TODO handle key presses
                    // update met input
                    break;
                default:
                    std::cout << "Unhandled event" << std::endl;
                    break;
            }
        }
        // TODO update game
        std::cout << "Update" << std::endl;
        // update zonder input
    }
}

void Game::setupGame() {
    // Load sprites
    sf::Image spritesImage;
    try {
        if (!spritesImage.loadFromFile("../src/Sprites.png")) {
            throw std::runtime_error("Error loading sprites");
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    // Load fonts$

    try {
        if (!pacManFont.loadFromFile("../src/pacManFont.ttf")) {
            throw std::runtime_error("Error loading font");
        }
        if (!pixelFont.loadFromFile("../src/pixelFont.ttf")) {
            throw std::runtime_error("Error loading font");
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }





//    // Create states
//    shared_ptr <State> menuState = make_shared<MenuState>(MenuState(window, spritesImage, font));
//    shared_ptr <State> gameState = make_shared<GameState>(GameState(window, spritesImage, font));
//    shared_ptr <State> gameOverState = make_shared<GameOverState>(GameOverState(window, spritesImage, font));
//
//    // Add states to state manager
//    stateManager.addState(menuState);
//    stateManager.addState(gameState);
//    stateManager.addState(gameOverState);
//
//    // Set initial state
//    stateManager.changeState(sf::Keyboard::Enter);

}


