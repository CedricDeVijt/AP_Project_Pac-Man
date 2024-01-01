#ifndef AP_PROJECT_PAC_MAN_WORLD_H
#define AP_PROJECT_PAC_MAN_WORLD_H

#include <memory>
#include <vector>

#include "AbstractFactory.h"
#include "Score.h"
#include "Subject.h"

using std::shared_ptr;

class World {
public:
    explicit World(shared_ptr<AbstractFactory> factory, int level, shared_ptr<Score> score);

    ~World() = default;

    void update();

    void setDirectionPacMan(const Direction& direction);

    bool isLevelComplete();
    bool isAllLevelsComplete();

private:
    std::vector<shared_ptr<Wall>> walls;
    std::vector<shared_ptr<Coin>> coins;
    std::vector<shared_ptr<Fruit>> fruits;
    std::vector<shared_ptr<Ghost>> ghosts;
    shared_ptr<PacMan> pacMan;
    shared_ptr<Score> score;
    int level;

    std::vector<Direction> getPossibleDirections(std::shared_ptr<EntityModel> entityModel, double tolerance);
    void collect(std::vector<std::shared_ptr<Coin>>& coins);
    void collect(std::vector<std::shared_ptr<Fruit>>& fruits);
};

#endif // AP_PROJECT_PAC_MAN_WORLD_H
