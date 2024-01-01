#ifndef AP_PROJECT_PAC_MAN_ENTITYVIEW_H
#define AP_PROJECT_PAC_MAN_ENTITYVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "../model/Collectable.h"
#include "../model/Ghost.h"
#include "../model/PacMan.h"
#include "../model/Wall.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"

using std::shared_ptr;

/**
 * @class EntityView
 * @brief Base class for visual representation of entities in the game.
 */
class EntityView : public Observer {
protected:
    shared_ptr<sf::RenderWindow> window = WindowSingleton::getInstance().getWindow();
    SpriteFactory& spriteFactory = SpriteFactory::getInstance();

    /**
     * @brief Converts normalized coordinates to pixel coordinates on the X-axis.
     * @param position The normalized position on the X-axis.
     * @return The pixel position on the X-axis.
     */
    int toPixelX(double position);

    /**
     * @brief Converts normalized coordinates to pixel coordinates on the Y-axis.
     * @param position The normalized position on the Y-axis.
     * @return The pixel position on the Y-axis.
     */
    int toPixelY(double position);

    /**
     * @brief Gets the grid size based on the window size.
     * @return The size of a grid cell.
     */
    int getGridSize() const;
};

/**
 * @class PacManView
 * @brief Visual representation of the PacMan entity.
 */
class PacManView : public EntityView {
public:
    /**
     * @brief Constructs a PacManView object.
     * @param pacMan The PacMan entity to be visualized.
     */
    PacManView(shared_ptr<PacMan> pacMan);

    /**
     * @brief Updates the visual representation of PacMan.
     */
    void update() override;

private:
    shared_ptr<PacMan> pacMan;
};

/**
 * @class GhostView
 * @brief Visual representation of the Ghost entity.
 */
class GhostView : public EntityView {
public:
    /**
     * @brief Constructs a GhostView object.
     * @param ghost The Ghost entity to be visualized.
     */
    GhostView(shared_ptr<Ghost> ghost);

    /**
     * @brief Updates the visual representation of Ghost.
     */
    void update() override;

private:
    shared_ptr<Ghost> ghost;
};

/**
 * @class CoinView
 * @brief Visual representation of the Coin entity.
 */
class CoinView : public EntityView {
public:
    /**
     * @brief Constructs a CoinView object.
     * @param coin The Coin entity to be visualized.
     */
    CoinView(shared_ptr<Coin> coin);

    /**
     * @brief Updates the visual representation of Coin.
     */
    void update() override;

private:
    shared_ptr<Coin> coin;
};

/**
 * @class WallView
 * @brief Visual representation of the Wall entity.
 */
class WallView : public EntityView {
public:
    /**
     * @brief Constructs a WallView object.
     * @param wall The Wall entity to be visualized.
     */
    WallView(shared_ptr<Wall> wall);

    /**
     * @brief Updates the visual representation of Wall.
     */
    void update() override;

private:
    shared_ptr<Wall> wall;
};

/**
 * @class FruitView
 * @brief Visual representation of the Fruit entity.
 */
class FruitView : public EntityView {
public:
    /**
     * @brief Constructs a FruitView object.
     * @param fruit The Fruit entity to be visualized.
     */
    FruitView(shared_ptr<Fruit> fruit);

    /**
     * @brief Updates the visual representation of Fruit.
     */
    void update() override;

private:
    shared_ptr<Fruit> fruit;
};

#endif // AP_PROJECT_PAC_MAN_ENTITYVIEW_H
