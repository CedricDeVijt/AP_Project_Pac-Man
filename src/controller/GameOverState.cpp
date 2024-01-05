
#include "GameOverState.h"
#include "../util/Singleton.h"
#include "../view/FontFactory.h"
#include "../view/SoundEffects.h"
#include "../view/SpriteFactory.h"

GameOverState::GameOverState(StateManager* stateManager) : State(stateManager) {
    // stop any background sound that was playing
    Singleton<SoundEffects>::getInstance().stop();
    // play the background sound corresponding to this level
    Singleton<SoundEffects>::getInstance().playGameOver();
}

void GameOverState::processInput(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::Enter:
        toNewGameState();
        break;
    default:
        break;
    }
}

void GameOverState::update() {}

void GameOverState::draw(shared_ptr<sf::RenderWindow> window) {
    // draw the logo
    sf::Sprite sprite = Singleton<SpriteFactory>::getInstance().createLogo();
    window->draw(sprite);

    // draw the title
    sf::Font pacManFont = Singleton<FontFactory>::getInstance().getPacManFont();
    sf::Text title("Game Over", pacManFont, 50);
    centerHorizontally(title, sprite.getGlobalBounds().height + 70);
    window->draw(title);

    // draw the instructions
    sf::Font pixelFont = Singleton<FontFactory>::getInstance().getPixelFont();
    sf::Text instructions("Press Enter to start a new game", pixelFont, 15);
    centerHorizontally(instructions, window->getSize().y - 100);
    window->draw(instructions);
}

void GameOverState::toNewGameState() const {
    // pop the GameOverState state from the stack
    stateManager->popState();
    // pop the LevelState state from the stack
    stateManager->popState();
    // we should now be at the MenuState

    // play the background sound corresponding to this level
    Singleton<SoundEffects>::getInstance().playOpeningSong();
}
