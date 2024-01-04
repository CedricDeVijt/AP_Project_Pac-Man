
#include "PacManView.h"
#include "EntityView.h"
#include "SpriteFactory.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>
#include <iostream>


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
