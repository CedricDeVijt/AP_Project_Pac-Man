#ifndef AP_PROJECT_PAC_MAN_PACMAN_H
#define AP_PROJECT_PAC_MAN_PACMAN_H


#include "EntityModel.h"

enum Direction {
    LEFT, RIGHT, UP, DOWN, NONE
};


class PacMan : public EntityModel {
private:
    Direction direction;
public:
    explicit PacMan(std::tuple<double, double, double, double> position);

    void update() final;

    void setDirection(const Direction &direction);

    Direction getDirection() const;

    void goHome();
};


#endif //AP_PROJECT_PAC_MAN_PACMAN_H
