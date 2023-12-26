#ifndef AP_PROJECT_PAC_MAN_WORLD_H
#define AP_PROJECT_PAC_MAN_WORLD_H

#include <memory>

#include "AbstractFactory.h"
#include "Subject.h"

using std::shared_ptr;

class World {
public:
    explicit World(shared_ptr<AbstractFactory> factory);

    ~World() = default;

    void update();

    Subject *getSubject(int x, int y);

private:
    Subject *grid[20][12];

    // TODO change to shared_ptr
    void setCoins(AbstractFactory *factory);

    void setWalls(AbstractFactory *factory);

    void setFruits(AbstractFactory *factory);

};


#endif //AP_PROJECT_PAC_MAN_WORLD_H
