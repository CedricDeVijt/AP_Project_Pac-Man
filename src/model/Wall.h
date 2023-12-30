#ifndef AP_PROJECT_PAC_MAN_WALL_H
#define AP_PROJECT_PAC_MAN_WALL_H


#include "EntityModel.h"


class Wall : public EntityModel {
public:
    Wall(std::tuple<double, double, double, double> position);
};


#endif //AP_PROJECT_PAC_MAN_WALL_H
