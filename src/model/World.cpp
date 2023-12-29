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
                    grid[i][j] = factory->createWall(position);
                    break;
                case 'c':
                    grid[i][j] = factory->createCoin(position);
                    break;
                case 'f':
                    grid[i][j] = factory->createFruit(position);
                    break;
                case '1':
                    grid[i][j] = factory->createGhost(GhostType::Blinky, position);
                    break;
                case '2':
                    grid[i][j] = factory->createGhost(GhostType::Pinky, position);
                    break;
                case '3':
                    grid[i][j] = factory->createGhost(GhostType::Inky, position);
                    break;
                case '4':
                    grid[i][j] = factory->createGhost(GhostType::Clyde, position);
                    break;
                case 'P':
                    pacMan = factory->createPacMan(position);
                    grid[i][j] = pacMan;
                    break;
                default:
                    break;
            }
        }
    }

//    // create PacMan
//    shared_ptr<PacMan> pacMan = factory->createPacMan();
//    pacMan->goHome();
//
//    // create Ghosts
//    shared_ptr<Ghost> pinky = factory->createGhost(GhostType::Pinky, std::make_tuple(8*size_x, 5* size_y, size_x, size_y));
//    shared_ptr<Ghost> clyde = factory->createGhost(GhostType::Clyde, std::make_tuple(9*size_x, 5* size_y, size_x, size_y));
//    shared_ptr<Ghost> inky = factory->createGhost(GhostType::Inky, std::make_tuple(10*size_x, 5* size_y, size_x, size_y));
//    shared_ptr<Ghost> blinky = factory->createGhost(GhostType::Blinky, std::make_tuple(11*size_x, 5* size_y, size_x, size_y));

//    std::cout << pinky.overlapsWith(clyde) << "\n";
}

void World::update() {
    const int grid_size_x = sizeof(grid) / sizeof(grid[0]);
    const int grid_size_y = sizeof(grid[0]) / sizeof(grid[0][0]);

    for (int i = 0; i < grid_size_x; i++) {
        for (int j = 0; j < grid_size_y; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j]->update();
            }
        }
    }
}

void World::setDirectionPacMan(Direction direction) {
    pacMan->setDirection(direction);
}
