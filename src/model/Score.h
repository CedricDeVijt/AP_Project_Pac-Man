#ifndef AP_PROJECT_PAC_MAN_SCORE_H
#define AP_PROJECT_PAC_MAN_SCORE_H

#include <vector>
#include <string>
#include "Observer.h"

class Score : public Observer {
    // std::vector<std::pair<std::string, int>> highScores;
    int currentScore;

public:
    void saveHighScore(std::string name, int score, std::string fileName);

    std::vector<std::pair<std::string, int>> getHighScores(const std::string &fileName);
};


#endif //AP_PROJECT_PAC_MAN_SCORE_H
