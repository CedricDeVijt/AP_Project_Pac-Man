
#include "VictoryState.h"
#include "../util/Singleton.h"
#include "../view/FontFactory.h"
#include "../view/SoundEffects.h"
#include "../view/SpriteFactory.h"

VictoryState::VictoryState(shared_ptr<StateManager> stateManager, int score) : State(stateManager), score(score) {
    // stop any background sound that was playing
    Singleton<SoundEffects>::getInstance().stop();
    // play the background sound corresponding to this level
    Singleton<SoundEffects>::getInstance().playVictory();
}

void VictoryState::toMenuState() const {
    // get the correct state
    stateManager->popState(); // back to level state
    stateManager->popState(); // back to menu state

    // prepare for the menu state
    Singleton<SoundEffects>::getInstance().stop();
    Singleton<SoundEffects>::getInstance().playOpeningSong();
}

void VictoryState::processInput(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::Enter:
        toMenuState();
        break;
    default:
        break;
    }
}

void VictoryState::update() {}

void VictoryState::draw(shared_ptr<sf::RenderWindow> window) {
    // draw the logo
    const sf::Sprite sprite = Singleton<SpriteFactory>::getInstance().createLogo();
    window->draw(sprite);

    // draw the title
    const sf::Font font = Singleton<FontFactory>::getInstance().getPacManFont();
    sf::Text title("Victory !!!", font, 50);
    centerHorizontally(title, sprite.getGlobalBounds().height + 30);
    window->draw(title);

    // draw the score
    const sf::Font pixelFont = Singleton<FontFactory>::getInstance().getPixelFont();
    sf::Text scoreText("Your score: " + std::to_string(score), pixelFont, 30);
    centerHorizontally(scoreText, sprite.getGlobalBounds().height + 180);
    window->draw(scoreText);

    // draw the instructions
    sf::Text instructions("Press Enter to continue", pixelFont, 15);
    centerHorizontally(instructions, window->getSize().y - 100);
    window->draw(instructions);
}
