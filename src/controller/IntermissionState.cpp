
#include "IntermissionState.h"
#include "../util/Singleton.h"
#include "../view/FontFactory.h"
#include "../view/SoundEffects.h"
#include "../view/SpriteFactory.h"
#include "LevelState.h"
#include "StateManager.h"
#include "Stopwatch.h"

IntermissionState::IntermissionState(shared_ptr<StateManager> stateManager, int level) : State(stateManager), level(level) {
    Singleton<SoundEffects>::getInstance().stop();
    Singleton<SoundEffects>::getInstance().playIntermission();
}

void IntermissionState::toNextLevelState() const {
    // pop the intermission state from the stack
    stateManager->popState();

    // update the LevelState to the next level
    const std::shared_ptr<LevelState> state = std::dynamic_pointer_cast<LevelState>(stateManager->getCurrentState());
    state->toNextLevelState();

    // start the state
    Stopwatch::getInstance().restart();
    Singleton<SoundEffects>::getInstance().stop();
    Singleton<SoundEffects>::getInstance().playToyBoxWorld();
}

void IntermissionState::processInput(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::Enter:
        toNextLevelState();
        break;
    default:
        break;
    }
}

void IntermissionState::update() {}

void IntermissionState::draw(shared_ptr<sf::RenderWindow> window) {
    // draw the logo
    const sf::Sprite sprite = Singleton<SpriteFactory>::getInstance().createLogo();
    window->draw(sprite);

    // draw the title
    const sf::Font font = Singleton<FontFactory>::getInstance().getPixelFont();
    const std::string titleText = "Level " + std::to_string(level + 1) + " Completed";
    sf::Text title(titleText, font, 50);
    centerHorizontally(title, sprite.getGlobalBounds().height + 70);
    window->draw(title);

    // draw the instructions
    sf::Text instructions("Press Enter to continue", font, 15);
    centerHorizontally(instructions, window->getSize().y - 100);
    window->draw(instructions);
}
