#include "PacMan.h"
#include <cmath>
#include <vector>
#include <algorithm>

void PacMan::goHome() {
    // TODO implement

    notifyObservers();
}

double roundToClosestMultiple(double value, double multiple) {
    // Calculate the rounded result to the nearest integer
    double roundedValue = std::round(value / multiple);

    // Multiply by the multiple to get the closest multiple
    double result = roundedValue * multiple;

    return result;
}

void PacMan::setTargetDirection(const Direction &direction){
    targetDirection = direction;
}


void PacMan::nudgeToGrid() {
    double x, y, sizeX, sizeY;
    std::tie(x, y, sizeX, sizeY) = position;
    x = roundToClosestMultiple(x + 1, sizeX) -1;
    y = roundToClosestMultiple(y + 1 , sizeY) -1;
    position = std::make_tuple(x, y, sizeX, sizeY);
}


PacMan::PacMan(std::tuple<double, double, double, double> position) : EntityModel(position){
    direction = NONE;
}


Direction PacMan::getDirection() const {
    return direction;
}

void PacMan::update(const std::vector<Direction> &directions) {
    // Check if we can take the target direction, if so take the new direction and align back to the grid
    if (std::find(directions.begin(), directions.end(), targetDirection) != directions.end()) {
        direction = targetDirection;
        targetDirection = NONE;
        nudgeToGrid();
    }

    // take a step in the direction
    double stepX = 0.01;
    double stepY = stepX *22/11; // compensate for grid aspect ratio
    double x, y, sizeX, sizeY;
    std::tie(x, y, sizeX, sizeY) = position;
    for (auto possibleDirection: directions) {
        if (possibleDirection == LEFT and direction == LEFT) {
            x -= stepX;
            break;
        } else if (possibleDirection == RIGHT and direction == RIGHT) {
            x += stepX;
            break;
        } else if (possibleDirection == UP and direction == UP) {
            y -= stepY;
            break;
        } else if (possibleDirection == DOWN and direction == DOWN) {
            y += stepY;
            break;
        }
    }
    position = std::make_tuple(x, y, sizeX, sizeY);
    notifyObservers();
}
