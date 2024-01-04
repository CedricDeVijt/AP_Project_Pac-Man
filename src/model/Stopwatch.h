#ifndef AP_PROJECT_PAC_MAN_STOPWATCH_H
#define AP_PROJECT_PAC_MAN_STOPWATCH_H

#include <chrono>


/**
 * @class Stopwatch
 * @brief A singleton class for measuring time and calculating delta time.
 */
class Stopwatch {
private:
    /**
     * @brief Private constructor to prevent external instantiation.
     */
    Stopwatch();

public:
    /**
     * @brief Static method to get the instance of the singleton.
     * @return The instance of the Stopwatch.
     */
    static Stopwatch& getInstance();

    /**
     * @brief Starts the stopwatch.
     */
    void start();

    /**
     * @brief Restarts the stopwatch.
     */
    void restart();

    /**
     * @brief Moves the tick time forward to the current time.
     */
    void tick();

    /**
     * @brief Pauses the stopwatch.
     */
    void pause();

    /**
     * @brief Resumes the stopwatch from a paused state.
     */
    void unPause();

    /**
     * @brief Gets the time elapsed between the last two ticks in microseconds.
     * @return The delta time in microseconds.
     */
    double getDeltaTime() const;

    // Prevent copying and assignment
    Stopwatch(const Stopwatch&) = delete;
    Stopwatch& operator=(const Stopwatch&) = delete;

    static constexpr int SECOND = 1000000;

private:
    std::chrono::high_resolution_clock::time_point previousTime, tickTime, startTime, pauseTime;
    std::chrono::microseconds deltaTime{}, pauseDuration{};
    bool running = false;
};

#endif // AP_PROJECT_PAC_MAN_STOPWATCH_H
