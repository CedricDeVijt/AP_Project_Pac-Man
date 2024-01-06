
#ifndef GAMELOGICLIB_SOUNDEFFECTOBSERVER_H
#define GAMELOGICLIB_SOUNDEFFECTOBSERVER_H

#include "Observer.h"

/**
 * @brief Observer class for handling sound effects events.
 *
 * This class is responsible for processing specific game events related to sound effects,
 * triggering the appropriate sound effect based on the event type.
 */
class SoundEffectObserver : public Observer {
public:
    /**
     * @brief Processes the event and triggers the corresponding sound effect.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;
};

#endif // GAMELOGICLIB_SOUNDEFFECTOBSERVER_H
