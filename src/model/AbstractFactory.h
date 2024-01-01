#ifndef AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H
#define AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H

#include "../view/SpriteFactory.h"
#include "Collectable.h"
#include "Ghost.h"
#include "PacMan.h"
#include "Wall.h"
#include <SFML/Graphics.hpp>
#include <memory>
using std::shared_ptr;

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;

    virtual shared_ptr<Ghost> createGhost(GhostType type, std::tuple<double, double, double, double> position) = 0;
    virtual shared_ptr<PacMan> createPacMan(std::tuple<double, double, double, double> position) = 0;
    virtual shared_ptr<Wall> createWall(std::tuple<double, double, double, double> position) = 0;
    virtual shared_ptr<Coin> createCoin(std::tuple<double, double, double, double> position) = 0;
    virtual shared_ptr<Fruit> createFruit(std::tuple<double, double, double, double> position) = 0;
};

#endif // AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H
