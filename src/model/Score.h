#ifndef AP_PROJECT_PAC_MAN_SCORE_H
#define AP_PROJECT_PAC_MAN_SCORE_H

#include "Observer.h"
#include <string>
#include <vector>

class Score : public Observer {
public:
    static void saveScore(std::string name, int score);
    static std::vector<std::pair<std::string, int>> loadHighScores();
    void pacManCapturesCoin();
    void pacManCapturesGhost();
    void pacManCapturedByGhost();

    void update() override;

    int getCurrentScore() const;
    int getLivesRemaining() const;

private:
    int currentScore = 0;
    int livesRemaining = 3;
};

#endif // AP_PROJECT_PAC_MAN_SCORE_H
