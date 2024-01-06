#include "GhostView.h"
#include "Camera.h"
#include "EntityView.h"
#include "Ghost.h"
#include "SpriteFactory.h"
#include "Window.h"
#include <utility>

GhostView::GhostView(shared_ptr<Ghost> ghost) : ghost(std::move(ghost)) {}

void GhostView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        // determine position
        int posX, posY, sizeX, sizeY;
        std::tie(posX, posY, sizeX, sizeY) = Camera::toPixelCoordinates(ghost->getPosition());

        // animate ghost by choosing a different variant dependent on the position
        constexpr int variants[] = {0, 1};
        const int variant = variants[((posX + posY) * 2 / getGridSize()) % 2];

        if (ghost->isFearMode()) {
            window->draw(spriteFactory.createGhost(GhostType::Fear, variant, posX, posY, sizeX));
        } else {
            window->draw(spriteFactory.createGhost(ghost->getType(), variant, posX, posY, sizeX));
        }
    }
}
