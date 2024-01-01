#include "Direction.h"

std::ostream& operator<<(std::ostream& os, const Direction& dir) {
    switch (dir) {
        case LEFT:
            os << "LEFT";
            break;
        case RIGHT:
            os << "RIGHT";
            break;
        case UP:
            os << "UP";
            break;
        case DOWN:
            os << "DOWN";
            break;
        case NONE:
            os << "NONE";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return os;
}

//Direction oppositeDirection(Direction dir) {
//    switch (dir) {
//        case LEFT:
//            return RIGHT;
//        case RIGHT:
//            return LEFT;
//        case UP:
//            return DOWN;
//        case DOWN:
//            return UP;
//        case NONE:
//            return NONE;
//    }
//}
//
