#ifndef AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
#define AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H

#include "AbstractFactory.h"
#include <memory>
using std::shared_ptr;

/**
 * @class ConcreteFactory
 * @brief A concrete implementation of the AbstractFactory interface.
 */
class ConcreteFactory final : public AbstractFactory {
public:
    /**
     * @brief Constructs a ConcreteFactory object.
     * @param level The level of the game.
     */
    explicit ConcreteFactory(int level);

    /**
     * @brief Destructs a ConcreteFactory object.
     */
    ~ConcreteFactory() override = default;

    /**
     * @brief Creates a Ghost object of the specified type and position.
     * @param type The type of the Ghost (Blinky, Pinky, Inky, or Clyde).
     * @param position The position of the Ghost.
     * @return A shared pointer to the created Ghost.
     */
    shared_ptr<Ghost> createGhost(GhostType type, std::tuple<double, double, double, double> position) final;

    /**
     * @brief Creates a PacMan object with the specified position.
     * @param position The position of PacMan.
     * @return A shared pointer to the created PacMan.
     */
    shared_ptr<PacMan> createPacMan(std::tuple<double, double, double, double> position) final;

    /**
     * @brief Creates a Wall object with the specified position.
     * @param position The position of the Wall.
     * @return A shared pointer to the created Wall.
     */
    shared_ptr<Wall> createWall(std::tuple<double, double, double, double> position) final;

    /**
     * @brief Creates a Coin object with the specified position.
     * @param position The position of the Coin.
     * @return A shared pointer to the created Coin.
     */
    shared_ptr<Coin> createCoin(std::tuple<double, double, double, double> position) final;

    /**
     * @brief Creates a Fruit object with the specified position.
     * @param position The position of the Fruit.
     * @return A shared pointer to the created Fruit.
     */
    shared_ptr<Fruit> createFruit(std::tuple<double, double, double, double> position) final;

private:
    int level = 0; ///< The level of the current game
};

#endif // AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
