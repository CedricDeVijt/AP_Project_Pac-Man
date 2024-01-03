#include "Ghost.h"
#include "EntityModel.h"
#include "Random.h"
#include "Stopwatch.h"
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>

std::ostream& operator<<(std::ostream& os, const GhostType& ghostType) {
    switch (ghostType) {
    case GhostType::Blinky:
        os << "Blinky";
        break;
    case GhostType::Pinky:
        os << "Pinky";
        break;
    case GhostType::Inky:
        os << "Inky";
        break;
    case GhostType::Clyde:
        os << "Clyde";
        break;
    case GhostType::Fear:
        os << "Fear";
        break;
    default:
        os << "UNKNOWN";
        break;
    }
    return os;
}

// TODO enum for modes?
Ghost::Ghost(GhostType type, std::tuple<double, double, double, double> homePosition, int level)
    : type(type), homePosition(homePosition), level(level), EntityModel(homePosition) {
    // set the wait time for the fear mode
    fearWaitTime = 0.0;

    // set the appropiate wait time for each of the ghosts
    switch (type) {
    case GhostType::Blinky:
        waitTime = 5 * Stopwatch::SECOND;
        break;
    case GhostType::Clyde:
        waitTime = 10 * Stopwatch::SECOND;
        break;
    default:
        waitTime = -1.0; // no waiting
        break;
    }
    direction = Direction::NONE;
    nudgeToGrid();
}

void Ghost::capturedByPacMan() {
    // go back to initial position and start chasing
    position = homePosition;
}

void Ghost::toFearMode() { fearWaitTime = 5 * Stopwatch::SECOND; }

bool Ghost::isFearMode() const { return fearWaitTime > 0; }

bool Ghost::isWaitMode() const { return waitTime > 0.0; }

GhostType Ghost::getType() const { return type; }

double manhattanDistance(std::tuple<double, double, double, double> a, std::tuple<double, double, double, double> b) {
    double a_x, a_y, b_x, b_y;
    std::tie(a_x, a_y, std::ignore, std::ignore) = a;
    std::tie(b_x, b_y, std::ignore, std::ignore) = b;

    return std::abs(a_x - b_x) + std::abs(a_y - b_y);
}

void Ghost::update(const std::vector<Direction>& possibleDirections,
                   std::tuple<double, double, double, double> pacManPosition) {
    std::cout << "updating " << type << ": ";
    // update fear mode if needed
    if (isFearMode()) {
        // decrease wait time
        fearWaitTime -= Stopwatch::getInstance().getDeltaTime();
    }

    if (isWaitMode()) {
        // decrease wait time
        waitTime -= Stopwatch::getInstance().getDeltaTime();

    } else {
        // if we have not defined a direction yet, choose a random one out of the possible directions
        if (direction == Direction::NONE) {
            direction = getRandomDirection(possibleDirections);

            // if we have not left the starting point yet, travel in our previous direction until we reach a corner
            // or intersection
            //        } else if (!hasLeftStartingPoint()) {
            //            std::cout << "has not left starting point \n";
            //            if (atCornerOrIntersection(possibleDirections)) {
            //                direction = getRandomDirection(possibleDirections);
            //            }
        }

        // return if at a deadend
        else if (atDeadEnd(possibleDirections)) {
            std::cout << "at dead end\n";
            direction = possibleDirections[0];
        }

        // determine a new direction if we are at a corner or intersecion
        else if (atCornerOrIntersection(possibleDirections)) {
            std::cout << "at corner or intersection: ";
            // decide with probability p=0.5 to take random or manhattan direction
            if (Random::getInstance().getRandomNumber(100) < 50) {
                std::cout << "go random \n";
                direction = getRandomDirection(possibleDirections);
            } else {
                // determine direction of minimum/maximum manhattan distance based on fear setting
                Direction manhattanDirection;
                if (isFearMode()) {
                    std::cout << "go manhattan in fear mode\n";
                    manhattanDirection = getDirectionWithMaximumManhattanDistance(possibleDirections, pacManPosition);
                } else {
                    std::cout << "go manhattan \n";
                    manhattanDirection = getDirectionWithMinmumManhattanDistance(possibleDirections, pacManPosition);
                }
                direction = manhattanDirection;
            }
        } else {
            std::cout << "go in same direction as previous\n";
        }
    }
    // determine the acceleration for the given level
    double acceleration = std::pow(accelerator, level);
    position = step(direction, position, acceleration);
    notifyObservers(TICK);
}

