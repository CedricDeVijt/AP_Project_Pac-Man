#ifndef AP_PROJECT_PAC_MAN_STATE_H
#define AP_PROJECT_PAC_MAN_STATE_H

#include <SFML/Graphics.hpp>

#include "Score.h"
#include "StateManager.h"
#include "World.h"

using std::shared_ptr;

class StateManager;

/**
 * @class State
 * @brief Abstract base class representing different states in the game.
 */
class State {

protected:
    shared_ptr<StateManager> stateManager; ///< Pointer to the StateManager managing the game states.

    /**
     * @brief Centers a text horizontally in the middle of a window
     * @param text the text to center.
     * @param posY the vertical position.
     */
    static void centerHorizontally(sf::Text& text, int posY);

public:
    /**
     * @brief Constructor for the State class.
     * @param stateManager Pointer to the StateManager managing the game states.
     */
    explicit State(shared_ptr<StateManager> stateManager);

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

#endif // AP_PROJECT_PAC_MAN_STATE_H
