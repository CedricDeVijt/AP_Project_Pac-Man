#ifndef AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H
#define AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H

#include "Collectable.h"
#include "Ghost.h"
#include "PacMan.h"
#include "Wall.h"
#include <memory>
using std::shared_ptr;

/**
 * @class AbstractFactory
 * @brief Abstract base class for creating game entities.
 */
class AbstractFactory {
public:
    /**
     * @brief Virtual destructor for the AbstractFactory class.
     */
    virtual ~AbstractFactory() = default;

    /**
     * @brief Creates a Ghost entity based on the specified GhostType and position.
     * @param type The type of the Ghost (e.g., Blinky, Pinky, etc.).
     * @param position A tuple representing the position (x, y, width, height) of the Ghost.
     * @return A shared pointer to the created Ghost entity.
     */
    virtual shared_ptr<Ghost> createGhost(const GhostType type,
                                          const std::tuple<double, double, double, double>& position) = 0;

    /**
     * @brief Creates a PacMan entity based on the specified position.
     * @param position A tuple representing the position (x, y, width, height) of PacMan.
     * @return A shared pointer to the created PacMan entity.
     */
    virtual shared_ptr<PacMan> createPacMan(const std::tuple<double, double, double, double>& position) = 0;

    /**
     * @brief Creates a Wall entity based on the specified position.
     * @param position A tuple representing the position (x, y, width, height) of the Wall.
     * @return A shared pointer to the created Wall entity.
     */
    virtual shared_ptr<Wall> createWall(const std::tuple<double, double, double, double>& position) = 0;

    /**
     * @brief Creates a Coin entity based on the specified position.
     * @param position A tuple representing the position (x, y, width, height) of the Coin.
     * @return A shared pointer to the created Coin entity.
     */
    virtual shared_ptr<Coin> createCoin(const std::tuple<double, double, double, double>& position) = 0;

    /**
     * @brief Creates a Fruit entity based on the specified position.
     * @param position A tuple representing the position (x, y, width, height) of the Fruit.
     * @return A shared pointer to the created Fruit entity.
     */
    virtual shared_ptr<Fruit> createFruit(const std::tuple<double, double, double, double>& position) = 0;
};

#endif // AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H
