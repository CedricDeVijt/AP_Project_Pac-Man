
#ifndef GAMELOGICLIB_GHOSTVIEW_H
#define GAMELOGICLIB_GHOSTVIEW_H
#include "EntityView.h"
#include "../model/Ghost.h"
#include "../model/Collectable.h"
#include "../model/Ghost.h"
#include "../model/PacMan.h"
#include "../model/Wall.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"

/**
 * @class GhostView
 * @brief Visual representation of the Ghost entity.
 */
class GhostView : public EntityView {
public:
    /**
     * @brief Constructs a GhostView object.
     * @param ghost The Ghost entity to be visualized.
     */
    GhostView(shared_ptr <Ghost> ghost);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr <Ghost> ghost;
};


#endif //GAMELOGICLIB_GHOSTVIEW_H
