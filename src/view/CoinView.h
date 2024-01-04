
#ifndef GAMELOGICLIB_COINVIEW_H
#define GAMELOGICLIB_COINVIEW_H
#include "EntityView.h"
#include "../model/Ghost.h"
#include "../model/Collectable.h"
#include "../model/Ghost.h"
#include "../model/PacMan.h"
#include "../model/Wall.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"



/**
 * @class CoinView
 * @brief Visual representation of the Coin entity.
 */
class CoinView : public EntityView {
public:
    /**
     * @brief Constructs a CoinView object.
     * @param coin The Coin entity to be visualized.
     */
    CoinView(shared_ptr <Coin> coin);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr <Coin> coin;
};



#endif //GAMELOGICLIB_COINVIEW_H
