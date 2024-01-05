
#ifndef GAMELOGICLIB_COINVIEW_H
#define GAMELOGICLIB_COINVIEW_H
#include "../util/Singleton.h"
#include "Collectable.h"
#include "EntityView.h"
#include "SpriteFactory.h"
#include "Window.h"

/**
 * @class CoinView
 * @brief Visual representation of the Coin entity.
 */
class CoinView final : public EntityView {
public:
    /**
     * @brief Constructs a CoinView object.
     * @param coin The Coin entity to be visualized.
     */
    explicit CoinView(shared_ptr<Coin> coin);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr<Coin> coin;
};

#endif // GAMELOGICLIB_COINVIEW_H
