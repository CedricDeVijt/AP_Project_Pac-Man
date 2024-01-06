#include "Random.h"

Random::Random() : mt(std::random_device{}()){};

Random& Random::getInstance() {
    static Random instance;
    return instance;
}

int Random::getRandomNumber(int max) {
    std::uniform_int_distribution<int> distribution(0, max);
    return distribution(mt);
}