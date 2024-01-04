#ifndef AP_PROJECT_PAC_MAN_COLLECTABLE_H
#define AP_PROJECT_PAC_MAN_COLLECTABLE_H

#include "EntityModel.h"

/**
 * @class Collectable
 * @brief Represents a generic collectable entity in the game.
 */
class Collectable : public EntityModel {
public:
    /**
     * @brief Constructor for the Collectable class.
     * @param position A tuple representing the position (x, y, width, height) of the collectable entity.
     */
    explicit Collectable(std::tuple<double, double, double, double> position);
};

/**
 * @class Coin
 * @brief Represents a coin collectable entity in the game.
 */
class Coin final : public Collectable {
public:
    /**
     * @brief Constructor for the Coin class.
     * @param position A tuple representing the position (x, y, width, height) of the coin entity.
     */
    explicit Coin(std::tuple<double, double, double, double> position);
};

/**
 * @class Fruit
 * @brief Represents a fruit collectable entity in the game.
 */
class Fruit final : public Collectable {
public:
    /**
     * @brief Constructor for the Fruit class.
     * @param position A tuple representing the position (x, y, width, height) of the fruit entity.
     * @param alternative The type of fruit.
     */
    explicit Fruit(std::tuple<double, double, double, double> position, int alternative);

    /**
     * @brief The type of fruit.
     * @return the integer representation of the alternative.
     */
    int getAlternative() const;

private:
    int alternative; ///< The type of fruit
};

#endif // AP_PROJECT_PAC_MAN_COLLECTABLE_H