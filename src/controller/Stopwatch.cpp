#include "Stopwatch.h"

// Define the static instance of the singleton
Stopwatch::Stopwatch() : running(false) {
    // Constructor code, if needed
}

Stopwatch& Stopwatch::getInstance() {
    static Stopwatch instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}

void Stopwatch::start() {
    if (!running) {
        running = true;
        startTime = Clock::now();
        previousTime = startTime;
    }
}

void Stopwatch::stop() {
    if (running) {
        previousTime = Clock::now();
        running = false;
    }
}

void Stopwatch::reset() {
    startTime = Clock::now();
    previousTime = startTime;
}

double Stopwatch::getDeltaTime() {
    if (running) {
        auto currentTime = Clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - previousTime);
        previousTime = currentTime;
        return deltaTime.count();
    } else {
        return 0.0;
    }
}
