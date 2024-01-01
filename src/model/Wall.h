#ifndef AP_PROJECT_PAC_MAN_WALL_H
#define AP_PROJECT_PAC_MAN_WALL_H

#include "EntityModel.h"

/**
 * @class Wall
 * @brief Represents a wall in the game.
 */
class Wall : public EntityModel {
public:
    /**
     * @brief Constructs a Wall object with the specified position.
     * @param position The position of the wall.
     */
    Wall(std::tuple<double, double, double, double> position);
};

#endif // AP_PROJECT_PAC_MAN_WALL_H
