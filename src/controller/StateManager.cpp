#include "StateManager.h"
#include "MenuState.h"
#include "State.h"

StateManager::StateManager() { stateStack.push(std::make_shared<MenuState>(this)); }

shared_ptr<State> StateManager::getCurrentState() { return stateStack.top(); }

void StateManager::pushState(const shared_ptr<State>& state) { stateStack.push(state); }

shared_ptr<State> StateManager::popState() {
    stateStack.pop();
    return stateStack.top();
}
