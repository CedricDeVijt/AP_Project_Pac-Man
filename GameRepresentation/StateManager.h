#ifndef AP_PROJECT_PAC_MAN_STATEMANAGER_H
#define AP_PROJECT_PAC_MAN_STATEMANAGER_H

#include <stack>
#include "State.h"

class StateManager {
    std::stack<State*> stateStack;

public:
    StateManager();
    ~StateManager() = default;

    void pushState(State *state);
    State *popState();
};


#endif //AP_PROJECT_PAC_MAN_STATEMANAGER_H
