#include "Ghost.h"
#include <cmath>


Ghost::Ghost(GhostType type, std::tuple<double, double, double, double> homePosition)
        : type(type), homePosition(homePosition) , EntityModel(homePosition){
    // start in waitmode
    fearMode = false;
    chaseMode = false;
    waitMode = true;
    position = homePosition;
    // TODO set startTime Wait Mode

    // set initial travel direction
    switch (type) {
        case GhostType::Pinky:
        case GhostType::Inky:
            direction = Direction::UP;
            break;
        case GhostType::Blinky:
            direction = Direction::RIGHT;
            break;
        case GhostType::Clyde:
            direction = Direction::LEFT;
            break;
        default:
            break;
    }
}


void Ghost::eaten() {
    // go back to initial position and start chasing
    fearMode = false;
    chaseMode = true;
    waitMode = false;
    position = homePosition;
}

void Ghost::toFearMode() {
    fearMode = true;
    chaseMode = false;
    // TODO set startTime Fear Mode
}

void Ghost::setTargetPosition(std::tuple<double, double, double, double> position) {
    pacManPosition = position;
}

bool Ghost::isFearMode() const {
    return fearMode;
}

bool Ghost::isChaseMode() const {
    return chaseMode;
}

bool Ghost::isWaitMode() const {
    return waitMode;
}

GhostType Ghost::getType() const {
    return type;
}


double manhattanDistance(std::tuple<double, double, double, double> a, std::tuple<double, double, double, double> b) {
    double a_x, a_y, b_x, b_y;
    std::tie(a_x, a_y, std::ignore, std::ignore) = a;
    std::tie(b_x, b_y, std::ignore, std::ignore) = b;

    return std::abs(a_x - b_x) + std::abs(a_y - b_y);
}
