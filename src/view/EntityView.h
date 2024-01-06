#ifndef AP_PROJECT_PAC_MAN_ENTITYVIEW_H
#define AP_PROJECT_PAC_MAN_ENTITYVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "../util/Singleton.h"
#include "SpriteFactory.h"
#include "Window.h"

using std::shared_ptr;

/**
 * @class EntityView
 * @brief Base class for visual representation of entities in the game.
 */
class EntityView : public Observer {
protected:
    shared_ptr<sf::RenderWindow> window = Singleton<Window>::getInstance().getWindow();
    SpriteFactory& spriteFactory = Singleton<SpriteFactory>::getInstance();

    /**
     * @brief Gets the grid size based on the window size.
     * @return The size of a grid cell.
     */
    int getGridSize() const;

    // TODO
    const int gridSize = window->getSize().x / 20;
};

#endif // AP_PROJECT_PAC_MAN_ENTITYVIEW_H
