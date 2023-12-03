#ifndef AP_PROJECT_PAC_MAN_WORLD_H
#define AP_PROJECT_PAC_MAN_WORLD_H

#include "AbstractFactory.h"
#include "Subject.h"


class World {
    Subject *grid[20][12];

    void setCoins(AbstractFactory* factory);

    void setWalls(AbstractFactory* factory);

    void setFruits(AbstractFactory* factory);

    explicit World(AbstractFactory* factory);

    // Is there a coin in the given position
    bool isCoin(int x, int y);

    // Is there a fruit in the given position
    bool isFruit(int x, int y);

    // Is there a wall in the given position
    bool isWall(int x, int y);

    // Is there a ghost in the given position
    bool isGhost(int x, int y);
};


#endif //AP_PROJECT_PAC_MAN_WORLD_H
