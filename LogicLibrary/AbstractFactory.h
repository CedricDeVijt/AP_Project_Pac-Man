#ifndef AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H
#define AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H

#include "Ghost.h"
#include "PacMan.h"
#include "Wall.h"
#include "Collectable.h"

class AbstractFactory {
public:

    virtual ~AbstractFactory() = default;

    virtual Ghost* createGhost() = 0;
    virtual PacMan* createPacMan() = 0;
    virtual Wall* createWall(const WallType wallType) = 0;
    virtual Coin* createCoin() = 0;
    virtual Fruit* createFruit() = 0;

};


#endif //AP_PROJECT_PAC_MAN_ABSTRACTFACTORY_H
