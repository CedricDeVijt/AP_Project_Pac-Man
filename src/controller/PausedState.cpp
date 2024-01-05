#include "PausedState.h"
#include "StateManager.h"
#include "Stopwatch.h"
#include "../view/SpriteFactory.h"
#include "../view/FontFactory.h"
#include "../view/SoundEffects.h"
#include "../util/Singleton.h"

PausedState::PausedState(StateManager* stateManager) : State(stateManager) {
    Stopwatch::getInstance().pause();
    Singleton<SoundEffects>::getInstance().pause();
}

void PausedState::toLevelState() const {
    // get the previous level state
    stateManager->popState();

    // restart the state
    Stopwatch::getInstance().unPause();
    Singleton<SoundEffects>::getInstance().unpause();
}

void PausedState::processInput(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Escape:
            toLevelState();
            break;
        default:
            break;
    }
}

void PausedState::update() {}

void PausedState::draw(shared_ptr<sf::RenderWindow> window) {
    // draw the logo
    const sf::Sprite sprite = Singleton<SpriteFactory>::getInstance().createLogo();
    window->draw(sprite);

    // draw the title
    const sf::Font font = Singleton<FontFactory>::getInstance().getPixelFont();
    sf::Text title("Game Paused", font, 50);
    centerHorizontally(title, sprite.getGlobalBounds().height + 70);
    window->draw(title);

    // draw the instructions
    sf::Text instructions("Press Escape to continue", font, 15);
    centerHorizontally(instructions, window->getSize().y - 100);
    window->draw(instructions);
}


