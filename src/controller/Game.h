#ifndef AP_PROJECT_PAC_MAN_GAME_H
#define AP_PROJECT_PAC_MAN_GAME_H

#include <SFML/Graphics.hpp>
#include "../model/StateManager.h"
#include "../model/World.h"


class Game {
public:
    Game();

    ~Game();

    void run();

private:

    sf::RenderWindow window;

    World world;
    StateManager stateManager;

    sf::Font pacManFont;
    sf::Font pixelFont;

    void setupGame();
};


#endif //AP_PROJECT_PAC_MAN_GAME_H