Direction Ghost::getRandomDirection(const std::vector<Direction>& possibleDirections) const {
    // determine random direction among possible directions
    // modified algorithm to not go back
    if (possibleDirections.size() == 1) {
        return possibleDirections[0];
    } else {
        std::vector<Direction> directions = {};
        for (Direction pd : possibleDirections) {
            if (pd != oppositeDirection(direction)) {
                directions.push_back(pd);
            }
        }
        int random = Random::getInstance().getRandomNumber(directions.size() - 1);
        Direction randomDirection = directions[random];
        return randomDirection;
    }
}

Direction Ghost::getDirectionWithMinmumManhattanDistance(
    const std::vector<Direction>& possibleDirections,
    const std::tuple<double, double, double, double>& pacManPosition) {
    double minDistance = std::numeric_limits<double>::max();
    Direction minDirection = NONE;
    for (auto possibleDirection : possibleDirections) {
        std::tuple<double, double, double, double> nextPosition = step(possibleDirection, position, accelerator);
        double distance = manhattanDistance(nextPosition, pacManPosition);
        if (distance < minDistance) {
            minDistance = distance;
            minDirection = possibleDirection;
        }
    }
    return minDirection;
}

Direction Ghost::getDirectionWithMaximumManhattanDistance(
    const std::vector<Direction>& possibleDirections,
    const std::tuple<double, double, double, double>& pacManPosition) {
    double maxDistance = std::numeric_limits<double>::min();
    Direction maxDirection = NONE;
    for (auto possibleDirection : possibleDirections) {
        std::tuple<double, double, double, double> nextPosition = step(possibleDirection, position, accelerator);
        double distance = manhattanDistance(nextPosition, pacManPosition);
        if (distance > maxDistance) {
            maxDistance = distance;
            maxDirection = possibleDirection;
        }
    }
    return maxDirection;
}
//
// Direction Ghost::getDirectionWithManhattanDistance(
//        const std::vector<Direction>& possibleDirections,
//        const std::tuple<double, double, double, double>& pacManPosition, const std::function<bool(double, double)>&
//        compareFunction) {
//    double extremumDistance = std::numeric_limits<double>::max();
//    Direction extremumDirection = NONE;
//    for (auto possibleDirection : possibleDirections) {
//        std::tuple<double, double, double, double> nextPosition = step(possibleDirection, position, accelerator);
//        double distance = manhattanDistance(nextPosition, pacManPosition);
//        if (compareFunction(distance, extremumDistance)) {
//            extremumDistance = distance;
//            extremumDirection = possibleDirection;
//        }
//    }
//    return extremumDirection;
//}
//

bool Ghost::atCornerOrIntersection(const std::vector<Direction>& directions) const {
    // Check if "up" or "down" is present
    bool hasUpDown = std::find(directions.begin(), directions.end(), Direction::UP) != directions.end() ||
                     std::find(directions.begin(), directions.end(), Direction::DOWN) != directions.end();

    // Check if "left" or "right" is present
    bool hasLeftRight = std::find(directions.begin(), directions.end(), Direction::LEFT) != directions.end() ||
                        std::find(directions.begin(), directions.end(), Direction::RIGHT) != directions.end();

    // Return true if one of "up" or "down" is present AND one of "left" or "right" is present
    return hasUpDown && hasLeftRight;
}

bool Ghost::atDeadEnd(const std::vector<Direction>& directions) const { return (directions.size() == 1); }

bool Ghost::hasLeftStartingPoint() const { return manhattanDistance(homePosition, position) > 0.2; }

void Ghost::goHome() { position = homePosition; }
