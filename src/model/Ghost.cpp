#include "Ghost.h"
#include "EntityModel.h"
#include "Random.h"
#include "Stopwatch.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>
#include <functional>

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
    }
    return os;
}

Ghost::Ghost(const GhostType type, const std::tuple<double, double, double, double>& homePosition, const int level)
    : EntityModel(homePosition), type(type), homePosition(homePosition), level(level) {
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

void Ghost::toFearMode() {
    fearWaitTime = 5 * Stopwatch::SECOND;
}

bool Ghost::isFearMode() const {
    return fearWaitTime > 0;
}

bool Ghost::isWaitMode() const {
    return waitTime > 0.0;
}

GhostType Ghost::getType() const { return type; }

double manhattanDistance(const std::tuple<double, double, double, double>& a,
                         const std::tuple<double, double, double, double>& b) {
    double a_x, a_y, b_x, b_y;
    std::tie(a_x, a_y, std::ignore, std::ignore) = a;
    std::tie(b_x, b_y, std::ignore, std::ignore) = b;

    return std::abs(a_x - b_x) + std::abs(a_y - b_y);
}

void Ghost::update(const std::vector<Direction>& directions,
                   const std::tuple<double, double, double, double>& pacManPosition) {
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
            direction = getRandomDirection(directions);
        }

            // return if at a deadend
        else if (atDeadEnd(directions)) {
            direction = directions[0];
        }

            // determine a new direction if we are at a corner or intersecion
        else if (atCornerOrIntersection(directions)) {
            // decide with probability p=0.5 to take random or manhattan direction
            if (Random::getInstance().getRandomNumber(100) < 50) {
                direction = getRandomDirection(directions);
            } else {
                // determine direction of minimum/maximum manhattan distance based on fear setting
                Direction manhattanDirection;
                if (isFearMode()) {
                    manhattanDirection = getDirectionWithMaximumManhattanDistance(directions, pacManPosition);
                } else {
                    manhattanDirection = getDirectionWithMinmumManhattanDistance(directions, pacManPosition);
                }
                direction = manhattanDirection;
            }
        } else {
        }
    }
    // determine the acceleration for the given level
    const double acceleration = std::pow(accelerator, level);
    position = step(direction, position, acceleration);
    notifyObservers(TICK);
}

Direction Ghost::getRandomDirection(
        const std::vector <Direction> &possibleDirections) const {
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
        const int random = Random::getInstance().getRandomNumber(directions.size() - 1);
        const Direction randomDirection = directions[random];
        return randomDirection;
    }
}

Direction Ghost::getDirectionWithMinmumManhattanDistance(
    const std::vector<Direction>& possibleDirections,
    const std::tuple<double, double, double, double>& pacManPosition) const {
    // initialisation
    double minDistance = std::numeric_limits<double>::max();
    Direction minDirection = NONE;
    // check each possible direction against what we previously had
    for (const auto possibleDirection : possibleDirections) {
        const std::tuple<double, double, double, double> nextPosition = step(possibleDirection, position, accelerator);
        // calculate the manhattan distance from the position to where pacman is
        const double distance = manhattanDistance(nextPosition, pacManPosition);
        // update the current result with the better value
        if (distance < minDistance) {
            minDistance = distance;
            minDirection = possibleDirection;
        }
    }
    return minDirection;
}

Direction Ghost::getDirectionWithMaximumManhattanDistance(
    const std::vector<Direction>& possibleDirections,
    const std::tuple<double, double, double, double>& pacManPosition) const {
    // initialisation
    double maxDistance = std::numeric_limits<double>::min();
    Direction maxDirection = NONE;
    // check each possible direction against what we previously had
    for (const auto possibleDirection : possibleDirections) {
        std::tuple<double, double, double, double> nextPosition = step(possibleDirection, position, accelerator);
        const double distance = manhattanDistance(nextPosition, pacManPosition);
        // update the current result with the better value
        if (distance > maxDistance) {
            maxDistance = distance;
            maxDirection = possibleDirection;
        }
    }
    return maxDirection;
}

bool Ghost::atCornerOrIntersection(const std::vector<Direction>& directions) {
    // Check if "up" or "down" is present
    const bool hasUpDown = std::find(directions.begin(), directions.end(), Direction::UP) != directions.end() ||
                     std::find(directions.begin(), directions.end(), Direction::DOWN) != directions.end();

    // Check if "left" or "right" is present
    const bool hasLeftRight = std::find(directions.begin(), directions.end(), Direction::LEFT) != directions.end() ||
                        std::find(directions.begin(), directions.end(), Direction::RIGHT) != directions.end();

    // Return true if one of "up" or "down" is present AND one of "left" or "right" is present
    return hasUpDown && hasLeftRight;
}

bool Ghost::atDeadEnd(const std::vector<Direction>& directions) { return (directions.size() == 1); }

bool Ghost::hasLeftStartingPoint() const {
    return manhattanDistance(homePosition, position) > 0.2;
}

void Ghost::goHome() {
    position = homePosition;
}
