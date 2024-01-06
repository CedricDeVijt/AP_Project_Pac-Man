#ifndef GAMELOGICLIB_SINGLETON_H
#define GAMELOGICLIB_SINGLETON_H

#include <iostream>

/**
 * @brief Generic Singleton template class.
 *
 * This template provides a mechanism to create a single instance of a class, ensuring
 * that the instance is created only once and providing a static method to access it.
 *
 * @tparam T The type of the class for which the singleton pattern is applied.
 */
template <typename T>
class Singleton {
public:
    /**
     * @brief Deleted copy constructor to prevent copying the singleton instance.
     */
    Singleton(const Singleton&) = delete; // Disable copy constructor

    /**
     * @brief Gets the static instance of the singleton.
     *
     * The instance is created only once when this method is first called.
     *
     * @return A reference to the singleton instance.
     */
    static T& getInstance() {
        static T instance;
        return instance;
    };

    /**
     * @brief Deleted copy assignment operator to prevent copying the singleton instance.
     */
    Singleton& operator=(const Singleton&) = delete;

private:
    /**
     * @brief Default constructor.
     *
     * Private constructor to prevent external instantiation.
     */
    Singleton() = default;

    /**
     * @brief Default destructor.
     *
     * Optional: Destructor to ensure proper cleanup.
     */
    ~Singleton() = default;
};

#endif // GAMELOGICLIB_SINGLETON_H
