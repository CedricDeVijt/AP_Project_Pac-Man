#ifndef AP_PROJECT_PAC_MAN_WALL_H
#define AP_PROJECT_PAC_MAN_WALL_H


#include "EntityModel.h"

enum WallType {
    CTL, CTR, CBL, CBR, H, V, TU, TD
};

class Wall : public EntityModel {
public:
    explicit Wall (WallType wallType);
};


#endif //AP_PROJECT_PAC_MAN_WALL_H
