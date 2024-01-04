#ifndef AP_PROJECT_PAC_MAN_GAME_H
#define AP_PROJECT_PAC_MAN_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "StateManager.h"

using std::shared_ptr;

/**
 * @class Game
 * @brief Represents the main game class following the Model-View-Controller (MVC) design pattern.
 */
class Game {
private:
    shared_ptr<sf::RenderWindow> window;         ///< The main game window.
    const shared_ptr<StateManager> stateManager; ///< Manages the game states.

public:
    /**
     * @brief Default constructor for the Game class.
     */
    Game();

    /**
     * @brief Destructor for the Game class.
     */
    ~Game() = default;

    /**
     * @brief Runs the main game loop.
     * This function handles the main game loop, including event processing, updating,
     * and rendering.
     */
    void run();
};

#endif // AP_PROJECT_PAC_MAN_GAME_H
