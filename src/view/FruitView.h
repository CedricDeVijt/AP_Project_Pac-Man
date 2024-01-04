
#ifndef GAMELOGICLIB_FRUITVIEW_H
#define GAMELOGICLIB_FRUITVIEW_H
#include "EntityView.h"
#include "../model/Ghost.h"
#include "../model/Collectable.h"
#include "../model/Ghost.h"
#include "../model/PacMan.h"
#include "../model/Wall.h"
#include "SpriteFactory.h"
#include "WindowSingleton.h"



/**
 * @class FruitView
 * @brief Visual representation of the Fruit entity.
 */
class FruitView : public EntityView {
public:
    /**
     * @brief Constructs a FruitView object.
     * @param fruit The Fruit entity to be visualized.
     */
    FruitView(shared_ptr <Fruit> fruit);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr <Fruit> fruit;
};


#endif //GAMELOGICLIB_FRUITVIEW_H
