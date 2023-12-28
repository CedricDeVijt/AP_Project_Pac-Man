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

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

//    Subject *getSubject(int x, int y);

private:
    shared_ptr<EntityModel> grid[12][20];
};


#endif //AP_PROJECT_PAC_MAN_WORLD_H
