#ifndef AP_PROJECT_PAC_MAN_STATE_H
#define AP_PROJECT_PAC_MAN_STATE_H

#include <SFML/Graphics.hpp>

#include "../model/Score.h"
#include "../model/World.h"
#include "StateManager.h"

using std::shared_ptr;

class StateManager;

class State {
protected:
    StateManager* stateManager;

    void createNewLevelState();

    void createNewMenuState();

public:
    explicit State(StateManager* stateManager);

    virtual ~State() = default;

    virtual void processInput(sf::Keyboard::Key key) = 0;

    virtual void update() = 0;

    virtual void draw(shared_ptr<sf::RenderWindow> window) = 0;
};

class MenuState final : public State {
public:
    explicit MenuState(StateManager* stateManager);

    void processInput(sf::Keyboard::Key key) override;

    void update() override;

    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    void toLevelState();
};

class LevelState final : public State {
public:
    explicit LevelState(StateManager* stateManager);

    void processInput(sf::Keyboard::Key key) override;

    void update() override;

    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    void toVictoryState();

    void toPausedState();

    void toGameOverState();

    void toLevelState();

    shared_ptr<World> world;
    shared_ptr<Score> score;
};

class PausedState final : public State {
public:
    explicit PausedState(StateManager* stateManager);

    void processInput(sf::Keyboard::Key key) override;

    void update() override;

    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    void toMenuState();

    void toLevelState();
};

class VictoryState final : public State {
public:
    explicit VictoryState(StateManager* stateManager);

    void processInput(sf::Keyboard::Key key) override;

    void update() override;

    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    void toLevelState();
};

class GameOverState final : public State {
public:
    explicit GameOverState(StateManager* stateManager);

    void processInput(sf::Keyboard::Key key) override;

    void update() override;

    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    void toMenuState();
};

#endif // AP_PROJECT_PAC_MAN_STATE_H
