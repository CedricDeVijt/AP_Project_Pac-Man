
#include "WallView.h"
#include "EntityView.h"
#include "SpriteFactory.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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

