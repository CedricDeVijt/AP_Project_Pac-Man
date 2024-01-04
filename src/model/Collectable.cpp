#include "Collectable.h"

Collectable::Collectable(const std::tuple<double, double, double, double>& position) : EntityModel(position) {}

Fruit::Fruit(const std::tuple<double, double, double, double>& position, int alternative) : Collectable(position), alternative(alternative) {}

int Fruit::getAlternative() const {
    return alternative;
}

Coin::Coin(const std::tuple<double, double, double, double>& position) : Collectable(position) {}
