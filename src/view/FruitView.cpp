#include "FruitView.h"

#include "../util/Singleton.h"
#include "Camera.h"
#include "Collectable.h"
#include "Window.h"
#include <utility>

FruitView::FruitView(shared_ptr<Fruit> fruit) : fruit(std::move(fruit)) {}

void FruitView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        // determine position
        int posX, posY, sizeX, sizeY;
        std::tie(posX, posY, sizeX, sizeY) = Camera::toPixelCoordinates(fruit->getPosition());

        // draw the sprite
        window->draw(spriteFactory.createFruit(fruit->getAlternative(), posX, posY, sizeX));
    }
}
