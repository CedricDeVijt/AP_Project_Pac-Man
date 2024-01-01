#include "World.h"
#include "Stopwatch.h"
#include <vector>
#include <string>
#include <iostream>

World::World(shared_ptr<AbstractFactory> factory, int level, shared_ptr<Score> score) : score(score) {

    std::vector<std::string> level_1{
            "wwwwwwwwwwwwwwwwwwww",
            "wfcccwccccccccwccccw",
            "wcwwcwcwwwwwwcwcwwcw",
            "wcwccccccccccccccwcw",
            "wcwcwwcwwGGwwcwwcwcw",
            "wPcccccw1234wccccccw",
            "wcwcwwcwwwwwwcwwcwcw",
            "wcwccccccccccccccwcw",
            "wcwwcwcwwwwwwcwcwwcw",
            "wccccwccccccccwcccfw",
            "wwwwwwwwwwwwwwwwwwww"
    };
//    std::vector<std::string> level_1{
//            "                    ",
//            " P                  ",
//            "                    ",
//            "                    ",
//            "       ww  ww       ",
//            "       w   4w       ",
//            "       wwwwww       ",
//            "                    ",
//            "                    ",
//            "                    ",
//            "                    ",
//    };
    std::vector<std::string> level_2{
            "wwwwwwwwwwwwwwwwwwww",
            "wfcccwccccccccwcccfw",
            "wcwwcwcwcwwcwcwcwwcw",
            "wcwccwcwccccwcwccwcw",
            "wcwcwwcwwwwwwcwwcwcw",
            "wPcccccw1234wccccccw",
            "wwwcwcwwwccwwwcwcwww",
            "wcccwccccccccccwcccw",
            "wcwwwwcwwcwwwcwwwwcw",
            "wcccfcccwccwccccfccw",
            "wwwwwwwwwwwwwwwwwwww",
    };
    std::vector<std::string> board = (level % 2 == 0) ? level_1 : level_2;

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
    Stopwatch::getInstance().tick();

    for (auto &coin: coins) {
        coin->update();
    }

    for (auto &fruit: fruits) {
        fruit->update();
    }

    for (auto &ghost: ghosts) {
        if (ghost->overlapsWith(pacMan)) {
            if (ghost->isFearMode()) {
                pacMan->captureGhost();
                ghost->capturedByPacMan();
                score->pacManCapturesGhost();
            } else {
                pacMan->die();
                score->pacManCapturedByGhost();
            }
        }
        const std::vector <Direction> &possibleDirections = getPossibleDirections(ghost, 0.1);
        ghost->update(possibleDirections, pacMan->getPosition());
    }

    pacMan->update(getPossibleDirections(pacMan, 0.1));
    collect(coins);
    collect(fruits);

    for (auto &wall: walls) {
        wall->update();
    }
}

void World::collect(std::vector<std::shared_ptr<Coin>>& collectables) {
    // Define the condition for removal (overlap with PacMan)
    auto condition = [this](const std::shared_ptr<Collectable>& collectable) {
        return collectable->overlapsWith(pacMan, 0.9);
    };
    // Use std::remove_if to move elements that satisfy the condition to the end
    auto newEnd = std::remove_if(collectables.begin(), collectables.end(), condition);
    // before removing, do something
    for (auto it = newEnd; it != collectables.end(); ++it) {
        score->pacManCapturesCoin();
    }
    // Use vector's erase member function to erase the elements from newEnd to the end
    collectables.erase(newEnd, collectables.end());
}


void World::collect(std::vector<std::shared_ptr<Fruit>>& collectables) {
    // Define the condition for removal (overlap with PacMan)
    auto condition = [this](const std::shared_ptr<Collectable>& collectable) {
        return collectable->overlapsWith(pacMan, 0.9);
    };
    // Use std::remove_if to move elements that satisfy the condition to the end
    auto newEnd = std::remove_if(collectables.begin(), collectables.end(), condition);
    // before removing, do something
    for (auto it = newEnd; it != collectables.end(); ++it) {
        for (auto ghost: ghosts) {
            ghost->toFearMode();
        }
    }
    // Use vector's erase member function to erase the elements from newEnd to the end
    collectables.erase(newEnd, collectables.end());
}

void World::setDirectionPacMan(const Direction &direction) {
    pacMan->setTargetDirection(direction);
}

std::vector<Direction> World::getPossibleDirections(std::shared_ptr<EntityModel> entityModel, double tolerance) {
    // Get the current position and size of the entity
    double x, y, sizeX, sizeY;
    std::tie(x, y, sizeX, sizeY) = entityModel->getPosition();

    double toleranceX = sizeX * tolerance;
    double toleranceY = sizeY * tolerance;

    // Initialize possible directions with all directions initially
    std::vector<Direction> possibleDirections = {LEFT, RIGHT, UP, DOWN};

    // Check if entity collides with the wall
    for (auto &wall : walls) {
        // Get wall's position and size
        double wallX, wallY, wallSizeX, wallSizeY;
        std::tie(wallX, wallY, wallSizeX, wallSizeY) = wall->getPosition();


        // Check UP DOWN, reduce width of box
        // Check for collision along the X-axis
        bool collisionX = x + toleranceX <= wallX + wallSizeX && x + sizeX - toleranceX >= wallX;
        bool collisionY = y - toleranceY <= wallY + wallSizeY && y + sizeY + toleranceY >= wallY;
        // If there is a collision along both axes, PacMan cannot move in that direction
        if (collisionX && collisionY) {
            if (y <= wallY) {
                possibleDirections.erase(std::remove(possibleDirections.begin(), possibleDirections.end(), DOWN), possibleDirections.end());
            } else if (y + sizeY >= wallY + wallSizeY) {
                possibleDirections.erase(std::remove(possibleDirections.begin(), possibleDirections.end(), UP), possibleDirections.end());
            }
        }

        // Check LEFT & RIGHT, reduce Height of box
        // Check for collision along the X-axis and Y-axis
        collisionX = x - toleranceX <= wallX + wallSizeX && x + sizeX + toleranceX >= wallX;
        collisionY = y + toleranceY <= wallY + wallSizeY && y + sizeY - toleranceY >= wallY;
        // If there is a collision along both axes, PacMan cannot move in that direction
        if (collisionX && collisionY) {
            // Remove the corresponding direction from the possible directions
            if (x <= wallX) {
                possibleDirections.erase(std::remove(possibleDirections.begin(), possibleDirections.end(), RIGHT), possibleDirections.end());
            } else if (x + sizeX >= wallX + wallSizeX) {
                possibleDirections.erase(std::remove(possibleDirections.begin(), possibleDirections.end(), LEFT), possibleDirections.end());
            }
        }

    }

    // Return the updated list of possible directions after checking for collisions with walls
    return possibleDirections;
}


bool World::isLevelComplete() {
        return coins.size() < 70;

        // TODO put back
        //    return coins.empty();
    }

bool World::isAllLevelsComplete() {
    return isLevelComplete() && level == 2;
}
