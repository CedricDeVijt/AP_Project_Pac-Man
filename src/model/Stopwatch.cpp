#include "Stopwatch.h"

#include <iostream>

Stopwatch& Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}

void Stopwatch::start() {
    running = true;
    tick();
    tick();
}

void Stopwatch::restart() {
    previousTime = std::chrono::high_resolution_clock::now();
    pauseDuration = std::chrono::microseconds(0);
    running = true;
}

double Stopwatch::getDeltaTime() const {
    if (running) {
        return deltaTime.count();
    } else {
        return 0.0;
    }
}

void Stopwatch::tick() {
    if (running) {
        previousTime = tickTime;
        tickTime = std::chrono::high_resolution_clock::now();
        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(tickTime - previousTime);
    } else {
        throw std::runtime_error("Clock was stopped");
    }
}

void Stopwatch::pause() {
    if (running) {
        pauseTime = std::chrono::high_resolution_clock::now();
        running = false;
    } else {
        throw std::runtime_error("Clock was not running");
    }
}

void Stopwatch::unPause() {
    if (!running) {
        running = true;
        tick();
    } else {
        throw std::runtime_error("Clock was not paused");
    }
}
