#include "State.h"

State::State(StateManager *stateManager) : stateManager(stateManager) {}

MenuState::MenuState(StateManager *stateManager) : State(stateManager) {}

void State::createNewLevelState() {
    State *levelState = new LevelState(stateManager);
    stateManager->pushState(levelState);

    // TODO: Add code to start the level
}

void State::createNewMenuState() {
    State *menuState = new MenuState(stateManager);
    stateManager->pushState(menuState);

    // TODO: Add code to show menu screen
}

void MenuState::toLevelState() {
    createNewLevelState();
}

LevelState::LevelState(StateManager *stateManager) : State(stateManager) {}

void LevelState::toVictoryState() {
    State *victoryState = new VictoryState(stateManager);
    stateManager->pushState(victoryState);

    // TODO: Add code to show victory screen
}

void LevelState::toPausedState() {
    State *pausedState = new PausedState(stateManager);
    stateManager->pushState(pausedState);

    // TODO: Add code to show paused screen
}

void LevelState::toGameOverState() {
    State *gameOverState = new GameOverState(stateManager);
    stateManager->pushState(gameOverState);

    // TODO: Add code to show game over screen
}

PausedState::PausedState(StateManager *stateManager) : State(stateManager) {}

void PausedState::toMenuState() {
    createNewMenuState();
}

void PausedState::toLevelState() {
    State *levelState = stateManager->popState();
    stateManager->pushState(levelState);

    // TODO: Add code to resume the level
}

VictoryState::VictoryState(StateManager *stateManager) : State(stateManager) {}

void VictoryState::toLevelState() {
    createNewLevelState();
}

GameOverState::GameOverState(StateManager *stateManager) : State(stateManager) {
}

void GameOverState::toMenuState() {
    createNewMenuState();
}
