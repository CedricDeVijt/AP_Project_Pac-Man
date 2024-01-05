
#ifndef GAMELOGICLIB_SOUNDEFFECTOBSERVER_H
#define GAMELOGICLIB_SOUNDEFFECTOBSERVER_H

#include "../model/Observer.h"

/**
 * @class SoundEffectObserver
 * @brief An observer class responsible for playing sound effects based on game events.
 */
class SoundEffectObserver : public Observer {
public:
    /**
     * @brief Processes the event and triggers the corresponding sound effect.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;
};


#endif //GAMELOGICLIB_SOUNDEFFECTOBSERVER_H
