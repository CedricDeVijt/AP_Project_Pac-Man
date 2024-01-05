#ifndef AP_PROJECT_PAC_MAN_Window_H
#define AP_PROJECT_PAC_MAN_Window_H
#include <SFML/Graphics.hpp>
#include <memory>

using std::shared_ptr;

/**
 * @class Window
 * @brief A singleton class managing the application's SFML window.
 */
class Window {
private:
    shared_ptr<sf::RenderWindow> window; ///< The SFML window instance.

public:
    Window();
    /**
     * @brief Gets the SFML window instance.
     * @return A shared pointer to the SFML window.
     */
    shared_ptr<sf::RenderWindow> getWindow();
};

#endif // AP_PROJECT_PAC_MAN_Window_H
