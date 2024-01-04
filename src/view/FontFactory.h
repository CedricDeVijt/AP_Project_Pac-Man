#ifndef AP_PROJECT_PAC_MAN_FontFactory_H
#define AP_PROJECT_PAC_MAN_FontFactory_H

#include <SFML/Graphics.hpp>

/**
 * @class FontFactory
 * @brief Handles the loading and creation of fonts.
 */
class FontFactory {
private:
    // Private constructor to prevent external instantiation
    FontFactory();
    ~FontFactory() = default;
    sf::Font pixelFont, pacManFont;


public:
    // Static method to get the instance of the singleton
    static FontFactory& getInstance();

    sf::Font getPixelFont();
    sf::Font getPacManFont();

    // Prevent copying and assignment
    FontFactory(const FontFactory&) = delete;
    FontFactory& operator=(const FontFactory&) = delete;
};

#endif // AP_PROJECT_PAC_MAN_FontFactory_H
