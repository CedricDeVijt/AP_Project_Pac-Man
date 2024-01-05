#ifndef AP_PROJECT_PAC_MAN_FontFactory_H
#define AP_PROJECT_PAC_MAN_FontFactory_H

#include <SFML/Graphics.hpp>

/**
 * @class FontFactory
 * @brief Handles the loading and creation of fonts.
 */
class FontFactory {
private:
    sf::Font pixelFont, pacManFont;

public:
    FontFactory();
    ~FontFactory() = default;

    sf::Font getPixelFont() const;
    sf::Font getPacManFont() const;

    // Prevent copying and assignment
    FontFactory(const FontFactory&) = delete;
    FontFactory& operator=(const FontFactory&) = delete;
};

#endif // AP_PROJECT_PAC_MAN_FontFactory_H
