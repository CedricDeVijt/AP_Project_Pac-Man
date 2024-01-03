
#ifndef GAMELOGICLIB_SOUNDEFFECTOBSERVER_H
#define GAMELOGICLIB_SOUNDEFFECTOBSERVER_H

#include "../model/Observer.h"

class SoundEffectObserver : public Observer {
public:
    /**
     * @brief processes the event.
     * @param eventType The type of event that occurred.
     */
    void processEvent(EventType eventType) override;
};


#endif //GAMELOGICLIB_SOUNDEFFECTOBSERVER_H
