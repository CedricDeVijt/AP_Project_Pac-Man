#include "PacMan.h"

void PacMan::goHome() {
    // TODO implement

    notifyObservers();
}

PacMan::PacMan(std::tuple<double, double, double, double> position) : position(position) {}
