#ifndef AP_PROJECT_PAC_MAN_WINDOWSINGLETON_H
#define AP_PROJECT_PAC_MAN_WINDOWSINGLETON_H
#include <memory>
#include <SFML/Graphics.hpp>

using std::shared_ptr;

class WindowSingleton {
private:
    // Private constructor to prevent external instantiation
    WindowSingleton();
    shared_ptr<sf::RenderWindow> window;

public:
    // Static method to get the instance of the singleton
    static WindowSingleton& getInstance();

    shared_ptr<sf::RenderWindow> getWindow();

    // Prevent copying and assignment
    WindowSingleton(const WindowSingleton&) = delete;
    WindowSingleton& operator=(const WindowSingleton&) = delete;
};

#endif //AP_PROJECT_PAC_MAN_WINDOWSINGLETON_H
