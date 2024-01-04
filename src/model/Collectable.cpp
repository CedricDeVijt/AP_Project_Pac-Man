#include "Collectable.h"

Collectable::Collectable(std::tuple<double, double, double, double> position) : EntityModel(position) {}

Fruit::Fruit(std::tuple<double, double, double, double> position, int alternative) : Collectable(position), alternative(alternative) {}

int Fruit::getAlternative() const {
    return alternative;
}

Coin::Coin(std::tuple<double, double, double, double> position) : Collectable(position) {}
