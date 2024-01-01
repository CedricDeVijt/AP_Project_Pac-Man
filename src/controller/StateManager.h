#ifndef AP_PROJECT_PAC_MAN_STATEMANAGER_H
#define AP_PROJECT_PAC_MAN_STATEMANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

using std::shared_ptr;

class State;

/**
 * @class StateManager
 * @brief Manages the game states.
 */
class StateManager {
    std::stack<shared_ptr<State>> stateStack; ///< Stack of game states.

public:
    /**
     * @brief Default constructor for the StateManager class.
     * Initializes the state stack with the MenuState.
     */
    StateManager();

    /**
     * @brief Destructor for the StateManager class.
     */
    ~StateManager() = default;

    /**
     * @brief Gets the current active state on top of the stack.
     * @return A shared pointer to the current active state.
     */
    shared_ptr<State> getCurrentState();

    /**
     * @brief Pushes a new state onto the stack.
     * @param state A shared pointer to the state to be pushed onto the stack.
     */
    void pushState(shared_ptr<State> state);

    /**
     * @brief Pops the top state from the stack.
     * @return A shared pointer to the state that was popped.
     */
    shared_ptr<State> popState();
};

#endif // AP_PROJECT_PAC_MAN_STATEMANAGER_H
