#ifndef AP_PROJECT_PAC_MAN_COLLECTABLE_H
#define AP_PROJECT_PAC_MAN_COLLECTABLE_H

#include "EntityModel.h"

class Collectable : public EntityModel {
public:
    explicit Collectable(std::tuple<double, double, double, double> position);
};

class Coin : public Collectable {
public:
    explicit Coin(std::tuple<double, double, double, double> position);
};

class Fruit : public Collectable {
public:
    explicit Fruit(std::tuple<double, double, double, double> position);
};

#endif //AP_PROJECT_PAC_MAN_COLLECTABLE_H