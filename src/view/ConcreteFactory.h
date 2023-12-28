#ifndef AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
#define AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H

#include "../model/AbstractFactory.h"
using std::shared_ptr;

class ConcreteFactory final : public AbstractFactory{
public:
    ConcreteFactory() = default;
    ConcreteFactory(shared_ptr<sf::RenderWindow> window);
    ~ConcreteFactory() = default;

    shared_ptr<Ghost> createGhost(GhostType type, std::tuple<double, double, double, double> position) final;
    shared_ptr<PacMan> createPacMan() final;
    shared_ptr<Wall> createWall(std::tuple<double, double, double, double> position) final;
    shared_ptr<Coin> createCoin() final;
    shared_ptr<Fruit>   createFruit() final;

private:
    shared_ptr<sf::RenderWindow> window;
};


#endif //AP_PROJECT_PAC_MAN_CONCRETEFACTORY_H
