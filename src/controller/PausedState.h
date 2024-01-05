
#ifndef GAMELOGICLIB_PAUSEDSTATE_H
#define GAMELOGICLIB_PAUSEDSTATE_H

#include "State.h"
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
    void toLevelState() const;
};

#endif // GAMELOGICLIB_PAUSEDSTATE_H
