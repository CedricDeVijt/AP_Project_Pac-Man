#ifndef AP_PROJECT_PAC_MAN_SOUNDEFFECTS_H
#define AP_PROJECT_PAC_MAN_SOUNDEFFECTS_H
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>
#include <memory>

using std::shared_ptr;


class SoundEffects {
private:
    // Private constructor to prevent external instantiation
    SoundEffects();
    std::map<std::string, shared_ptr<sf::SoundBuffer>> soundMap;
    sf::Sound sound;
    sf::SoundBuffer bufferEatingCherry, bufferEatingGhost, bufferExtraLife, bufferIntermission, bufferOpeningSong, bufferSiren, bufferWakaWaka;


public:
    // Static method to get the instance of the singleton
    static SoundEffects& getInstance();
    void playEatingCherry();
    void playEatingGhost();
    void playExtraLife();
    void playIntermission();
    void playOpeningSong();
    void playSiren();
    void playWakaWaka();

    // Prevent copying and assignment
    SoundEffects(const SoundEffects&) = delete;
    SoundEffects& operator=(const SoundEffects&) = delete;

    void play(const sf::SoundBuffer &buffer);
};

#endif //AP_PROJECT_PAC_MAN_SOUNDEFFECTS_H
