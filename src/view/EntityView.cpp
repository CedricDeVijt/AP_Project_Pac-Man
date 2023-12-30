#include "EntityView.h"
#include "SpriteFactory.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int EntityView::getGridSize() const { return window->getSize().x / 20; }

int toPixel(double position, int canvasSize) {
    return (position + 1) * canvasSize / 2.0;  // [-1, 1] -> [0, 2] -> [0, canvasSize]
}

int EntityView::toPixelX(double position) {
    return toPixel(position, window->getSize().x);
}

int EntityView::toPixelY(double position) {
    return toPixel(position, window->getSize().x * 11 / 20); // same aspect ratio for a 20 by 11 grid
}


WallView::WallView(shared_ptr<Wall> wall) : wall(wall){
}

void WallView::update() {
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = wall->getPosition();
    int gridSize = getGridSize() +1;
    int posX = toPixelX(x);
    int posY = toPixelY(y);

    sf::RectangleShape rectangle(sf::Vector2f(gridSize, gridSize));
    rectangle.setPosition(posX, posY);
    rectangle.setFillColor(sf::Color::Blue);
    window->draw(rectangle);
}

CoinView::CoinView(shared_ptr<Coin> coin) : coin(coin){
}

void CoinView::update() {
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = coin->getPosition();
    int gridSize = getGridSize();
    int posX = toPixelX(x);
    int posY = toPixelY(y);

    window->draw(spriteFactory.createCoin(posX, posY, gridSize));
}

FruitView::FruitView(shared_ptr<Fruit> fruit) : fruit(fruit){
}

void FruitView::update() {
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = fruit->getPosition();
    int gridSize = getGridSize();
    int posX = toPixelX(x);
    int posY = toPixelY(y);

    window->draw(spriteFactory.createFruit(0, posX, posY, gridSize));
}

GhostView::GhostView(shared_ptr<Ghost> ghost) : ghost(ghost) {
}

void GhostView::update() {
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = ghost->getPosition();
    int gridSize = getGridSize();
    int posX = toPixelX(x);
    int posY = toPixelY(y);

    // TODO choose alternative to animate
    int alternative = 0;

    if (ghost->isFearMode()) {
        window->draw(spriteFactory.createGhost(GhostType::Fear, alternative, posX, posY, gridSize));
    } else {
        window->draw(spriteFactory.createGhost(ghost->getType(), alternative, posX, posY, gridSize));
    }
}


PacManView::PacManView(shared_ptr<PacMan> pacMan) : pacMan(pacMan) {
}

void PacManView::update() {
//    std::cout << "PacManView::update() PacManview was updated\n";
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = pacMan->getPosition();
//    std::cout << "Creating pacMan at " << x <<", " << y <<"\n";
//    std::cout << "New position at " << 30*20 *(x+1) <<", " << 30*11 * (y+1) <<"\n";

    sf::Vector2f scale = sf::Vector2f(1.5, 1.5);
    sf::Sprite sprite;

    switch (pacMan->getDirection()){
        case Direction::UP:
            sprite = SpriteFactory::getInstance().createPacMan(10, 30*20*(x+1), 30*11*(y+1), scale);
            break;
        case Direction::DOWN:
            sprite = SpriteFactory::getInstance().createPacMan(4, 30*20*(x+1), 30*11*(y+1), scale);
            break;
        case Direction::LEFT:
            sprite = SpriteFactory::getInstance().createPacMan(7, 30*20*(x+1), 30*11*(y+1), scale);
            break;
        case Direction::RIGHT:
//            sprite = SpriteFactory::getInstance().createPacMan(1, 30*20*(x+1), 30*11*(y+1), scale);
////            break;
        case Direction::NONE:
            sprite = SpriteFactory::getInstance().createPacMan(1, 30*20*(x+1), 30*11*(y+1), scale);
            break;
    }


    window->draw(sprite);
}
