#ifndef AP_PROJECT_PAC_MAN_SCORE_H
#define AP_PROJECT_PAC_MAN_SCORE_H

#include <vector>
#include <string>
#include "Observer.h"

class Score : public Observer {
public:
    static void saveScore(std::string name, int score);
    static std::vector<std::pair<std::string, int>> loadHighScores();
    void pacManEatsCookie();
    void pacManCapturesGhost();
    void update() override ;

    int getCurrentScore() const;

private:
    int currentScore = 0;

};


#endif //AP_PROJECT_PAC_MAN_SCORE_H
