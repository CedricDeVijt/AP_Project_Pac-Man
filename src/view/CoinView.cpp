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


CoinView::CoinView(shared_ptr <Coin> coin) : coin(coin) {}

void CoinView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(coin->getPosition());

        window->draw(spriteFactory.createCoin(posX, posY, gridSize));
    }
}

