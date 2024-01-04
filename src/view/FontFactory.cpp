#include "FontFactory.h"
#include "WindowSingleton.h"

// Define the static instance of the singleton
FontFactory::FontFactory() {
    if (!pixelFont.loadFromFile("resources/fonts/pixelFont.ttf")) {
        throw std::runtime_error("Error loading font");
    }
    if (!pacManFont.loadFromFile("resources/fonts/pacManFont.ttf")) {
        throw std::runtime_error("Error loading font");
    }
}

FontFactory& FontFactory::getInstance() {
    static FontFactory instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}

sf::Font FontFactory::getPixelFont() {
    return pixelFont;
}

sf::Font FontFactory::getPacManFont() {
    return pacManFont;
}

