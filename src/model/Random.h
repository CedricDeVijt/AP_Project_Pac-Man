#ifndef AP_PROJECT_PAC_MAN_RANDOM_H
#define AP_PROJECT_PAC_MAN_RANDOM_H

#include <random>

/**
 * @class Random
 * @brief Singleton class for generating random numbers.
 */
class Random {
private:
    /**
     * @brief Private constructor to prevent external instantiation.
     */
    Random();

public:
    /**
     * @brief Static method to get the instance of the singleton.
     * @return The instance of the Random singleton.
     */
    static Random& getInstance();

    /**
     * @brief Generates a random number in the range [0, max].
     * @param max The maximum value for the random number.
     * @return A random number in the specified range.
     */
    int getRandomNumber(int max);

    // Prevent copying and assignment
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;

private:
    std::default_random_engine generator; ///< Random number generator engine.
};

#endif // AP_PROJECT_PAC_MAN_RANDOM_H
