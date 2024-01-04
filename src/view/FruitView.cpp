#include "FruitView.h"

#include <utility>
#include "EntityView.h"
#include "../model/Ghost.h"
#include "../model/Collectable.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"
#include "Camera.h"

FruitView::FruitView(shared_ptr <Fruit> fruit) : fruit(std::move(fruit)) {}

void FruitView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        const int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(fruit->getPosition());

        window->draw(spriteFactory.createFruit(fruit->getAlternative(), posX, posY, gridSize));
    }
}

