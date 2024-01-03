#ifndef AP_PROJECT_PAC_MAN_DIRECTION_H
#define AP_PROJECT_PAC_MAN_DIRECTION_H
#include <iostream>

/**
 * @enum Direction
 * @brief Represents the possible directions of movement in the game.
 */
enum Direction { LEFT, RIGHT, UP, DOWN, NONE };

/**
 * @brief Gets the opposite direction of the given direction.
 * @param direction The input direction.
 * @return The opposite direction.
 */
Direction oppositeDirection(Direction direction);

/**
 * @brief Overloaded output stream operator for Direction enum.
 * @param os The output stream.
 * @param dir The Direction enum value.
 * @return The modified output stream.
 */
std::ostream& operator<<(std::ostream& os, const Direction& dir);

#endif // AP_PROJECT_PAC_MAN_DIRECTION_H
