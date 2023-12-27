#ifndef AP_PROJECT_PAC_MAN_SCORE_H
#define AP_PROJECT_PAC_MAN_SCORE_H

#include <vector>
#include <string>
#include "Observer.h"

class Score : public Observer {
    int currentScore;

public:
    static void saveScore(std::string name, int score);

    static std::vector<std::pair<std::string, int>> loadHighScores();
};


#endif //AP_PROJECT_PAC_MAN_SCORE_H
