#include "Random.h"
#include <iostream>

// Define the static instance of the singleton
Random::Random() {
    // Constructor code, if needed
}

Random& Random::getInstance() {
    static Random instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}

int Random::getRandomNumber() {
    // Generate a random number between 1 and 100
    std::uniform_int_distribution<int> distribution(1, 100);
    return distribution(generator);
}