#ifndef AP_PROJECT_PAC_MAN_STOPWATCH_H
#define AP_PROJECT_PAC_MAN_STOPWATCH_H

#include <chrono>

class Stopwatch {
private:
    // Private constructor to prevent external instantiation
    Stopwatch();

public:
    // Static method to get the instance of the singleton
    static Stopwatch& getInstance();

    // Prevent copying and assignment
    Stopwatch(const Stopwatch&) = delete;
    Stopwatch& operator=(const Stopwatch&) = delete;

    void start();
//    void stop();
    void restart();
    void tick();
    void pause();
    void unPause();

    double getDeltaTime();

private:
    std::chrono::high_resolution_clock::time_point previousTime, tickTime, startTime, pauseTime;
    std::chrono::microseconds deltaTime, pauseDuration;
    bool running = false;
};


#endif //AP_PROJECT_PAC_MAN_STOPWATCH_H
