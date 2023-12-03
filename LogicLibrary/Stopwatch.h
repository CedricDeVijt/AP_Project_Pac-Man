#ifndef AP_PROJECT_PAC_MAN_STOPWATCH_H
#define AP_PROJECT_PAC_MAN_STOPWATCH_H

#include <chrono>

class Stopwatch {
    Stopwatch();
    ~Stopwatch() = default;

    void start();
    void stop();
    void reset();

    double getDetalTime();

private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    TimePoint startTime;
    TimePoint previousTime;
    bool running;

};


#endif //AP_PROJECT_PAC_MAN_STOPWATCH_H
