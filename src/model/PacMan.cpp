#include "PacMan.h"
#include "Stopwatch.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

void PacMan::setTargetDirection(const Direction& newDirection) { targetDirection = newDirection; }

PacMan::PacMan(const std::tuple<double, double, double, double>& position, const int level)
    : EntityModel(position), homePosition(position), level(level) {
    direction = Direction::NONE;
}

Direction PacMan::getDirection() const { return direction; }

void PacMan::update(const std::vector<Direction>& directions) {
    // determine the acceleration for the given level
    const double acceleration = std::pow(accelerator, level);

    // if not dead
    if (lives != 0) {
        // Check if we can take the target direction, if so take the new direction and align back to the grid
        if (std::find(directions.begin(), directions.end(), targetDirection) != directions.end()) {
            direction = targetDirection;
            targetDirection = Direction::NONE;
            nudgeToGrid();
            position = step(direction, position, acceleration);
        } else if (std::find(directions.begin(), directions.end(), direction) != directions.end()) {
            // keep on going in the direction we were travelling if we can
            position = step(direction, position, acceleration);
        }
    }
    notifyObservers(EventType::TICK);
}

void PacMan::die() {
    // remove one life
    lives -= 1;

    // go back to starting point
    position = homePosition;
    direction = Direction::NONE;
    notifyObservers(EventType::PACMAN_DIES);
}

void PacMan::captureGhost() const { notifyObservers(EventType::PACMAN_CAPTURES_GHOST); }

void PacMan::captureFruit() const { notifyObservers(EventType::PACMAN_CAPTURES_FRUIT); }

void PacMan::captureCoin() const { notifyObservers(EventType::PACMAN_CAPTURES_COIN); }

bool PacMan::isDead() const { return lives == 0; }
