
#ifndef GAMELOGICLIB_MENUSTATE_H
#define GAMELOGICLIB_MENUSTATE_H

#include "State.h"
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
    explicit MenuState(shared_ptr<StateManager> stateManager);

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

#endif // GAMELOGICLIB_MENUSTATE_H
