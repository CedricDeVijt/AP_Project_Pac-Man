#include "Random.h"
#include <iostream>

// Define the static instance of the singleton
Random::Random() {
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 generator(rd()); // Standard mersenne_twister_engine seeded with rd()
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