
#ifndef GAMELOGICLIB_WALLVIEW_H
#define GAMELOGICLIB_WALLVIEW_H
#include "../util/Singleton.h"
#include "EntityView.h"
#include "SpriteFactory.h"
#include "Wall.h"
#include "Window.h"

/**
 * @class WallView
 * @brief Visual representation of the Wall entity.
 */
class WallView final : public EntityView {
public:
    /**
     * @brief Constructs a WallView object.
     * @param wall The Wall entity to be visualized.
     */
    explicit WallView(shared_ptr<Wall> wall);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr<Wall> wall;
};

#endif // GAMELOGICLIB_WALLVIEW_H
