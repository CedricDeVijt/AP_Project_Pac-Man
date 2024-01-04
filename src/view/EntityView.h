#ifndef AP_PROJECT_PAC_MAN_ENTITYVIEW_H
#define AP_PROJECT_PAC_MAN_ENTITYVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "../model/Collectable.h"
#include "../model/Ghost.h"
#include "../model/PacMan.h"
#include "../model/Wall.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"

using std::shared_ptr;

/**
 * @class EntityView
 * @brief Base class for visual representation of entities in the game.
 */
class EntityView : public Observer {
protected:
    shared_ptr <sf::RenderWindow> window = WindowSingleton::getInstance().getWindow();
    SpriteFactory &spriteFactory = SpriteFactory::getInstance();

    /**
     * @brief Gets the grid size based on the window size.
     * @return The size of a grid cell.
     */
    int getGridSize() const;
};



#endif // AP_PROJECT_PAC_MAN_ENTITYVIEW_H
