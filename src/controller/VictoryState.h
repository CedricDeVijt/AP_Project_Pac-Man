
#ifndef GAMELOGICLIB_VICTORYSTATE_H
#define GAMELOGICLIB_VICTORYSTATE_H

#include "State.h"
#include "StateManager.h"
/**
 * @class VictoryState
 * @brief Represents the victory state of the game.
 */
class VictoryState final : public State {
public:
    /**
     * @brief Constructor for the VictoryState class.
     * @param stateManager Pointer to the StateManager managing the game states.
     * @param score The score that the player obtained.
     */
    explicit VictoryState(shared_ptr<StateManager> stateManager, int score);

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
    void toMenuState() const;

    int score;
};

#endif // GAMELOGICLIB_VICTORYSTATE_H
