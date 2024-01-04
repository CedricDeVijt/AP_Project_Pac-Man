#include "GhostView.h"

#include <utility>
#include "EntityView.h"
#include "../model/Ghost.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"
#include "Camera.h"
GhostView::GhostView(shared_ptr <Ghost> ghost) : ghost(std::move(ghost)) {}

void GhostView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        const int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(ghost->getPosition());

        // animate ghost by choosing a different variant dependent on the position
        constexpr int variants[] = {0, 1};
        const int variant = variants[((posX + posY) * 2 / gridSize) % 2];

        if (ghost->isFearMode()) {
            window->draw(spriteFactory.createGhost(GhostType::Fear, variant, posX, posY, gridSize));
        } else {
            window->draw(spriteFactory.createGhost(ghost->getType(), variant, posX, posY, gridSize));
        }
    }
}
