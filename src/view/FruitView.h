
#ifndef GAMELOGICLIB_FRUITVIEW_H
#define GAMELOGICLIB_FRUITVIEW_H
#include "EntityView.h"
#include "Collectable.h"
#include "Window.h"



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
    explicit FruitView(shared_ptr <Fruit> fruit);

    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;

private:
    shared_ptr <Fruit> fruit;
};


#endif //GAMELOGICLIB_FRUITVIEW_H
