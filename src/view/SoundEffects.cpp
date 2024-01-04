#include "SoundEffects.h"

SoundEffects::SoundEffects() {
    if (!bufferOpeningSong.loadFromFile("resources/sounds/Pacman_Dies.wav") ||
        !bufferEatingCherry.loadFromFile("resources/sounds/Pacman_Eating_Cherry.wav") ||
        !bufferEatingGhost.loadFromFile("resources/sounds/Pacman_Eating_Ghost.wav") ||
        !bufferExtraLife.loadFromFile("resources/sounds/Pacman_Extra_Live.wav") ||
        !bufferIntermission.loadFromFile("resources/sounds/Pacman_Intermission.wav") ||
        !bufferOpeningSong.loadFromFile("resources/sounds/Pacman_Opening_Song.wav") ||
        !bufferSiren.loadFromFile("resources/sounds/Pacman_Siren.wav") ||
        !bufferWakaWaka.loadFromFile("resources/sounds/Pacman_Waka_Waka.wav") ||
        !bufferGameOver.loadFromFile("resources/sounds/Pacman_Game_Over.wav") ||
        !bufferVictory.loadFromFile("resources/sounds/Pacman_Victory.wav") ) {
        throw std::runtime_error("Failed to load sounds file");
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
void SoundEffects::playVictory() { play(bufferVictory); }
void SoundEffects::playGameOver() { play(bufferGameOver); }

void SoundEffects::play(const sf::SoundBuffer& buffer) {
    sound.setBuffer(buffer);
    // TODO reenable
    sound.play();
}

void SoundEffects::stop() {
    sound.stop();
}
