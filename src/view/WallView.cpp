
#include "WallView.h"
#include "Camera.h"
#include "EntityView.h"
#include "SpriteFactory.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

WallView::WallView(shared_ptr<Wall> wall) : wall(std::move(wall)) {}

void WallView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        // determine position
        int posX, posY, sizeX, sizeY;
        std::tie(posX, posY, sizeX, sizeY) = Camera::toPixelCoordinates(wall->getPosition());

        sf::RectangleShape rectangle(sf::Vector2f(sizeX+1, sizeY +1)); // +1 since otherwise we might have gaps
                                                                        // between walls
        rectangle.setPosition(posX, posY);
        rectangle.setFillColor(sf::Color::Blue);
        window->draw(rectangle);
    }
}
