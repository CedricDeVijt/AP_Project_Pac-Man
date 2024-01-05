
#ifndef GAMELOGICLIB_GHOSTVIEW_H
#define GAMELOGICLIB_GHOSTVIEW_H
#include "EntityView.h"
#include "Ghost.h"

/**
 * @class GhostView
 * @brief Visual representation of the Ghost entity.
 */
class GhostView final : public EntityView {
public:
    /**
     * @brief Constructs a GhostView object.
     * @param ghost The Ghost entity to be visualized.
     */
    explicit GhostView(shared_ptr <Ghost> ghost);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr <Ghost> ghost;
};


#endif //GAMELOGICLIB_GHOSTVIEW_H
