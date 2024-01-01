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

public:
    /**
     * @brief Constructor for the PacMan class.
     * @param position The initial position of Pac-Man.
     */
    explicit PacMan(std::tuple<double, double, double, double> position);

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
};

#endif // AP_PROJECT_PAC_MAN_PACMAN_H
