//
// Created by Cedric De Vijt on 25/11/2023.
//

#include "EntityModel.h"

std::tuple<double, double, double, double> EntityModel::getPosition() {
    return position;
}

bool EntityModel::overlapsWith(EntityModel entityModel) {
    // Extracting coordinates and sizes from tuples
    int x1, y1, sizeX1, sizeY1;
    std::tie(x1, y1, sizeX1, sizeY1) = position;

    int x2, y2, sizeX2, sizeY2;
    std::tie(x2, y2, sizeX2, sizeY2) = entityModel.position;

    // Check for overlap along both axes
    bool overlapX = (x1 < (x2 + sizeX2)) && ((x1 + sizeX1) > x2);
    bool overlapY = (y1 < (y2 + sizeY2)) && ((y1 + sizeY1) > y2);

    // The rectangles overlap if they intersect along both axes
    return overlapX && overlapY;
}

void EntityModel::update() {
    notifyObservers();
}
