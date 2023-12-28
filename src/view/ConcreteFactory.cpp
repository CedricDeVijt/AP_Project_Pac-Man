#include "ConcreteFactory.h"
#include "EntityView.h"

shared_ptr<Ghost> ConcreteFactory::createGhost(GhostType type, std::tuple<double, double, double, double> position) {
    shared_ptr<Ghost> ghost = std::make_shared<Ghost>(type, position);
    return ghost;
}

shared_ptr<PacMan> ConcreteFactory::createPacMan() {
    return std::make_shared<PacMan>();
}

shared_ptr<Wall> ConcreteFactory::createWall(std::tuple<double, double, double, double> position) {
    shared_ptr<Wall> wall = std::make_shared<Wall>();
    shared_ptr<WallView> wallView = std::make_shared<WallView>(position);
    wall->registerObserver(wallView);
    return wall;
}

shared_ptr<Coin> ConcreteFactory::createCoin() {
    return std::make_shared<Coin>();
}

shared_ptr<Fruit> ConcreteFactory::createFruit() {
    return std::make_shared<Fruit>();
}

ConcreteFactory::ConcreteFactory(shared_ptr <sf::RenderWindow> window) {

}
