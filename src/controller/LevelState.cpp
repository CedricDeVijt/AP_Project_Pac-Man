#include "LevelState.h"
#include "../util/Singleton.h"
#include "../view/ConcreteFactory.h"
#include "../view/FontFactory.h"
#include "../view/SoundEffectObserver.h"
#include "../view/SoundEffects.h"
#include "GameOverState.h"
#include "IntermissionState.h"
#include "PausedState.h"
#include "StateManager.h"
#include "Stopwatch.h"
#include "VictoryState.h"

LevelState::LevelState(StateManager* stateManager) : LevelState(stateManager, 0, std::make_shared<Score>()) {}

LevelState::LevelState(StateManager* stateManager, int level, const shared_ptr<Score>& score)
    : State(stateManager), score(score), level(level) {
    // stop any background sound that was playing
    Singleton<SoundEffects>::getInstance().stop();

    // prepare the state
    auto factory = std::make_shared<ConcreteFactory>(level);
    world = std::make_shared<World>(factory, level);
    world->registerObserver(score);
    world->registerObserver(std::make_shared<SoundEffectObserver>());

    // start the level
    Stopwatch::getInstance().start();
    Singleton<SoundEffects>::getInstance().playToyBoxWorld();
    world->update();
}

void LevelState::toVictoryState() {
    stateManager->pushState(std::make_shared<VictoryState>(stateManager, score->getCurrentScore()));
}

void LevelState::toPausedState() { stateManager->pushState(std::make_shared<PausedState>(stateManager)); }

void LevelState::toGameOverState() { stateManager->pushState(std::make_shared<GameOverState>(stateManager)); }

void LevelState::toIntermissionState() {
    stateManager->pushState(std::make_shared<IntermissionState>(stateManager, level));
}

void LevelState::processInput(sf::Keyboard::Key key) {
    switch (key) {
    case sf::Keyboard::Escape:
        toPausedState();
        break;
    case sf::Keyboard::Up:
        world->setDirectionPacMan(Direction::UP);
        break;
    case sf::Keyboard::Down:
        world->setDirectionPacMan(Direction::DOWN);
        break;
    case sf::Keyboard::Left:
        world->setDirectionPacMan(Direction::LEFT);
        break;
    case sf::Keyboard::Right:
        world->setDirectionPacMan(Direction::RIGHT);
        break;
    default:
        break;
    }
}

void LevelState::update() {
    world->update();
    if (world->isGameOver()) {
        toGameOverState();
    } else if (world->isAllLevelsComplete()) {
        toVictoryState();
    } else if (world->isLevelComplete()) {
        toIntermissionState();
    }
}

void LevelState::draw(shared_ptr<sf::RenderWindow> window) {
    const sf::Font font = Singleton<FontFactory>::getInstance().getPixelFont();
    constexpr int textMargin = 30;

    // draw the score on the left bottom of the screen
    sf::Text scoreText("Score: " + std::to_string(score->getCurrentScore()), font, 20);
    const int textPosY = window->getSize().y - scoreText.getGlobalBounds().height - textMargin;
    scoreText.setPosition(textMargin, textPosY);
    window->draw(scoreText);

    // draw the lives remaining on the right bottom of the screen
    sf::Text livesText("# Lives Remaining: " + std::to_string(score->getLivesRemaining()), font, 20);
    livesText.setPosition(window->getSize().x - livesText.getGlobalBounds().width - textMargin, textPosY);
    window->draw(livesText);
}

void LevelState::toNextLevelState() {
    // remove old level state
    stateManager->popState();

    // push new level state
    const shared_ptr<State> levelState = std::make_shared<LevelState>(stateManager, ++level, score);
    stateManager->pushState(levelState);
    Stopwatch::getInstance().restart();
}
