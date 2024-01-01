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
     */
    Ghost(GhostType type, std::tuple<double, double, double, double> homePosition);

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
     * @brief Switches the ghost to fear mode.
     */
    void toFearMode();

    /**
     * @brief Checks if the ghost is in fear mode.
     * @return True if the ghost is in fear mode, false otherwise.
     */
    bool isFearMode() const;

    /**
     * @brief Checks if the ghost is in chase mode.
     * @return True if the ghost is in chase mode, false otherwise.
     */
    bool isChaseMode() const;

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
    GhostType type; ///< The type of the ghost.
    bool fearMode; ///< Flag indicating whether the ghost is in fear mode.
    bool chaseMode; ///< Flag indicating whether the ghost is in chase mode.
    bool waitMode; ///< Flag indicating whether the ghost is in wait mode.
    bool hasLeftStartingPoint; ///< Flag indicating whether the ghost has left its starting point.
    std::tuple<double, double, double, double> homePosition; ///< The home position of the ghost.
    Direction direction = Direction::NONE; ///< The current direction of the ghost.

    // TODO use stopwatch
    int timer = 0; ///< Timer used for controlling wait mode.

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
};

#endif // AP_PROJECT_PAC_MAN_GHOST_H
