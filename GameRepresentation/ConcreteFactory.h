#ifndef AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
#define AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H

#include "../LogicLibrary/AbstractFactory.h"

class ConcreteFactory final : public AbstractFactory{

    Ghost* createGhost();
    PacMan* createPacMan();
    Wall* createWall(const WallType wallType);
    Coin* createCoin();
    Fruit* createFruit();

};


#endif //AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
