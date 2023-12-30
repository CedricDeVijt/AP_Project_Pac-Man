#ifndef AP_PROJECT_PAC_MAN_GAME_H
#define AP_PROJECT_PAC_MAN_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "StateManager.h"
#include "../model/World.h"

using std::shared_ptr;

class Game {
private:
    shared_ptr<sf::RenderWindow> window;
    shared_ptr<StateManager> stateManager;
public:
    Game();

    ~Game();

    void run();
};


#endif //AP_PROJECT_PAC_MAN_GAME_H
