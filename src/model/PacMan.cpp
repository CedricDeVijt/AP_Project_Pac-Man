#include "PacMan.h"

void PacMan::goHome() {
    // TODO implement

    notifyObservers();
}

void PacMan::setDirection(const Direction &direction_){
    direction = direction_;
}

PacMan::PacMan(std::tuple<double, double, double, double> position) : EntityModel(position){
    direction = NONE;
}

void PacMan::update() {
    double x, y, sizeX, sizeY;
    std::tie(x, y, sizeX, sizeY) = position;
    switch (direction) {
        case NONE:
            break;
        case LEFT:

            x -= 0.01;
            break;
        case RIGHT:
            x += 0.01;
            break;
        case UP:
            y -= 0.01;
            break;
        case DOWN:
            y += 0.01;
            break;
    }
    position = std::make_tuple(x, y, sizeX, sizeY);
    notifyObservers();
}

Direction PacMan::getDirection() const {
    return direction;
}
