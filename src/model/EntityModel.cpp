#include <utility>

#include "EntityModel.h"

std::tuple<double, double, double, double> EntityModel::getPosition() {
    return position;
}

bool EntityModel::overlapsWith(shared_ptr<EntityModel> entityModel) {
    return overlapsWith(entityModel, 0.0);
}

// check if there is an overlap between the 2 entities with a given percentage overlap
bool EntityModel::overlapsWith(shared_ptr<EntityModel> entityModel, double percentage) {
    // Extracting coordinates and sizes from tuples
    double x1, y1, sizeX1, sizeY1;
    std::tie(x1, y1, sizeX1, sizeY1) = position;

    double x2, y2, sizeX2, sizeY2;
    std::tie(x2, y2, sizeX2, sizeY2) = entityModel->position;

    // Check for overlap along both axes
    bool overlapX = (x1 < (x2 + sizeX2 * (1 - percentage))) && ((x1 + sizeX1 * (1 - percentage)) > x2);
    bool overlapY = (y1 < (y2 + sizeY2 * (1 - percentage))) && ((y1 + sizeY1 * (1 - percentage)) > y2);

    // The rectangles overlap if they intersect along both axes
    return overlapX && overlapY;
}

void EntityModel::update() {
    notifyObservers();
}


EntityModel::EntityModel(std::tuple<double, double, double, double> position) : position(std::move(position)) {}
