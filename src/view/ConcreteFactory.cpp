#include "ConcreteFactory.h"

Ghost* ConcreteFactory::createGhost() {
    return new Ghost();
}

PacMan* ConcreteFactory::createPacMan() {
    return new PacMan();
}

Wall* ConcreteFactory::createWall(const WallType wallType) {
    return new Wall(wallType);
}

Coin* ConcreteFactory::createCoin() {
    return new Coin();
}

Fruit* ConcreteFactory::createFruit() {
    return new Fruit();
}
