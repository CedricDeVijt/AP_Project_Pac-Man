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
    //    if (!running) {
    running = true;
    tick();
    tick();
    //    } else {
    //        throw std::runtime_error("Clock is already running");
    //    }
}

// void Stopwatch::stop() {
//     if (running) {
//         running = false;
//     } else {
//         std::cerr << "Clock is already stopped.\n";
//     }
// }
//
void Stopwatch::restart() {
    previousTime = std::chrono::high_resolution_clock::now();
    pauseDuration = std::chrono::microseconds(0);
    running = true;
}
//
// double Stopwatch::getGameTime() {
//    if (running) {
//        const std::chrono::high_resolution_clock::time_point &now = std::chrono::high_resolution_clock::now();
//        deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - startTime);
//        return deltaTime.count();
//    } else {
//        return 0.0;
//    }
//}
//
//

double Stopwatch::getDeltaTime() {
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
    std::cout << "Pause\n";
    if (running) {
        pauseTime = std::chrono::high_resolution_clock::now();
        running = false;
    } else {
        throw std::runtime_error("Clock was not running");
    }
}

void Stopwatch::unPause() {
    std::cout << "unPause\n";
    if (!running) {
        //        const std::chrono::high_resolution_clock::time_point &now = std::chrono::high_resolution_clock::now();
        //        pauseDuration += std::chrono::duration_cast<std::chrono::microseconds>(now - pauseTime));
        running = true;
        tick();
    } else {
        throw std::runtime_error("Clock was not paused");
    }
}
