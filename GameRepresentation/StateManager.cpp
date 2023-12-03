#include "StateManager.h"
#include "State.h"

StateManager::StateManager() {
    stateStack.push(new MenuState(this));
}

void StateManager::pushState(State* state) {
    stateStack.push(state);
}

State * StateManager::popState() {
    stateStack.pop();
    State *topState = stateStack.top();
    return topState;
}
