#ifndef AP_PROJECT_PAC_MAN_WALL_H
#define AP_PROJECT_PAC_MAN_WALL_H

#include "EntityModel.h"

/**
 * @class Wall
 * @brief Represents a wall in the game.
 */
class Wall final : public EntityModel {
public:
    /**
     * @brief Constructs a Wall object with the specified position.
     * @param position The position of the wall.
     */
    explicit Wall(const std::tuple<double, double, double, double>& position);
};

#endif // AP_PROJECT_PAC_MAN_WALL_H
