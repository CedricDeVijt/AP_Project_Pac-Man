#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>


#include "Score.h"

void Score::saveHighScore(std::string name, int score, std::string fileName) {
    auto scores = getHighScores(fileName);
    scores.emplace_back(name, score);

    // sort the scores
    std::sort(scores.begin(), scores.end(), [](const auto&a, const auto&b) {
        return a.second > b.second; // Sort in descending order based on scores
    });

    // discard the lowest score
    scores.pop_back();

    // write the scores to the file
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

std::vector<std::pair<std::string, int>> Score::getHighScores(const std::string&fileName) {
    std::ifstream file(fileName);
    std::vector<std::pair<std::string, int>> highScores;

    if (file.is_open()) {
        std::string line;
        // Skip the header line
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name;
            int score;

            if (iss >> name >> score) {
                highScores.emplace_back(name, score);
            }
            else {
                // Handle parsing error if needed
                throw std::runtime_error("Error parsing high scores file");
            }
        }

        file.close();
    }
    else {
        // Handle file opening error if needed
        throw std::runtime_error("Error opening high scores file");
    }

    return highScores;
}
