#include "EntityModel.h"

#include "Ghost.h"
#include "Stopwatch.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>
#include <vector>

std::tuple<double, double, double, double> EntityModel::getPosition() const { return position; }

bool EntityModel::overlapsWith(const shared_ptr<EntityModel>& entityModel) const {
    return overlapsWith(entityModel, 0.0);
}

// check if there is an overlap between the 2 entities with a given percentage overlap
bool EntityModel::overlapsWith(const shared_ptr<EntityModel>& entityModel, double percentage) const {
    // Extracting coordinates and sizes from tuples
    double x1, y1, sizeX1, sizeY1;
    std::tie(x1, y1, sizeX1, sizeY1) = position;

    double x2, y2, sizeX2, sizeY2;
    std::tie(x2, y2, sizeX2, sizeY2) = entityModel->position;

    // Check for overlap along both axes
    const bool overlapX = (x1 < (x2 + sizeX2 * (1 - percentage))) && ((x1 + sizeX1 * (1 - percentage)) > x2);
    const bool overlapY = (y1 < (y2 + sizeY2 * (1 - percentage))) && ((y1 + sizeY1 * (1 - percentage)) > y2);

    // The rectangles overlap if they intersect along both axes
    return overlapX && overlapY;
}

void EntityModel::processEvent(EventType eventType) { notifyObservers(eventType); }

double roundToClosestMultiple(double value, double multiple) {
    // Calculate the rounded result to the nearest integer
    const double roundedValue = std::round(value / multiple);

    // Multiply by the multiple to get the closest multiple
    const double result = roundedValue * multiple;

    return result;
}

void EntityModel::nudgeToGrid() {
    double x, y, sizeX, sizeY;
    std::tie(x, y, sizeX, sizeY) = position;
    x = roundToClosestMultiple(x + 1, sizeX) - 1;
    y = roundToClosestMultiple(y + 1, sizeY) - 1;
    position = std::make_tuple(x, y, sizeX, sizeY);
}

EntityModel::EntityModel(std::tuple<double, double, double, double> position) : position(std::move(position)) {}

// calculate the position after taking a step in a direction
std::tuple<double, double, double, double> EntityModel::step(
    Direction direction, const std::tuple<double, double, double, double>& startPosition, double accelerator) {
    // calculate step in each direction
    const auto deltaTime = Stopwatch::getInstance().getDeltaTime();
    const double stepX = SPEED * deltaTime * accelerator;
    const double stepY = stepX * 22 / 11; // compensate for grid aspect ratio

    double x, y, sizeX, sizeY;
    std::tie(x, y, sizeX, sizeY) = startPosition;
    if (direction == Direction::LEFT) {
        x -= stepX;
    } else if (direction == Direction::RIGHT) {
        x += stepX;
    } else if (direction == Direction::UP) {
        y -= stepY;
    } else if (direction == Direction::DOWN) {
        y += stepY;
    }
    return std::make_tuple(x, y, sizeX, sizeY);
}