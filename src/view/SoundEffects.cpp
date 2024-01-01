#include "SoundEffects.h"

SoundEffects::SoundEffects() {
    if (!bufferOpeningSong.loadFromFile("resources/sound/Pacman_Dies.wav") ||
        !bufferEatingCherry.loadFromFile("resources/sound/Pacman_Eating_Cherry.wav") ||
        !bufferEatingGhost.loadFromFile("resources/sound/Pacman_Eating_Ghost.wav") ||
        !bufferExtraLife.loadFromFile("resources/sound/Pacman_Extra_Live.wav") ||
        !bufferIntermission.loadFromFile("resources/sound/Pacman_Intermission.wav") ||
        !bufferOpeningSong.loadFromFile("resources/sound/Pacman_Opening_Song.wav") ||
        !bufferSiren.loadFromFile("resources/sound/Pacman_Siren.wav") ||
        !bufferWakaWaka.loadFromFile("resources/sound/Pacman_Waka_Waka.wav")) {
        throw std::runtime_error("Failed to load sound file");
    }
}

SoundEffects& SoundEffects::getInstance() {
    static SoundEffects instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}

void SoundEffects::playEatingCherry() { play(bufferEatingCherry); }
void SoundEffects::playEatingGhost() { play(bufferEatingGhost); }
void SoundEffects::playExtraLife() { play(bufferExtraLife); }
void SoundEffects::playIntermission() { play(bufferIntermission); }

void SoundEffects::playOpeningSong() { play(bufferOpeningSong); }
void SoundEffects::playSiren() { play(bufferSiren); }
void SoundEffects::playWakaWaka() { play(bufferWakaWaka); }

void SoundEffects::play(const sf::SoundBuffer& buffer) {
    sound.setBuffer(buffer);
    // TODO enable
    sound.play();
}
