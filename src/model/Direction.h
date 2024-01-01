#ifndef AP_PROJECT_PAC_MAN_DIRECTION_H
#define AP_PROJECT_PAC_MAN_DIRECTION_H
#include <iostream>

enum Direction { LEFT, RIGHT, UP, DOWN, NONE };

Direction oppositeDirection(Direction dir);
std::ostream& operator<<(std::ostream& os, const Direction& dir);

#endif // AP_PROJECT_PAC_MAN_DIRECTION_H
