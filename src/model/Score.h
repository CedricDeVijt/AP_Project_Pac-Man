#ifndef AP_PROJECT_PAC_MAN_SCORE_H
#define AP_PROJECT_PAC_MAN_SCORE_H

#include "Observer.h"
#include <string>
#include <vector>

/**
 * @class Score
 * @brief Keeps track of the player's score and lives, and manages high scores.
 */
class Score final : public Observer {
public:
    /**
     * @brief Saves the player's score along with their name and updates the high scores.
     * @param name The player's name.
     * @param score The player's score.
     */
    static void saveScore(const std::string& name, int score);

    /**
     * @brief Loads the high scores from a file.
     * @return A vector of pairs containing player names and their corresponding scores.
     */
    static std::vector<std::pair<std::string, int>> loadHighScores();

    /**
     * @brief Overrides the update method from the Observer class.
     */
    void processEvent(EventType eventType) override;

    /**
     * @brief Gets the current score.
     * @return The current score.
     */
    int getCurrentScore() const;

    /**
     * @brief Gets the remaining lives.
     * @return The remaining lives.
     */
    int getLivesRemaining() const;

private:
    int currentScore = 0;   ///< The current score.
    int livesRemaining = 3; ///< The remaining lives.
    double timeToReduceScore = 0; ///< The remaining time until the score is reduced by one.

    static constexpr int POINTS_TICK  = -1;  ///< the number of points losts with each tick
    static constexpr int POINTS_COIN  = 1;   ///< the number of points scored when a coin is captured
    static constexpr int POINTS_FRUIT = 10;  ///< the number of points scored when a fruit is captured
    static constexpr int POINTS_GHOST = 50;  ///< the number of points scored when a ghost is captured
};

#endif // AP_PROJECT_PAC_MAN_SCORE_H
