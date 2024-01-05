#include "Direction.h"

std::ostream& operator<<(std::ostream& os, const Direction& dir) {
    switch (dir) {
    case Direction::LEFT:
        os << "LEFT";
        break;
    case Direction::RIGHT:
        os << "RIGHT";
        break;
    case Direction::UP:
        os << "UP";
        break;
    case Direction::DOWN:
        os << "DOWN";
        break;
    case Direction::NONE:
        os << "NONE";
        break;
    default:
        os << "UNKNOWN";
        break;
    }
    return os;
}

Direction oppositeDirection(Direction dir) {
    switch (dir) {
    case Direction::LEFT:
        return Direction::RIGHT;
    case Direction::RIGHT:
        return Direction::LEFT;
    case Direction::UP:
        return Direction::DOWN;
    case Direction::DOWN:
        return Direction::UP;
    default:
        return Direction::NONE;
    }
}
