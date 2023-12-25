#ifndef AP_PROJECT_PAC_MAN_WORLD_H
#define AP_PROJECT_PAC_MAN_WORLD_H

#include "AbstractFactory.h"
#include "Subject.h"


class World {
public:
    World();

    ~World();

    void update();

private:
    Subject *grid[20][12];

    void setCoins(AbstractFactory *factory);

    void setWalls(AbstractFactory *factory);

    void setFruits(AbstractFactory *factory);

    explicit World(AbstractFactory *factory);

};


#endif //AP_PROJECT_PAC_MAN_WORLD_H
