#ifndef AP_PROJECT_PAC_MAN_PACMAN_H
#define AP_PROJECT_PAC_MAN_PACMAN_H

#include <vector>

#include "Direction.h"
#include "EntityModel.h"

/**
 * @class PacMan
 * @brief Represents the Pac-Man entity in the game.
 */
class PacMan : public EntityModel {
private:
    Direction direction;                                     ///< Current direction of Pac-Man.
    Direction targetDirection = Direction::NONE;             ///< Target direction set by the player.
    std::tuple<double, double, double, double> homePosition; ///< Starting position of Pac-Man.
    int lives = 3;                                           ///< Number of lives remaining for Pac-Man.
    int level = 0;                                           ///< The level of the current game
    const double accelerator = 1.1;                          ///< The accelerator factor used to speed up the movements of the ghost


public:
    /**
     * @brief Constructor for the PacMan class.
     * @param position The initial position of Pac-Man.
     * @param level The level of the game.
     */
    explicit PacMan(std::tuple<double, double, double, double> position, int level);

    /**
     * @brief Updates the state of Pac-Man based on the available directions.
     * @param directions A vector of possible directions for Pac-Man to move.
     */
    void update(const std::vector<Direction>& directions);

    /**
     * @brief Sets the target direction for Pac-Man.
     * @param direction The target direction to set.
     */
    void setTargetDirection(const Direction& direction);

    /**
     * @brief Gets the current direction of Pac-Man.
     * @return The current direction of Pac-Man.
     */
    Direction getDirection() const;

    /**
     * @brief Handles the death of Pac-Man.
     * @details Decreases the number of lives and resets Pac-Man's position to the starting point.
     */
    void die();

    /**
     * @brief Handles the capture of a ghost by Pac-Man.
     * @details To be implemented.
     */
    void captureGhost();

    /**
     * @brief checks if Pac-Man is dead.
     * @return True if all lives of Pac-Man are exhausted, false otherwise.
     */
    bool isDead();
};

#endif // AP_PROJECT_PAC_MAN_PACMAN_H
