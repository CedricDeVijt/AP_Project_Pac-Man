#ifndef AP_PROJECT_PAC_MAN_GAME_H
#define AP_PROJECT_PAC_MAN_GAME_H

#include <SFML/Graphics.hpp>
#include "StateManager.h"


class Game {
public:
    Game();
    ~Game();

    void run();

private:
    // SFML window
    sf::RenderWindow window;
    // Game state manager
    StateManager stateManager;

    // Function to handle user input during gameplay
    void handleInput();

    // Function to update the game logic
    void update();

    // Function to render the game
    void render();

};


#endif //AP_PROJECT_PAC_MAN_GAME_H
