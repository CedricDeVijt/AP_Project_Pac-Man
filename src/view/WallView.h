
#ifndef GAMELOGICLIB_WALLVIEW_H
#define GAMELOGICLIB_WALLVIEW_H
#include "EntityView.h"
#include "../model/Ghost.h"
#include "../model/Collectable.h"
#include "../model/Ghost.h"
#include "../model/PacMan.h"
#include "../model/Wall.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"


/**
 * @class WallView
 * @brief Visual representation of the Wall entity.
 */
class WallView : public EntityView {
public:
    /**
     * @brief Constructs a WallView object.
     * @param wall The Wall entity to be visualized.
     */
    WallView(shared_ptr <Wall> wall);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr <Wall> wall;
};



#endif //GAMELOGICLIB_WALLVIEW_H
