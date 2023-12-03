#ifndef AP_PROJECT_PAC_MAN_STATE_H
#define AP_PROJECT_PAC_MAN_STATE_H

#include "StateManager.h"

class State {
protected:
    StateManager *stateManager;
    void createNewLevelState();
    void createNewMenuState();


public:
    explicit State(StateManager *stateManager);
    virtual ~State() = default;
};

class MenuState final : public State {
public:
    explicit MenuState(StateManager *stateManager);

private:
    void toLevelState();
};

class LevelState final : public State {
public:
    explicit LevelState(StateManager *stateManager);

private:
    void toVictoryState();
    void toPausedState();
    void toGameOverState();
};

class PausedState final : public State {
public:
    explicit PausedState(StateManager *stateManager);

private:
    void toMenuState();
    void toLevelState();
};

class VictoryState final : public State {
public:
    explicit VictoryState(StateManager *stateManager);

private:
    void toLevelState();
};

class GameOverState final : public State {
public:
    explicit GameOverState(StateManager *stateManager);

private:
    void toMenuState();
};

#endif //AP_PROJECT_PAC_MAN_STATE_H
