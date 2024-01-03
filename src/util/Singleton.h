#ifndef GAMELOGICLIB_SINGLETON_H
#define GAMELOGICLIB_SINGLETON_H

#include <iostream>

template <typename T>
class Singleton {
public:
    // get the static instance
    static T& getInstance() {
        static T instance; // The instance is created only once
        return instance;
    };

private:
    Singleton() {}                                   // Private constructor to prevent external instantiation
    ~Singleton() {}                                  // Optional: Destructor to ensure proper cleanup
    Singleton(const Singleton&) = delete;            // Disable copy constructor
    Singleton& operator=(const Singleton&) = delete; // Disable copy assignment
};

#endif // GAMELOGICLIB_SINGLETON_H
