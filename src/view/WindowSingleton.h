#ifndef AP_PROJECT_PAC_MAN_WINDOWSINGLETON_H
#define AP_PROJECT_PAC_MAN_WINDOWSINGLETON_H
#include <SFML/Graphics.hpp>
#include <memory>

using std::shared_ptr;

/**
 * @class WindowSingleton
 * @brief A singleton class managing the application's SFML window.
 */
class WindowSingleton {
private:
    // Private constructor to prevent external instantiation
    WindowSingleton();
    shared_ptr<sf::RenderWindow> window; ///< The SFML window instance.

public:
    /**
     * @brief Retrieves the instance of the WindowSingleton.
     * @return The instance of the WindowSingleton.
     */
    static WindowSingleton& getInstance();

    /**
     * @brief Gets the SFML window instance.
     * @return A shared pointer to the SFML window.
     */
    shared_ptr<sf::RenderWindow> getWindow();

    // Prevent copying and assignment
    WindowSingleton(const WindowSingleton&) = delete;
    WindowSingleton& operator=(const WindowSingleton&) = delete;
};

#endif // AP_PROJECT_PAC_MAN_WINDOWSINGLETON_H
