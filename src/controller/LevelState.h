
#ifndef GAMELOGICLIB_LEVELSTATE_H
#define GAMELOGICLIB_LEVELSTATE_H

#include "World.h"
#include "Score.h"
#include "State.h"

/**
 * @class LevelState
 * @brief Represents the level state of the game.
 */
class LevelState final : public State {
public:
    /**
     * @brief Constructor for the LevelState class.  Creates a world of level 0.
     * @param stateManager Pointer to the StateManager managing the game states.
     */
    explicit LevelState(StateManager *stateManager);

    /**
     * @brief Constructor for the LevelState class.  Creates a world with given level and score.
     * @param stateManager Pointer to the StateManager managing the game states.
     * @param level The level of the game
     * @param score The object containing the current score info
     */
    explicit LevelState(StateManager *stateManager, int level, const shared_ptr <Score>& score);

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
    void draw(shared_ptr <sf::RenderWindow> window) override;

    /**
     * @brief creates a LevelState that corresponds to the next level in the game.
     */
    void toNextLevelState();

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
     * @brief Transitions to IntermissionState.
     */
    void toIntermissionState();

    shared_ptr <World> world; ///< Pointer to the game world.
    shared_ptr <Score> score; ///< Pointer to the game score.
    int level = 0;                ///< The current level of the game
};



#endif //GAMELOGICLIB_LEVELSTATE_H
