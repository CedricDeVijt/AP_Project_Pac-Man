#include "SoundEffectObserver.h"
#include "SoundEffects.h"

void SoundEffectObserver::processEvent(EventType eventType) {
    switch (eventType) {
    case PACMAN_CAPTURES_COIN:
        SoundEffects::getInstance().playWakaWaka();
        break;
    case PACMAN_CAPTURES_FRUIT:
        SoundEffects::getInstance().playEatingCherry();
        break;
    case PACMAN_CAPTURES_GHOST:
        SoundEffects::getInstance().playEatingGhost();
        break;
    case PACMAN_DIES:
        SoundEffects::getInstance().playSiren();
        break;
    default:
        break;
    }
}