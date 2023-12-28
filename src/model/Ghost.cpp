#include "Ghost.h"

Ghost::Ghost(GhostType type, std::tuple<double, double, double, double> homePosition)
        : type(type), homePosition(homePosition) {}


// TODO implement going home
//void Ghost::goHome() {
//    switch (type) {
//        case GhostType::Blinky :
//            break;
//        case GhostType::Inky :
//            break;
//        case GhostType::Clyde :
//            break;
//        case GhostType::Pinky :
//            break;
//        default:
//            break;
//    }
//    notifyObservers();
//}

void Ghost::toFearMode() {

}
