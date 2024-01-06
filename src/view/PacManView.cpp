
#include "PacManView.h"
#include "Camera.h"
#include "EntityView.h"
#include "SpriteFactory.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

PacManView::PacManView(shared_ptr<PacMan> pacMan) : pacMan(std::move(pacMan)) {}

void PacManView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        // determine position
        int posX, posY, sizeX, sizeY;
        std::tie(posX, posY, sizeX, sizeY) = Camera::toPixelCoordinates(pacMan->getPosition());

        // animate PacMan by choosing a different variant dependent on the position
        constexpr int variants[] = {0, 1, 2, 1};
        const int variant = variants[((posX + posY) * 2 / getGridSize()) % 4];

        switch (pacMan->getDirection()) {
        case Direction::UP:
            window->draw(Singleton<SpriteFactory>::getInstance().createPacMan(9 + variant, posX, posY, sizeX));
            break;
        case Direction::DOWN:
            window->draw(Singleton<SpriteFactory>::getInstance().createPacMan(3 + variant, posX, posY, sizeX));
            break;
        case Direction::LEFT:
            window->draw(Singleton<SpriteFactory>::getInstance().createPacMan(6 + variant, posX, posY, sizeX));
            break;
        case Direction::RIGHT:
        case Direction::NONE:
            window->draw(Singleton<SpriteFactory>::getInstance().createPacMan(0 + variant, posX, posY, sizeX));
            break;
        }
    }
}
