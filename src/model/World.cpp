#include "World.h"
#include <vector>
#include <string>
#include <iostream>

World::World(shared_ptr<AbstractFactory> factory) {

    std::vector<std::string> board{
            "wwwwwwwwwwwwwwwwwwww",
            "wfcccwccccccccwccccw",
            "wcwwcwcwwwwwwcwcwwcw",
            "wcwccccccccccccccwcw",
            "wcwcwwcww  wwcwwcwcw",
            "wPcccccw1234wccccccw",
            "wcwcwwcwwwwwwcwwcwcw",
            "wcwccccccccccccccwcw",
            "wcwwcwcwwwwwwcwcwwcw",
            "wccccwccccccccwcccfw",
            "wwwwwwwwwwwwwwwwwwww"
    };
    int items_x = board[0].length();
    int items_y = board.size();

    std::cout << "items x: " << items_x << "\n";
    std::cout << "items y: " << items_y << "\n";

    double size_x = 2.0 / items_x;
    double size_y = 2.0 / items_y;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++) {
            double position_x = j * size_x - 1.0;
            double position_y = i * size_y - 1.0;
            std::tuple<double, double, double, double> position(position_x, position_y, size_x, size_y);
            switch (board[i][j]) {
                case 'w':
                    walls.push_back(factory->createWall(position));
                    break;
                case 'c':
                    coins.push_back(factory->createCoin(position));
                    break;
                case 'f':
                    fruits.push_back(factory->createFruit(position));
                    break;
                case '1':
                    ghosts.push_back(factory->createGhost(GhostType::Blinky, position));
                    break;
                case '2':
                    ghosts.push_back(factory->createGhost(GhostType::Pinky, position));
                    break;
                case '3':
                    ghosts.push_back(factory->createGhost(GhostType::Inky, position));
                    break;
                case '4':
                    ghosts.push_back(factory->createGhost(GhostType::Clyde, position));
                    break;
                case 'P':
                    pacMan = factory->createPacMan(position);
                    break;
                default:
                    break;
            }
        }
    }
}

void World::update() {
    for (auto &ghost: ghosts) {
        ghost->update();
    }

    for (auto &coin: coins) {
        coin->update();
    }

    for (auto &fruit: fruits) {
        fruit->update();
    }

    for (auto &wall: walls) {
        wall->update();
    }

    pacMan->update(getPossibleDirections());

}

void World::setDirectionPacMan(const Direction &direction) {

    for (auto possibleDirection: getPossibleDirections()) {
        if (possibleDirection == direction) {
            pacMan->setDirection(direction);
            return;
        }
    }
}

std::vector<Direction> World::getPossibleDirections() {
    double x, y, sizeX, sizeY;
    std::tie(x, y, sizeX, sizeY) = pacMan->getPosition();
    std::vector<Direction> possibleDirections;



    return {RIGHT, LEFT, UP, DOWN};
}
