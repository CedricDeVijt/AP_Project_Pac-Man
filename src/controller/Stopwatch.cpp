#include "Stopwatch.h"

#include <iostream>


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
        previous_time = std::chrono::high_resolution_clock::now();
        running = true;
    } else {
        std::cerr << "Clock is already running.\n";
    }
}

void Stopwatch::stop() {
    if (running) {
        running = false;
    } else {
        std::cerr << "Clock is already stopped.\n";
    }
}

void Stopwatch::restart() {
    previous_time = std::chrono::high_resolution_clock::now();
    running = true;
}

double Stopwatch::getDeltaTime() {
    if (running) {
        auto current_time = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration<double>(current_time - previous_time);
        previous_time = current_time;
        return deltaTime.count();
    } else {
        return 0.0;
    }
}
