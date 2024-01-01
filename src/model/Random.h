#ifndef AP_PROJECT_PAC_MAN_RANDOM_H
#define AP_PROJECT_PAC_MAN_RANDOM_H

#include <random>
class Random {
private:
    // Private constructor to prevent external instantiation
    Random();

public:
    // Static method to get the instance of the singleton
    static Random& getInstance();

    // Member function of the singleton
    int getRandomNumber(int max);

    // Prevent copying and assignment
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

private:
    // Random number generator
    // TODO mersenne
    std::default_random_engine generator;
};

#endif //AP_PROJECT_PAC_MAN_RANDOM_H
