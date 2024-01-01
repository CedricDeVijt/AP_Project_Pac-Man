#include "Ghost.h"
#include "EntityModel.h"
#include "Random.h"
#include <algorithm>
#include <cmath>
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
Ghost::Ghost(GhostType type, std::tuple<double, double, double, double> homePosition)
    : type(type), homePosition(homePosition), EntityModel(homePosition) {
    // start in waitmode
    fearMode = false;
    chaseMode = false;
    waitMode = true;
    hasLeftStartingPoint = false;
    position = homePosition;
    nudgeToGrid();
    // TODO set startTime Wait Mode
}

void Ghost::capturedByPacMan() {
    // go back to initial position and start chasing
    fearMode = false;
    chaseMode = true;
    waitMode = false;
    hasLeftStartingPoint = false;
    position = homePosition;
}

void Ghost::toFearMode() {
    fearMode = true;
    chaseMode = false;
    // TODO set startTime Fear Mode
}

bool Ghost::isFearMode() const { return fearMode; }

bool Ghost::isChaseMode() const { return chaseMode; }

bool Ghost::isWaitMode() const { return waitMode; }

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
    if (isWaitMode()) {
        // TODO use StopWatch
        waitMode = (timer++ < 1);
        chaseMode = !waitMode;
        direction = Direction::NONE;

    } else if (isChaseMode() || isFearMode()) {
        // choose a random direction if we have not left the starting point yet
        if (!hasLeftStartingPoint) {
            std::cout << "has not left starting point \n";
            // leave starting gate
            int random = Random::getInstance().getRandomNumber(possibleDirections.size());
            direction = possibleDirections[random];
            hasLeftStartingPoint = true;
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
                // determine random direction among possible directions
                int random = Random::getInstance().getRandomNumber(possibleDirections.size());
                direction = possibleDirections[random];
            } else {
                // determine direction of minimum/maximum manhattan distance based on fear setting
                Direction manhattanDirection;
                if (isFearMode()) {
                    std::cout << "go manhattan in fear mode\n";
                    manhattanDirection = getDirectionWithMinmumManhattanDistance(possibleDirections, pacManPosition);
                } else {
                    std::cout << "go manhattan \n";
                    manhattanDirection = getDirectionWithMaximumManhattanDistance(possibleDirections, pacManPosition);
                }
                //                if (manhattanDirection != direction) {
                //                    nudgeToGrid();
                //                }
                direction = manhattanDirection;
            }
        } else {
            std::cout << "go in same direction as previous\n";
        }
    } else {
        std::cout << "****************************************************Funky Stae\n";
    }
    position = step(direction, position);

    notifyObservers();
}

Direction Ghost::getDirectionWithMinmumManhattanDistance(
    const std::vector<Direction>& possibleDirections,
    const std::tuple<double, double, double, double>& pacManPosition) {
    double minDistance = std::numeric_limits<double>::max();
    Direction minDirection = NONE;
    for (auto possibleDirection : possibleDirections) {
        std::tuple<double, double, double, double> nextPosition = step(possibleDirection, position);
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
        std::tuple<double, double, double, double> nextPosition = step(possibleDirection, position);
        double distance = manhattanDistance(nextPosition, pacManPosition);
        if (distance > maxDistance) {
            maxDistance = distance;
            maxDirection = possibleDirection;
        }
    }
    return maxDirection;
}

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