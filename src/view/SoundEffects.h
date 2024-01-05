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
    std::map<std::string, shared_ptr<sf::SoundBuffer>> soundMap;
    sf::Sound foregroundSound, backgroundSound;
    sf::SoundBuffer bufferEatingCherry, bufferEatingGhost, bufferExtraLife, bufferIntermission, bufferOpeningSong,
        bufferSiren, bufferWakaWaka, bufferGameOver, bufferVictory, bufferToyBoxWorld;
public:
    SoundEffects();

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
     * @brief Plays the victory sound effect.
     */
    void playVictory();

    /**
     * @brief Plays the game over sound effect.
     */
    void playGameOver();

    /**
     * @brief Plays the background sound effect ToyBoxWorld.
     */
    void playToyBoxWorld();

    /**
     * @brief Plays a given sound buffer in the foreground.
     * @param buffer The sound buffer to be played.
     */
    void playForeground(const sf::SoundBuffer& buffer);

    /**
     * @brief Plays a given sound buffer in the background.
     * @param buffer The sound buffer to be played.
     */
    void playBackground(const sf::SoundBuffer& buffer);

    /**
     * @brief Stop any sound that is playing.
     */
    void stop();

    /**
     * @brief pause any sound that is playing.
     */
    void pause();

    /**
     * @brief unpause any sound that was paused.
     */
    void unpause();
};

#endif // AP_PROJECT_PAC_MAN_SOUNDEFFECTS_H
