#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>


#include "Score.h"
void Score::saveScore(std::string name, int score) {
    auto scores = loadHighScores();
    scores.emplace_back(name, score);

    // sort the scores
    std::sort(scores.begin(), scores.end(), [](const auto &a, const auto &b) {
        return a.second > b.second; // Sort in descending order based on scores
    });

    // discard the lowest score
    if (scores.size() >= 5) {
        scores.pop_back();
    }

    // write the scores to the file
    const std::string fileName = "data/high_scores.csv";
    std::ofstream file(fileName, std::ios::trunc);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening high scores file");
    } else {
        file << "Name, Score\n";
        for (const auto &scorePair: scores) {
            file << scorePair.first << ", " << scorePair.second << "\n";
        }
        file.close();
    }
}

std::vector<std::pair<std::string, int>> Score::loadHighScores() {
    const std::string fileName = "data/high_scores.csv";
    std::ifstream file(fileName);
    std::vector<std::pair<std::string, int>> highScores;

    if (file.is_open()) {
        std::string line;
        // Skip the header line
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name;
            std::string score;

            std::getline(iss, name, ',');
            std::getline(iss, score, ',');
            highScores.emplace_back(name, std::stoi(score));
        }

        file.close();
    } else {
        // Handle file opening error if needed
        throw std::runtime_error("Error opening high scores file");
    }

    return highScores;
}

void Score::pacManCapturesCoin(){
    currentScore +=1;
}

void Score::pacManCapturesGhost() {
    currentScore +=50;
}

void Score::pacManCapturedByGhost() {
    livesRemaining -=1;
}

void Score::update() {

}

int Score::getCurrentScore() const {
    return currentScore;
}

int Score::getLivesRemaining() const {
    return livesRemaining;
}


