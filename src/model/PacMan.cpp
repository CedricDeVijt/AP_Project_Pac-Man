#include "PacMan.h"
#include "Stopwatch.h"
#include <vector>
#include <algorithm>
#include <iostream>



void PacMan::setTargetDirection(const Direction &direction){
    targetDirection = direction;
}



PacMan::PacMan(std::tuple<double, double, double, double> position) : EntityModel(position){
    homePosition = position;
    direction = NONE;
}


Direction PacMan::getDirection() const {
    return direction;
}

void PacMan::update(const std::vector<Direction> &directions) {
    // if not dead
    if (lives != 0) {
        // Check if we can take the target direction, if so take the new direction and align back to the grid
        if (std::find(directions.begin(), directions.end(), targetDirection) != directions.end()) {
            direction = targetDirection;
            targetDirection = NONE;
            nudgeToGrid();
            position = step(direction, position);
        } else if (std::find(directions.begin(), directions.end(), direction) != directions.end()) {
            // keep on going in the direction we were travelling if we can
            position = step(direction, position);
        }
    }
    notifyObservers();
}

void PacMan::die() {
    // remove one life
    lives -=1;

    // go back to starting point
    position = homePosition;
    direction = NONE;
    notifyObservers();
}

void PacMan::captureGhost() {
    // TODO
}
