#ifndef AP_PROJECT_PAC_MAN_SOUNDEFFECTS_H
#define AP_PROJECT_PAC_MAN_SOUNDEFFECTS_H
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>
#include <memory>

using std::shared_ptr;

/**
 * @class SoundEffects
 * @brief Handles playing sound effects in the game.
 */
class SoundEffects {
private:
    // Private constructor to prevent external instantiation
    SoundEffects();
    std::map<std::string, shared_ptr<sf::SoundBuffer>> soundMap;
    sf::Sound sound;
    sf::SoundBuffer bufferEatingCherry, bufferEatingGhost, bufferExtraLife, bufferIntermission, bufferOpeningSong,
        bufferSiren, bufferWakaWaka;

public:
    // Static method to get the instance of the singleton
    static SoundEffects& getInstance();

    /**
     * @brief Plays the sound effect for eating a cherry.
     */
    void playEatingCherry();

    /**
     * @brief Plays the sound effect for eating a ghost.
     */
    void playEatingGhost();

    /**
     * @brief Plays the sound effect for earning an extra life.
     */
    void playExtraLife();

    /**
     * @brief Plays the sound effect for an intermission (between levels).
     */
    void playIntermission();

    /**
     * @brief Plays the opening song sound effect.
     */
    void playOpeningSong();

    /**
     * @brief Plays the siren sound effect.
     */
    void playSiren();

    /**
     * @brief Plays the "Waka Waka" sound effect.
     */
    void playWakaWaka();

    /**
     * @brief Plays a given sound buffer.
     * @param buffer The sound buffer to be played.
     */
    void play(const sf::SoundBuffer& buffer);

    // Prevent copying and assignment
    SoundEffects(const SoundEffects&) = delete;
    SoundEffects& operator=(const SoundEffects&) = delete;
};

#endif // AP_PROJECT_PAC_MAN_SOUNDEFFECTS_H
