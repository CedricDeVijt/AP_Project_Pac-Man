#include "CoinView.h"

#include "Camera.h"
#include "Collectable.h"
#include "EntityView.h"
#include "SpriteFactory.h"
#include "Window.h"
#include <utility>

CoinView::CoinView(shared_ptr<Coin> coin) : coin(std::move(coin)) {}

void CoinView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        const int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(coin->getPosition());

        window->draw(spriteFactory.createCoin(posX, posY, gridSize));
    }
}
