
#ifndef GAMELOGICLIB_INTERMISSIONSTATE_H
#define GAMELOGICLIB_INTERMISSIONSTATE_H



#include "StateManager.h"
#include "State.h"
/**
 * @class IntermissionState
 * @brief Represents the intermission state between two levels.
 */
class IntermissionState final : public State {
public:
    /**
     * @brief Constructor for the IntermissionState class.
     * @param stateManager Pointer to the StateManager managing the game states.
     * @param level The level that just has been completed.
     */
    explicit IntermissionState(StateManager *stateManager, int level);

    /**
     * @brief Processes input events for the IntermissionState.
     * Transitions to MenuState on Enter key press.
     * @param key The key that was pressed.
     */
    void processInput(sf::Keyboard::Key key) override;

    /**
     * @brief Updates the IntermissionState logic.
     */
    void update() override;

    /**
     * @brief Draws the IntermissionState on the given window.
     * @param window Shared pointer to the SFML RenderWindow.
     */
    void draw(shared_ptr <sf::RenderWindow> window) override;

private:
    /**
     * @brief Transitions to MenuState.
     */
    void toNextLevelState() const;

    int level; ///< The value of the level that just has been completed
};



#endif //GAMELOGICLIB_INTERMISSIONSTATE_H
