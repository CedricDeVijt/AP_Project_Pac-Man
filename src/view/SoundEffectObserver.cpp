#include "SoundEffectObserver.h"
#include "../util/Singleton.h"
#include "SoundEffects.h"

void SoundEffectObserver::processEvent(const EventType eventType) {
    switch (eventType) {
    case PACMAN_CAPTURES_COIN:
        Singleton<SoundEffects>::getInstance().playWakaWaka();
        break;
    case PACMAN_CAPTURES_FRUIT:
        Singleton<SoundEffects>::getInstance().playEatingCherry();
        break;
    case PACMAN_CAPTURES_GHOST:
        Singleton<SoundEffects>::getInstance().playEatingGhost();
        break;
    case PACMAN_DIES:
        Singleton<SoundEffects>::getInstance().playSiren();
        break;
    default:
        break;
    }
}