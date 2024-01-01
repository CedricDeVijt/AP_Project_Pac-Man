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

    // TODO base on time
    int variants[] = {0,1};
    int variant = variants[((posX + posY)*2 / gridSize) % 2];

    if (ghost->isFearMode()) {
        window->draw(spriteFactory.createGhost(GhostType::Fear, variant, posX, posY, gridSize));
    } else {
        window->draw(spriteFactory.createGhost(ghost->getType(), variant, posX, posY, gridSize));
    }
}


PacManView::PacManView(shared_ptr<PacMan> pacMan) : pacMan(pacMan) {
}

void PacManView::update() {
    // TODO do this properly using camera
    double x, y, size_x, size_y;
    std::tie(x, y, size_x, size_y) = pacMan->getPosition();
    int gridSize = getGridSize();
    int posX = toPixelX(x);
    int posY = toPixelY(y);

    // animate PacMan by choosing a different variant dependent on the position (really should be based on time)
    // TODO base on time
    int variants[] = {0,1,2,1};
    int variant = variants[((posX + posY)*2 / gridSize) % 4];

    switch (pacMan->getDirection()){
        case Direction::UP:
            window->draw(SpriteFactory::getInstance().createPacMan(9 + variant, posX, posY, gridSize));
            break;
        case Direction::DOWN:
            window->draw(SpriteFactory::getInstance().createPacMan(3 + variant, posX, posY, gridSize));
            break;
        case Direction::LEFT:
            window->draw(SpriteFactory::getInstance().createPacMan(6 + variant, posX, posY, gridSize));
            break;
        case Direction::RIGHT:
        case Direction::NONE:
            window->draw(SpriteFactory::getInstance().createPacMan(0 + variant, posX, posY, gridSize));
            break;
    }
}
