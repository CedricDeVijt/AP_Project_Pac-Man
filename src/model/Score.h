#ifndef AP_PROJECT_PAC_MAN_SCORE_H
#define AP_PROJECT_PAC_MAN_SCORE_H

#include "Observer.h"
#include <string>
#include <vector>

/**
 * @class Score
 * @brief Keeps track of the player's score and lives, and manages high scores.
 */
class Score : public Observer {
public:
    /**
     * @brief Saves the player's score along with their name and updates the high scores.
     * @param name The player's name.
     * @param score The player's score.
     */
    static void saveScore(std::string name, int score);

    /**
     * @brief Loads the high scores from a file.
     * @return A vector of pairs containing player names and their corresponding scores.
     */
    static std::vector<std::pair<std::string, int>> loadHighScores();

    /**
     * @brief Increments the score when PacMan captures a coin.
     */
    void pacManCapturesCoin();

    /**
     * @brief Increments the score when PacMan captures a ghost.
     */
    void pacManCapturesGhost();

    /**
     * @brief Decrements the remaining lives when PacMan is captured by a ghost.
     */
    void pacManCapturedByGhost();

    /**
     * @brief Overrides the update method from the Observer class.
     */
    void update() override;

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
};

#endif // AP_PROJECT_PAC_MAN_SCORE_H
