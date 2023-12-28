#include "ConcreteFactory.h"
#include "EntityView.h"

shared_ptr<Ghost> ConcreteFactory::createGhost(GhostType type, std::tuple<double, double, double, double> position) {
    shared_ptr<Ghost> ghost = std::make_shared<Ghost>(type, position);
    shared_ptr<GhostView> ghostView = std::make_shared<GhostView>(type, position);
    ghost->registerObserver(ghostView);
    return ghost;

}

shared_ptr<PacMan> ConcreteFactory::createPacMan(std::tuple<double, double, double, double> position) {
    shared_ptr<PacMan> pacMan = std::make_shared<PacMan>(position);
    shared_ptr<PacManView> pacManView = std::make_shared<PacManView>(pacMan);
    pacMan->registerObserver(pacManView);
    return pacMan;
}

shared_ptr<Wall> ConcreteFactory::createWall(std::tuple<double, double, double, double> position) {
    shared_ptr<Wall> wall = std::make_shared<Wall>();
    shared_ptr<WallView> wallView = std::make_shared<WallView>(position);
    wall->registerObserver(wallView);
    return wall;
}

shared_ptr<Coin> ConcreteFactory::createCoin(std::tuple<double, double, double, double> position) {
    shared_ptr<Coin> coin = std::make_shared<Coin>();
    shared_ptr<CoinView> coinView = std::make_shared<CoinView>(position);
    coin->registerObserver(coinView);
    return coin;
}

shared_ptr<Fruit> ConcreteFactory::createFruit(std::tuple<double, double, double, double> position) {
    shared_ptr<Fruit> fruit = std::make_shared<Fruit>();
    shared_ptr<FruitView> fruitView = std::make_shared<FruitView>(position);
    fruit->registerObserver(fruitView);
    return fruit;
}

ConcreteFactory::ConcreteFactory() {

}
