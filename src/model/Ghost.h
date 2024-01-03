#ifndef AP_PROJECT_PAC_MAN_GHOST_H
#define AP_PROJECT_PAC_MAN_GHOST_H

#include "Direction.h"
#include "EntityModel.h"
#include <iostream>
#include <tuple>

/**
 * @enum GhostType
 * @brief Enum representing different types of ghosts.
 */
enum class GhostType { Blinky, Pinky, Inky, Clyde, Fear };

/**
 * @fn operator<<(std::ostream& os, const GhostType& ghostType)
 * @brief Overloaded stream insertion operator for GhostType.
 * @param os The output stream.
 * @param ghostType The GhostType to be inserted into the stream.
 * @return The output stream with GhostType inserted.
 */
std::ostream& operator<<(std::ostream& os, const GhostType& ghostType);

/**
 * @class Ghost
 * @brief Represents a ghost entity in the game with specific behavior and movement.
 */
class Ghost : public EntityModel {
public:
    /**
     * @brief Constructor for the Ghost class.
     * @param type The type of the ghost.
     * @param homePosition A tuple representing the home position (x, y, width, height) of the ghost.
     * @param level The level of the game.
     */
    Ghost(GhostType type, std::tuple<double, double, double, double> homePosition, int level);

    /**
     * @brief Gets the type of the ghost.
     * @return The type of the ghost.
     */
    GhostType getType() const;

    /**
     * @brief Handles the event when the ghost is captured by PacMan.
     */
    void capturedByPacMan();

    /**
     * @brief Go back to home position.
     */
    void goHome();

    /**
     * @brief Switches the ghost to fear mode.
     */
    void toFearMode();

    /**
     * @brief Checks if the ghost is in fear mode.
     * @return True if the ghost is in fear mode, false otherwise.
     */
    bool isFearMode() const;

    /**
     * @brief Checks if the ghost is in wait mode.
     * @return True if the ghost is in wait mode, false otherwise.
     */
    bool isWaitMode() const;

    /**
     * @brief Updates the ghost's state and position based on the game rules.
     * @param possibleDirections A vector of possible directions the ghost can move in.
     * @param pacManPosition A tuple representing the current position (x, y, width, height) of PacMan.
     */
    void update(const std::vector<Direction>& directions, std::tuple<double, double, double, double> pacManPosition);

private:
    GhostType type;            ///< The type of the ghost.
    std::tuple<double, double, double, double> homePosition; ///< The home position of the ghost.
    Direction direction = Direction::NONE;                   ///< The current direction of the ghost.

    double waitTime;                ///< The remaining time before the ghost can start moving.
    double fearWaitTime;                ///< The remaining time before the ghost leaves fear mode.
    int level = 0;                  ///< The level of the current game
    const double accelerator = 1.1; ///< The accelerator factor used to speed up the movements of the ghost


    /**
     * @brief Checks if the ghost is at a corner or intersection.
     * @param directions A vector of possible directions the ghost can move in.
     * @return True if the ghost is at a corner or intersection, false otherwise.
     */
    bool atCornerOrIntersection(const std::vector<Direction>& possibleDirections) const;

    /**
     * @brief Gets the direction with the minimum Manhattan distance to PacMan.
     * @param possibleDirections A vector of possible directions the ghost can move in.
     * @param pacManPosition A tuple representing the current position (x, y, width, height) of PacMan.
     * @return The direction with the minimum Manhattan distance.
     */
    Direction getDirectionWithMinmumManhattanDistance(const std::vector<Direction>& possibleDirections,
                                                      const std::tuple<double, double, double, double>& pacManPosition);

    /**
     * @brief Gets the direction with the maximum Manhattan distance to PacMan.
     * @param possibleDirections A vector of possible directions the ghost can move in.
     * @param pacManPosition A tuple representing the current position (x, y, width, height) of PacMan.
     * @return The direction with the maximum Manhattan distance.
     */
    Direction getDirectionWithMaximumManhattanDistance(
        const std::vector<Direction>& possibleDirections,
        const std::tuple<double, double, double, double>& pacManPosition);

    /**
     * @brief Checks if the ghost is at a dead end.
     * @param directions A vector of possible directions the ghost can move in.
     * @return True if the ghost is at a dead end, false otherwise.
     */
    bool atDeadEnd(const std::vector<Direction>& directions) const;

    /**
     * @brief Checks if the ghost has left his starting point.
     * @return True if the ghost has left the starting point, false otherwise.
     */
    bool hasLeftStartingPoint() const;

    Direction getRandomDirection(const std::vector <Direction> &possibleDirections) const;
};

#endif // AP_PROJECT_PAC_MAN_GHOST_H
