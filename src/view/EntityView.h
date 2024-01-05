#ifndef AP_PROJECT_PAC_MAN_ENTITYVIEW_H
#define AP_PROJECT_PAC_MAN_ENTITYVIEW_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "SpriteFactory.h"
#include "Window.h"
#include "../util/Singleton.h"

using std::shared_ptr;

/**
 * @class EntityView
 * @brief Base class for visual representation of entities in the game.
 */
class EntityView : public Observer {
protected:
    shared_ptr <sf::RenderWindow> window = Singleton<Window>::getInstance().getWindow();
    SpriteFactory &spriteFactory = Singleton<SpriteFactory>::getInstance();

    /**
     * @brief Gets the grid size based on the window size.
     * @return The size of a grid cell.
     */
    int getGridSize() const;
};



#endif // AP_PROJECT_PAC_MAN_ENTITYVIEW_H
