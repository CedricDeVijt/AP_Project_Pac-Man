#ifndef AP_PROJECT_PAC_MAN_STATE_H
#define AP_PROJECT_PAC_MAN_STATE_H

#include <SFML/Graphics.hpp>

#include "../model/Score.h"
#include "../model/World.h"
#include "StateManager.h"

using std::shared_ptr;

class StateManager;

/**
 * @class State
 * @brief Abstract base class representing different states in the game.
 */
class State {
protected:
    StateManager* stateManager; ///< Pointer to the StateManager managing the game states.

    /**
     * @brief Creates a new LevelState and adds it to the state stack.
     */
    void createNewLevelState();

    /**
     * @brief Creates a new MenuState and adds it to the state stack.
     */
    void createNewMenuState();

public:
    /**
     * @brief Constructor for the State class.
     * @param stateManager Pointer to the StateManager managing the game states.
     */
    explicit State(StateManager* stateManager);

    /**
     * @brief Virtual destructor for the State class.
     */
    virtual ~State() = default;

    /**
     * @brief Processes input events based on the current state.
     * @param key The key that was pressed.
     */
    virtual void processInput(sf::Keyboard::Key key) = 0;

    /**
     * @brief Updates the state logic.
     */
    virtual void update() = 0;

    /**
     * @brief Draws the state on the given window.
     * @param window Shared pointer to the SFML RenderWindow.
     */
    virtual void draw(shared_ptr<sf::RenderWindow> window) = 0;
};

/**
 * @class MenuState
 * @brief Represents the menu state of the game.
 */
class MenuState final : public State {
public:
    /**
     * @brief Constructor for the MenuState class.
     * @param stateManager Pointer to the StateManager managing the game states.
     */
    explicit MenuState(StateManager* stateManager);

    /**
    * @brief Processes input events for the MenuState.
    * Transitions to LevelState on Enter key press.
    * @param key The key that was pressed.
     */
    void processInput(sf::Keyboard::Key key) override;

    /**
     * @brief Updates the MenuState logic.
     */
    void update() override;

    /**
     * @brief Draws the MenuState on the given window.
     * Displays the Pac-man logo and high scores.
     * @param window Shared pointer to the SFML RenderWindow.
     */
    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    /**
     * @brief Transitions to LevelState.
     */
    void toLevelState();
};

/**
 * @class LevelState
 * @brief Represents the level state of the game.
 */
class LevelState final : public State {
public:
    /**
     * @brief Constructor for the LevelState class.
     * @param stateManager Pointer to the StateManager managing the game states.
     */
    explicit LevelState(StateManager* stateManager);

    /**
     * @brief Processes input events for the LevelState.
     * Transitions to VictoryState on completing all levels.
     * Transitions to PausedState on Escape key press.
     * @param key The key that was pressed.
     */
    void processInput(sf::Keyboard::Key key) override;

    /**
     * @brief Updates the LevelState logic.
     */
    void update() override;

    /**
    * @brief Draws the LevelState on the given window.
    * Displays the current score and remaining lives.
    * @param window Shared pointer to the SFML RenderWindow.
     */
    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    /**
     * @brief Transitions to VictoryState.
     */
    void toVictoryState();

    /**
     * @brief Transitions to PausedState.
     */
    void toPausedState();

    /**
     * @brief Transitions to GameOverState.
     */
    void toGameOverState();

    /**
     * @brief Restarts the current level.
     */
    void toLevelState();

    shared_ptr<World> world; ///< Pointer to the game world.
    shared_ptr<Score> score;  ///< Pointer to the game score.
};

/**
 * @class PausedState
 * @brief Represents the paused state of the game.
 */
class PausedState final : public State {
public:
    /**
     * @brief Constructor for the PausedState class.
     * @param stateManager Pointer to the StateManager managing the game states.
     */
    explicit PausedState(StateManager* stateManager);

    /**
     * @brief Processes input events for the PausedState.
     * Transitions to LevelState on Escape key press.
     * @param key The key that was pressed.
     */
    void processInput(sf::Keyboard::Key key) override;

    /**
     * @brief Updates the PausedState logic.
     */
    void update() override;

    /**
     * @brief Draws the PausedState on the given window.
     * @param window Shared pointer to the SFML RenderWindow.
     */
    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    /**
     * @brief Transitions to LevelState.
     */
    void toMenuState();

    /**
     * @brief Transitions to LevelState.
     */
    void toLevelState();
};

/**
 * @class VictoryState
 * @brief Represents the victory state of the game.
 */
class VictoryState final : public State {
public:
    /**
     * @brief Constructor for the VictoryState class.
     * @param stateManager Pointer to the StateManager managing the game states.
     */
    explicit VictoryState(StateManager* stateManager);

    /**
     * @brief Processes input events for the VictoryState.
     * Transitions to MenuState on Enter key press.
     * @param key The key that was pressed.
     */
    void processInput(sf::Keyboard::Key key) override;

    /**
     * @brief Updates the VictoryState logic.
     */
    void update() override;

    /**
     * @brief Draws the VictoryState on the given window.
     * @param window Shared pointer to the SFML RenderWindow.
     */
    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    /**
     * @brief Transitions to MenuState.
     */
    void toLevelState();
};

/**
 * @class GameOverState
 * @brief Represents the game over state of the game.
 */
class GameOverState final : public State {
public:
    /**
     * @brief Constructor for the GameOverState class.
     * @param stateManager Pointer to the StateManager managing the game states.
     */
    explicit GameOverState(StateManager* stateManager);

    /**
     * @brief Processes input events for the GameOverState.
     * Transitions to MenuState on Enter key press.
     * @param key The key that was pressed.
     */
    void processInput(sf::Keyboard::Key key) override;

    /**
     * @brief Updates the GameOverState logic.
     */
    void update() override;

    /**
     * @brief Draws the GameOverState on the given window.
     * @param window Shared pointer to the SFML RenderWindow.
     */
    void draw(shared_ptr<sf::RenderWindow> window) override;

private:
    /**
     * @brief Transitions to MenuState.
     */
    void toMenuState();
};

#endif // AP_PROJECT_PAC_MAN_STATE_H
