#include "FruitView.h"
#include "CoinView.h"
#include "EntityView.h"
#include "../model/Ghost.h"
#include "../model/Collectable.h"
#include "../model/Ghost.h"
#include "../model/PacMan.h"
#include "../model/Wall.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"
#include "Camera.h"

FruitView::FruitView(shared_ptr <Fruit> fruit) : fruit(fruit) {}

void FruitView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(fruit->getPosition());

        window->draw(spriteFactory.createFruit(fruit->getAlternative(), posX, posY, gridSize));
    }
}

