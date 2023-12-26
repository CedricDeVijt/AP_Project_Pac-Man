#ifndef AP_PROJECT_PAC_MAN_STATEMANAGER_H
#define AP_PROJECT_PAC_MAN_STATEMANAGER_H

#include <SFML/Graphics.hpp>
#include <stack>
#include <memory>

using std::shared_ptr;

class State;

class StateManager {
    std::stack<shared_ptr<State>> stateStack;

public:
    StateManager();
    ~StateManager() = default;

    shared_ptr<State> getCurrentState();

    void pushState(shared_ptr<State> state);

    shared_ptr<State> popState();
};


#endif //AP_PROJECT_PAC_MAN_STATEMANAGER_H
