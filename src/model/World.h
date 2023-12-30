#ifndef AP_PROJECT_PAC_MAN_WORLD_H
#define AP_PROJECT_PAC_MAN_WORLD_H

#include <memory>
#include <vector>

#include "AbstractFactory.h"
#include "Subject.h"

using std::shared_ptr;

class World {
public:
    explicit World(shared_ptr<AbstractFactory> factory);

    ~World() = default;

    void update();

    void setDirectionPacMan(const Direction &direction);

//    Subject *getSubject(int x, int y);

private:
    std::vector<shared_ptr<Wall>> walls;
    std::vector<shared_ptr<Coin>> coins;
    std::vector<shared_ptr<Fruit>> fruits;
    std::vector<shared_ptr<Ghost>> ghosts;
    shared_ptr<PacMan> pacMan;


};


#endif //AP_PROJECT_PAC_MAN_WORLD_H
