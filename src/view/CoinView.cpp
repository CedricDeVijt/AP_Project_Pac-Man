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
        // determine position
        int posX, posY, sizeX, sizeY;
        std::tie(posX, posY, sizeX, sizeY) = Camera::toPixelCoordinates(coin->getPosition());

        // draw the sprite
        window->draw(spriteFactory.createCoin(posX, posY, sizeX));
    }
}
