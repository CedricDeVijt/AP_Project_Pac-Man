#include "FruitView.h"

#include "../model/Collectable.h"
#include "../model/Ghost.h"
#include "Camera.h"
#include "EntityView.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"
#include <utility>

FruitView::FruitView(shared_ptr<Fruit> fruit) : fruit(std::move(fruit)) {}

void FruitView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        const int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(fruit->getPosition());

        window->draw(spriteFactory.createFruit(fruit->getAlternative(), posX, posY, gridSize));
    }
}
