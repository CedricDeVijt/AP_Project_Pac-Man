#include "FontFactory.h"
#include "../util/Singleton.h"

// Define the static instance of the singleton
FontFactory::FontFactory() {
    if (!pixelFont.loadFromFile("resources/fonts/pixelFont.ttf")) {
        throw std::runtime_error("Error loading font");
    }
    if (!pacManFont.loadFromFile("resources/fonts/pacManFont.ttf")) {
        throw std::runtime_error("Error loading font");
    }
}

sf::Font FontFactory::getPixelFont() const { return pixelFont; }

sf::Font FontFactory::getPacManFont() const { return pacManFont; }
