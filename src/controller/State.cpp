#include "State.h"
#include "../view/SpriteFactory.h"


State::State(StateManager *stateManager) : stateManager(stateManager) {}

MenuState::MenuState(StateManager *stateManager) : State(stateManager) {}

void State::createNewLevelState() {
    shared_ptr<State> levelState = std::make_shared<LevelState>(stateManager);
    stateManager->pushState(levelState);

    // TODO: Add code to start the level
}

void State::createNewMenuState() {
    shared_ptr<State> menuState = std::make_shared<MenuState>(stateManager);
    stateManager->pushState(menuState);

    // TODO: Add code to show menu screen
}

void MenuState::toLevelState() {
    createNewLevelState();
}

void MenuState::draw(shared_ptr<sf::RenderWindow> window) {
    // Declare arrays for names and scores
    std::string names[5];
    int scores[5];

    // Generate sample names and scores
    names[0] = "Alice";
    scores[0] = 85;

    names[1] = "Bob";
    scores[1] = 92;

    names[2] = "Charlie";
    scores[2] = 78;

    names[3] = "David";
    scores[3] = 95;

    names[4] = "Eve";
    scores[4] = 88;

    // Load font
    // TODO: Move this to a more appropriate place in window
    sf::Font font;

    if (!font.loadFromFile("resources/pixelFont.ttf")) {
        throw std::runtime_error("Error loading font");
    }

    // TODO use window size to position text
    // get window size
    sf::Vector2u windowSize = window->getSize();
    unsigned int windowWidth = windowSize.x;
    unsigned int windowHeight = windowSize.y;

    sf::Text title("High Scores", font, 75);
    title.setPosition(100, 10);
    window->draw(title);



    for (int i = 0; i < 5; ++i) {
        sf::Text name(names[i], font, 20);
        name.setPosition(100, 150 + 30 * i);

        sf::Text score(std::to_string(scores[i]), font, 20);
        score.setPosition(300, 150 + 30 * i);

        window->draw(name);
        window->draw(score);
    }








}

void MenuState::processInput(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Enter) {
        toLevelState();
    }
}

void MenuState::update() {

}

LevelState::LevelState(StateManager *stateManager) : State(stateManager) {}

void LevelState::toVictoryState() {
    shared_ptr<State> victoryState = std::make_shared<VictoryState>(stateManager);
    stateManager->pushState(victoryState);

    // TODO: Add code to show victory screen
}

void LevelState::toPausedState() {
    shared_ptr<State> pausedState = std::make_shared<PausedState>(stateManager);
    stateManager->pushState(pausedState);
}

void LevelState::toGameOverState() {
    shared_ptr<State> gameOverState = std::make_shared<GameOverState>(stateManager);
    stateManager->pushState(gameOverState);

    // TODO: Add code to show game over screen
}

void LevelState::processInput(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Escape:
            toPausedState();
            break;
        default:
            break;
    }
}

void LevelState::update() {

}

void LevelState::draw(shared_ptr<sf::RenderWindow> window) {
    // Load font
    // TODO: Move this to a more appropriate place in window

    int score = 135;
    int livesRemaining = 3;

    std::string scoreString = "Score: " + std::to_string(score);
    std::string livesString = "Lives: " + std::to_string(livesRemaining);

    sf::Font font;

    if (!font.loadFromFile("resources/pixelFont.ttf")) {
        throw std::runtime_error("Error loading font");
    }


    sf::Text title(scoreString, font, 20);
    title.setPosition(100, 200);
    window->draw(title);


    sf::Text title2(livesString, font, 20);
    title2.setPosition(400, 200);
    window->draw(title2);


    SpriteFactory spriteFactory;
    sf::Vector2f scale = sf::Vector2f(2, 2);
    window->draw(spriteFactory.createGhost(GhostType::Clyde, 1, 200, 300, scale));
    window->draw(spriteFactory.createGhost(GhostType::Pinky, 1, 300, 300, scale));
    window->draw(spriteFactory.createPacMan(1, 300, 400, scale));


}

PausedState::PausedState(StateManager *stateManager) : State(stateManager) {}

void PausedState::toMenuState() {
    createNewMenuState();
}

void PausedState::toLevelState() {
    shared_ptr<State> levelState = stateManager->popState();
    stateManager->pushState(levelState);

    // TODO: Add code to resume the level
}

void PausedState::processInput(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::Escape:
            toLevelState();
            break;
//        case sf::Keyboard::Enter:
//            toMenuState();
//            break;
        default:
            break;
    }

}

void PausedState::update() {

}

void PausedState::draw(shared_ptr<sf::RenderWindow> window) {

    // Load font
    // TODO: Move this to a more appropriate place in window


    sf::Font font;

    if (!font.loadFromFile("resources/pixelFont.ttf")) {
        throw std::runtime_error("Error loading font");
    }


    sf::Text title("Paused", font, 20);
    title.setPosition(100, 200);
    window->draw(title);


}

VictoryState::VictoryState(StateManager *stateManager) : State(stateManager) {}

void VictoryState::toLevelState() {
    createNewLevelState();
}

void VictoryState::processInput(sf::Keyboard::Key key) {

}

void VictoryState::update() {

}

void VictoryState::draw(shared_ptr<sf::RenderWindow> window) {

}

GameOverState::GameOverState(StateManager *stateManager) : State(stateManager) {
}

void GameOverState::toMenuState() {
    createNewMenuState();
}

void GameOverState::processInput(sf::Keyboard::Key key) {

}

void GameOverState::update() {

}

void GameOverState::draw(shared_ptr<sf::RenderWindow> window) {

}
