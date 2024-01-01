#ifndef AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
#define AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H

#include "../model/AbstractFactory.h"
#include <memory>
using std::shared_ptr;

class ConcreteFactory final : public AbstractFactory{
public:
    ConcreteFactory();
    ~ConcreteFactory() = default;

    shared_ptr<Ghost> createGhost(GhostType type, std::tuple<double, double, double, double> position) final;
    shared_ptr<PacMan> createPacMan(std::tuple<double, double, double, double> position) final;
    shared_ptr<Wall> createWall(std::tuple<double, double, double, double> position) final;
    shared_ptr<Coin> createCoin(std::tuple<double, double, double, double> position) final;
    shared_ptr<Fruit> createFruit(std::tuple<double, double, double, double> position) final;

};


#endif //AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
