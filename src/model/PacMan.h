#ifndef AP_PROJECT_PAC_MAN_PACMAN_H
#define AP_PROJECT_PAC_MAN_PACMAN_H

#include <vector>


#include "EntityModel.h"
#include "Direction.h"


class PacMan : public EntityModel {
private:
    Direction direction;
    Direction targetDirection = Direction::NONE;
    std::tuple<double, double, double, double> homePosition;
    int lives = 3;
public:
    explicit PacMan(std::tuple<double, double, double, double> position);

    void update(const std::vector<Direction> &directions);

    void setTargetDirection(const Direction &direction);

    Direction getDirection() const;

    void die();
    void captureGhost();
};


#endif //AP_PROJECT_PAC_MAN_PACMAN_H
