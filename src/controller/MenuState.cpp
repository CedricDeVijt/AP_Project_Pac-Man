#include "MenuState.h"
#include "../util/Singleton.h"
#include "../view/FontFactory.h"
#include "../view/SoundEffects.h"
#include "../view/SpriteFactory.h"
#include "LevelState.h"
#include "State.h"

MenuState::MenuState(shared_ptr<StateManager> stateManager) : State(stateManager) {
    Singleton<SoundEffects>::getInstance().playOpeningSong();
}

void MenuState::toLevelState() { stateManager->pushState(std::make_shared<LevelState>(stateManager)); }

void MenuState::draw(shared_ptr<sf::RenderWindow> window) {
    window->draw(Singleton<SpriteFactory>::getInstance().createLogo());

    // High scores
    const std::vector<std::pair<std::string, int>> scores = Score::loadHighScores();
    const sf::Font font = Singleton<FontFactory>::getInstance().getPixelFont();

    sf::Text title("High Scores", font, 40);
    const auto spriteHeight =
        static_cast<int>(Singleton<SpriteFactory>::getInstance().createLogo().getGlobalBounds().height);
    title.setPosition(100, spriteHeight + 20);
    window->draw(title);

    for (int i = 0; i < scores.size(); ++i) {
        sf::Text name(scores[i].first, font, 20);
        name.setPosition(100, spriteHeight + 100 + 30 * i);

        sf::Text score(std::to_string(scores[i].second), font, 20);
        score.setPosition(300, spriteHeight + 100 + 30 * i);

        window->draw(name);
        window->draw(score);
    }

    // draw the instructions
    sf::Text instructions("Press Enter to play", font, 15);
    centerHorizontally(instructions, window->getSize().y - 50);
    window->draw(instructions);
}

void MenuState::processInput(const sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Enter) {
        toLevelState();
    }
}

void MenuState::update() {}
