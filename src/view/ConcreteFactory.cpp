#include "ConcreteFactory.h"
#include "CoinView.h"
#include "EntityView.h"
#include "FruitView.h"
#include "GhostView.h"
#include "PacManView.h"
#include "Random.h"
#include "WallView.h"

shared_ptr<Ghost> ConcreteFactory::createGhost(const GhostType type,
                                               const std::tuple<double, double, double, double> position) {
    auto ghost = std::make_shared<Ghost>(type, position, level);
    const auto ghostView = std::make_shared<GhostView>(ghost);
    ghost->registerObserver(ghostView);
    return ghost;
}

shared_ptr<PacMan> ConcreteFactory::createPacMan(const std::tuple<double, double, double, double> position) {
    auto pacMan = std::make_shared<PacMan>(position, level);
    const auto pacManView = std::make_shared<PacManView>(pacMan);
    pacMan->registerObserver(pacManView);
    return pacMan;
}

shared_ptr<Wall> ConcreteFactory::createWall(const std::tuple<double, double, double, double> position) {
    auto wall = std::make_shared<Wall>(position);
    const auto wallView = std::make_shared<WallView>(wall);
    wall->registerObserver(wallView);
    return wall;
}

shared_ptr<Coin> ConcreteFactory::createCoin(const std::tuple<double, double, double, double> position) {
    auto coin = std::make_shared<Coin>(position);
    const auto coinView = std::make_shared<CoinView>(coin);
    coin->registerObserver(coinView);
    return coin;
}

shared_ptr<Fruit> ConcreteFactory::createFruit(const std::tuple<double, double, double, double> position) {
    auto fruit = std::make_shared<Fruit>(position, Random::getInstance().getRandomNumber(7));
    const auto fruitView = std::make_shared<FruitView>(fruit);
    fruit->registerObserver(fruitView);
    return fruit;
}

ConcreteFactory::ConcreteFactory(const int level) : level(level) {}
