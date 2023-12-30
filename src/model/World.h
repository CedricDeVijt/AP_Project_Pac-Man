#ifndef AP_PROJECT_PAC_MAN_WORLD_H
#define AP_PROJECT_PAC_MAN_WORLD_H

#include <memory>
#include <vector>

#include "AbstractFactory.h"
#include "Subject.h"

using std::shared_ptr;

class World {
public:
    explicit World(shared_ptr <AbstractFactory> factory, int level);

    ~World() = default;

    void update();

    void setDirectionPacMan(const Direction &direction);

private:
    bool isCollidingWithWall(const shared_ptr<EntityModel> &entityModel);
    bool isCollidingWithCoin(const shared_ptr<EntityModel> &entityModel);
    bool isCollidingWithFruit(const shared_ptr<EntityModel> &entityModel);
    bool isCollidingWithGhost(const shared_ptr<EntityModel> &entityModel);

private:
    std::vector<shared_ptr<Wall>> walls;
    std::vector<shared_ptr<Coin>> coins;
    std::vector<shared_ptr<Fruit>> fruits;
    std::vector<shared_ptr<Ghost>> ghosts;
    shared_ptr<PacMan> pacMan;


    std::vector<Direction> getPossibleDirections();
};


#endif //AP_PROJECT_PAC_MAN_WORLD_H
