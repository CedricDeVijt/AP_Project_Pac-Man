#include "PacMan.h"
#include "Stopwatch.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

void PacMan::setTargetDirection(const Direction& direction) { targetDirection = direction; }

PacMan::PacMan(const std::tuple<double, double, double, double>& position, const int level) : EntityModel(position), level(level) {
    homePosition = position;
    direction = NONE;
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
            targetDirection = NONE;
            nudgeToGrid();
            position = step(direction, position, acceleration);
        } else if (std::find(directions.begin(), directions.end(), direction) != directions.end()) {
            // keep on going in the direction we were travelling if we can
            position = step(direction, position, acceleration);
        }
    }
    notifyObservers(TICK);
}

void PacMan::die() {
    // remove one life
    lives -= 1;

    // go back to starting point
    position = homePosition;
    direction = NONE;
    notifyObservers(PACMAN_DIES);
}

void PacMan::captureGhost() {
    notifyObservers(PACMAN_CAPTURES_GHOST);
}

void PacMan::captureFruit() {
    notifyObservers(PACMAN_CAPTURES_FRUIT);
}

void PacMan::captureCoin() {
    notifyObservers(PACMAN_CAPTURES_COIN);
}

bool PacMan::isDead() const {
    return lives == 0;
}
