#include "GhostView.h"
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
GhostView::GhostView(shared_ptr <Ghost> ghost) : ghost(ghost) {}

void GhostView::processEvent(EventType eventType) {
    if (eventType == EventType::TICK) {
        int gridSize = getGridSize();
        int posX, posY;
        std::tie(posX, posY) = Camera::toPixelCoordinates(ghost->getPosition());

        // animate ghost by choosing a different variant dependent on the position
        int variants[] = {0, 1};
        int variant = variants[((posX + posY) * 2 / gridSize) % 2];

        if (ghost->isFearMode()) {
            window->draw(spriteFactory.createGhost(GhostType::Fear, variant, posX, posY, gridSize));
        } else {
            window->draw(spriteFactory.createGhost(ghost->getType(), variant, posX, posY, gridSize));
        }
    }
}
