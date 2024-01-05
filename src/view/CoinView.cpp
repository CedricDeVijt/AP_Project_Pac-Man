#include "CoinView.h"

#include <utility>
#include "EntityView.h"
#include "Collectable.h"
#include "SpriteFactory.h"
#include "Window.h"
#include "Camera.h"


CoinView::CoinView(shared_ptr <Coin> coin) : coin(std::move(coin)) {}

void CoinView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        const int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(coin->getPosition());

        window->draw(spriteFactory.createCoin(posX, posY, gridSize));
    }
}

