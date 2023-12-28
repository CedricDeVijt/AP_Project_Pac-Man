#ifndef AP_PROJECT_PAC_MAN_GHOST_H
#define AP_PROJECT_PAC_MAN_GHOST_H


#include "EntityModel.h"


enum class GhostType {
    Blinky, Pinky, Inky, Clyde, Fear
};


class Ghost : public EntityModel {
public:
    Ghost(GhostType type, std::tuple<double, double, double, double> homePosition);
    void setHome(std::tuple<double, double, double, double> position);
    void toFearMode();

private:
    GhostType type;
    bool isFearMode;
    std::tuple<double, double, double, double> homePosition;
};


#endif //AP_PROJECT_PAC_MAN_GHOST_H
