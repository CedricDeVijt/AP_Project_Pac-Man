#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "Score.h"
#include "Stopwatch.h"

void Score::saveScore(const std::string& name, int score) {
    auto scores = loadHighScores();
    scores.emplace_back(name, score);

    // sort the scores
    std::sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
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
        for (const auto& scorePair : scores) {
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

void Score::processEvent(EventType eventType) {
    switch (eventType) {
    case TICK:
        // in each update cycle this method will be called 5 times (for packman and each of the ghosts), therfore
        // we need to divide by 5
        timeToReduceScore -= Stopwatch::getInstance().getDeltaTime() / 5;
        if (timeToReduceScore < 0) {
            timeToReduceScore = 2 * Stopwatch::SECOND;
            currentScore += POINTS_TICK;
            if (currentScore < 0) {
                currentScore = 0;
            }
        }
        break;
    case PACMAN_CAPTURES_COIN:
        currentScore += POINTS_COIN;
        break;
    case PACMAN_CAPTURES_FRUIT:
        currentScore += POINTS_FRUIT;
        break;
    case PACMAN_CAPTURES_GHOST:
        currentScore += POINTS_GHOST;
        break;
    case PACMAN_DIES:
        livesRemaining -= 1;
        break;
    default:
        break;
    }
}

int Score::getCurrentScore() const { return currentScore; }

int Score::getLivesRemaining() const { return livesRemaining; }
