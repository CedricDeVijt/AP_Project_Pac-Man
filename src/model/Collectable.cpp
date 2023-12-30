#include "Collectable.h"

Collectable::Collectable(std::tuple<double, double, double, double> position) : EntityModel(position) {}

Fruit::Fruit(std::tuple<double, double, double, double> position) : Collectable(position) {}

Coin::Coin(std::tuple<double, double, double, double> position) : Collectable(position) {}
