#include "State.h"
#include "../model/Score.h"
#include "../model/Stopwatch.h"
#include "../model/World.h"
#include "../view/ConcreteFactory.h"
#include "../view/FontFactory.h"
#include "../view/SpriteFactory.h"
#include "../view/WindowSingleton.h"
#include "../view/SoundEffects.h"

State::State(StateManager* stateManager) : stateManager(stateManager) {}

MenuState::MenuState(StateManager* stateManager) : State(stateManager) {}

void State::createNewMenuState() {
    const shared_ptr<State> menuState = std::make_shared<MenuState>(stateManager);
    stateManager->pushState(menuState);
}

void MenuState::toLevelState() {
    const shared_ptr<State> levelState = std::make_shared<LevelState>(stateManager);
    stateManager->pushState(levelState);
    SoundEffects::getInstance().stop();
}

void MenuState::draw(shared_ptr<sf::RenderWindow> window) {
    const sf::Sprite sprite = SpriteFactory::getInstance().createLogo();
    window->draw(sprite);

    // High scores
    const std::vector<std::pair<std::string, int>> scores = Score::loadHighScores();
    const sf::Font font = FontFactory::getInstance().getPixelFont();

    sf::Text title("High Scores", font, 40);
    const int spriteHeight = static_cast<int>(sprite.getGlobalBounds().height);
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

LevelState::LevelState(StateManager *stateManager) : State(stateManager) {
    score = std::make_shared<Score>();
    level = 0;
    auto factory = std::make_shared<ConcreteFactory>(level);
    world = std::make_shared<World>(factory, level, score);
    // start the clock
    Stopwatch::getInstance().start();
    world->update();
}

LevelState::LevelState(StateManager *stateManager, int level, const shared_ptr <Score>& score) : State(stateManager), score(score), level(level) {
    auto factory = std::make_shared<ConcreteFactory>(level);
    world = std::make_shared<World>(factory, level, score);
    // start the clock
    Stopwatch::getInstance().start();
    world->update();
}

void LevelState::toVictoryState() {
    const shared_ptr<State> victoryState = std::make_shared<VictoryState>(stateManager);
    stateManager->pushState(victoryState);
    SoundEffects::getInstance().playVictory();
}

void LevelState::toPausedState() {
    const shared_ptr<State> pausedState = std::make_shared<PausedState>(stateManager);
    stateManager->pushState(pausedState);
}

void LevelState::toGameOverState() {
    const shared_ptr<State> gameOverState = std::make_shared<GameOverState>(stateManager);
    stateManager->pushState(gameOverState);
    SoundEffects::getInstance().playGameOver();
}

void LevelState::toIntermissionState() {
    const shared_ptr<State> intermissionState = std::make_shared<IntermissionState>(stateManager, level);
    stateManager->pushState(intermissionState);
    SoundEffects::getInstance().playIntermission();

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
    const sf::Font font = FontFactory::getInstance().getPixelFont();
    sf::Text scoreText("Score: " + std::to_string(score->getCurrentScore()), font, 20);
    sf::Text livesText("# Lives Remaining: " + std::to_string(score->getLivesRemaining()), font, 20);

    constexpr int textMargin = 30;
    const int textPosY = window->getSize().y -scoreText.getGlobalBounds().height - textMargin;
    scoreText.setPosition(textMargin, textPosY);
    window->draw(scoreText);
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

PausedState::PausedState(StateManager* stateManager) : State(stateManager) { Stopwatch::getInstance().pause(); }

void PausedState::toMenuState() { createNewMenuState(); }

void PausedState::toLevelState() const {
    const shared_ptr<State> levelState = stateManager->popState();
    stateManager->pushState(levelState);
    Stopwatch::getInstance().unPause();
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
    const sf::Sprite sprite = SpriteFactory::getInstance().createLogo();
    window->draw(sprite);

    // draw the title
    const sf::Font font = FontFactory::getInstance().getPixelFont();
    sf::Text title("Game Paused", font, 50);
    centerHorizontally(title, sprite.getGlobalBounds().height + 70);
    window->draw(title);

    // draw the instructions
    sf::Text instructions("Press Escape to continue", font, 15);
    centerHorizontally(instructions, window->getSize().y - 100);
    window->draw(instructions);
}


VictoryState::VictoryState(StateManager* stateManager) : State(stateManager) {}

void VictoryState::toLevelState() const {
    stateManager->popState();  // back to level state
    stateManager->popState();  // back to menu state
    SoundEffects::getInstance().stop();
}

void VictoryState::processInput(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Enter:
            toLevelState();
            break;
        default:
            break;
    }
}

void VictoryState::update() {}

void VictoryState::draw(shared_ptr<sf::RenderWindow> window) {
    // draw the logo
    const sf::Sprite sprite = SpriteFactory::getInstance().createLogo();
    window->draw(sprite);

    // draw the title
    const sf::Font font = FontFactory::getInstance().getPacManFont();
    sf::Text title("Victory !!!", font, 50);
    centerHorizontally(title, sprite.getGlobalBounds().height + 70);
    window->draw(title);

    // draw the instructions
    sf::Text instructions("Press Enter to continue", font, 15);
    centerHorizontally(instructions, window->getSize().y - 100);
    window->draw(instructions);
}

GameOverState::GameOverState(StateManager* stateManager) : State(stateManager) {}

void GameOverState::toMenuState() { createNewMenuState(); }

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
    sf::Sprite sprite = SpriteFactory::getInstance().createLogo();
    window->draw(sprite);

    // draw the title
    sf::Font pacManFont = FontFactory::getInstance().getPacManFont();
    sf::Text title("Game Over", pacManFont, 50);
    centerHorizontally(title, sprite.getGlobalBounds().height + 70);
    window->draw(title);

    // draw the instructions
    sf::Font pixelFont = FontFactory::getInstance().getPixelFont();
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
}

void State::centerHorizontally(sf::Text &title, int posY) {
    const auto window = WindowSingleton::getInstance().getWindow();
    const int titleWidth = title.getGlobalBounds().width;
    title.setPosition((window->getSize().x - titleWidth) / 2, posY);
}

IntermissionState::IntermissionState(StateManager* stateManager, int level) : State(stateManager), level(level){}

void IntermissionState::toNextLevelState() const {
    // pop the intermission state from the stack
    stateManager->popState();

    // create the next LevelState
    const std::shared_ptr<LevelState> state = std::dynamic_pointer_cast<LevelState>(stateManager->getCurrentState());
    state->toNextLevelState();
    SoundEffects::getInstance().stop();
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
    const sf::Sprite sprite = SpriteFactory::getInstance().createLogo();
    window->draw(sprite);

    // draw the title
    const sf::Font font = FontFactory::getInstance().getPixelFont();
    const std::string titleText = "Level " + std::to_string(level) + " Completed";
    sf::Text title(titleText, font, 50);
    centerHorizontally(title, sprite.getGlobalBounds().height + 70);
    window->draw(title);

    // draw the instructions
    sf::Text instructions("Press Enter to continue", font, 15);
    centerHorizontally(instructions, window->getSize().y - 100);
    window->draw(instructions);
}
