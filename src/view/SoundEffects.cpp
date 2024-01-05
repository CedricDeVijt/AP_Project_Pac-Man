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
        !bufferVictory.loadFromFile("resources/sounds/Pacman_Victory.wav") ||
        !bufferToyBoxWorld.loadFromFile("resources/sounds/Pacman_Toy_Box_World.wav")) {
        throw std::runtime_error("Failed to load sounds file");
    }
}

void SoundEffects::playEatingCherry() { playForeground(bufferEatingCherry); }
void SoundEffects::playEatingGhost() { playForeground(bufferEatingGhost); }
void SoundEffects::playExtraLife() { playForeground(bufferExtraLife); }
void SoundEffects::playIntermission() { playBackground(bufferIntermission); }
void SoundEffects::playOpeningSong() { playBackground(bufferOpeningSong); }
void SoundEffects::playSiren() { playForeground(bufferSiren); }
void SoundEffects::playWakaWaka() { playForeground(bufferWakaWaka); }
void SoundEffects::playVictory() { playForeground(bufferVictory); }
void SoundEffects::playGameOver() { playBackground(bufferGameOver); }
void SoundEffects::playToyBoxWorld() { playBackground(bufferToyBoxWorld); }

void SoundEffects::playBackground(const sf::SoundBuffer& buffer) {
    backgroundSound.setBuffer(buffer);
    backgroundSound.play();
}

void SoundEffects::playForeground(const sf::SoundBuffer& buffer) {
    foregroundSound.setBuffer(buffer);
    foregroundSound.play();
}

void SoundEffects::stop() { backgroundSound.stop(); }

void SoundEffects::pause() { backgroundSound.pause(); }

void SoundEffects::unpause() { backgroundSound.play(); }
