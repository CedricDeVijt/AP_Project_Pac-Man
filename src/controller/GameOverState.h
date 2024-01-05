
#ifndef GAMELOGICLIB_GAMEOVERSTATE_H
#define GAMELOGICLIB_GAMEOVERSTATE_H



#include "StateManager.h"
#include "State.h"
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
    explicit GameOverState(StateManager *stateManager);

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
    void draw(shared_ptr <sf::RenderWindow> window) override;

private:
    /**
     * @brief Transitions to MenuState.
     */
    void toMenuState();

    void toNewGameState() const;
};




#endif //GAMELOGICLIB_GAMEOVERSTATE_H
