#ifndef GAMELOGICLIB_PACMANVIEW_H
#define GAMELOGICLIB_PACMANVIEW_H

#include "../model/Ghost.h"
#include "../model/PacMan.h"
#include "EntityView.h"
/**
 * @class PacManView
 * @brief Visual representation of the PacMan entity.
 */
class PacManView final : public EntityView {
public:
    /**
     * @brief Constructs a PacManView object.
     * @param pacMan The PacMan entity to be visualized.
     */
    explicit PacManView(shared_ptr <PacMan> pacMan);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr <PacMan> pacMan;
};

#endif //GAMELOGICLIB_PACMANVIEW_H
