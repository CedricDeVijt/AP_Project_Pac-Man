#include "EntityView.h"
#include "SpriteFactory.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int EntityView::getGridSize() const { return window->getSize().x / 20; }

WallView::WallView(shared_ptr <Wall> wall) : wall(wall) {}

void WallView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        int gridSize = getGridSize() + 1;  // +1 since rounding effects might leave a small gap otherwise
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(wall->getPosition());

        sf::RectangleShape rectangle(sf::Vector2f(gridSize, gridSize));
        rectangle.setPosition(posX, posY);
        rectangle.setFillColor(sf::Color::Blue);
        window->draw(rectangle);
    }
}

CoinView::CoinView(shared_ptr <Coin> coin) : coin(coin) {}

void CoinView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(coin->getPosition());

        window->draw(spriteFactory.createCoin(posX, posY, gridSize));
    }
}

FruitView::FruitView(shared_ptr <Fruit> fruit) : fruit(fruit) {}

void FruitView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(fruit->getPosition());

        window->draw(spriteFactory.createFruit(fruit->getAlternative(), posX, posY, gridSize));
    }
}

GhostView::GhostView(shared_ptr <Ghost> ghost) : ghost(ghost) {}

void GhostView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(ghost->getPosition());

        // animate ghost by choosing a different variant dependent on the position
        int variants[] = {0, 1};
        int variant = variants[((posX + posY) * 2 / gridSize) % 2];

        if (ghost->isFearMode()) {
            window->draw(spriteFactory.createGhost(GhostType::Fear, variant, posX, posY, gridSize));
        } else {
            window->draw(spriteFactory.createGhost(ghost->getType(), variant, posX, posY, gridSize));
        }
    }
}

PacManView::PacManView(shared_ptr <PacMan> pacMan) : pacMan(pacMan) {}

void PacManView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK){
        int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(pacMan->getPosition());

        // animate PacMan by choosing a different variant dependent on the position
        int variants[] = {0, 1, 2, 1};
        int variant = variants[((posX + posY) * 2 / gridSize) % 4];

        switch (pacMan->getDirection()) {
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
}
