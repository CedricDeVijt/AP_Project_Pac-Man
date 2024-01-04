#include "Random.h"
#include <iostream>

Random::Random() {
    std::random_device rd;
    std::mt19937 generator(rd());
}

Random& Random::getInstance() {
    static Random instance;
    return instance;
}

int Random::getRandomNumber(int max) {
    std::uniform_int_distribution<int> distribution(0, max);
    return distribution(generator);
}