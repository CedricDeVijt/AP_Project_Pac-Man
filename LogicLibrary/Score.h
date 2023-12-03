#ifndef AP_PROJECT_PAC_MAN_SCORE_H
#define AP_PROJECT_PAC_MAN_SCORE_H

#include <vector>
#include "Observer.h"

class Score : public Observer {
    std::vector<std::pair<std::string, int>> highScores;
    int currentScore;
};


#endif //AP_PROJECT_PAC_MAN_SCORE_H
