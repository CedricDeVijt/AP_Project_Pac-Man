#ifndef AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
#define AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H

#include "../model/AbstractFactory.h"

class ConcreteFactory final : public AbstractFactory{

    Ghost* createGhost() final;
    PacMan* createPacMan() final;
    Wall* createWall(WallType wallType) final;
    Coin* createCoin() final;
    Fruit*   createFruit() final;

};


#endif //AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
