#include "World.h"

void World::setCoins(AbstractFactory* factory) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 12; j++) {
            grid[i][j] = factory->createCoin();
        }
    }
}

void World::setWalls(AbstractFactory* factory) {
    // Set top walls
    grid[0][0] = factory->createWall(CTL);
    for (int i = 1; i < 19; i++) {
        grid[i][0] = factory->createWall(H);
    }
    grid[19][0] = factory->createWall(CTR);

    // Set bottom walls
    grid[0][11] = factory->createWall(CBL);
    for (int i = 1; i < 19; i++) {
        grid[i][11] = factory->createWall(H);
    }
    grid[19][11] = factory->createWall(CBR);

    // Set left walls
    for (int i = 1; i < 11; i++) {
        grid[0][i] = factory->createWall(V);
    }

    // Set right walls
    for (int i = 1; i < 11; i++) {
        grid[19][i] = factory->createWall(V);
    }

    // TODO Set other walls
}

void World::setFruits(AbstractFactory* factory) {
    grid[1][1] = factory->createFruit();
    grid[18][10] = factory->createFruit();
}

World::World(AbstractFactory *factory) {
    setCoins(factory);

    setWalls(factory);

    setFruits(factory);



}
