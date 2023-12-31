#include "SpriteFactory.h"

// Define the static instance of the singleton
SpriteFactory::SpriteFactory() {
    // Load a texture (replace "your_image.png" with the actual filename)
    if (!texture.loadFromFile("resources/Sprites.png")) {
        throw std::runtime_error("Failed to load texture");
    }
}

SpriteFactory &SpriteFactory::getInstance() {
    static SpriteFactory instance; // Guaranteed to be destroyed, instantiated on first use
    return instance;
}

sf::Sprite
SpriteFactory::createSprite(sf::IntRect textureRect, const sf::Vector2f &position, const sf::Vector2f &scale) {
    // Create a sprite and set its texture and texture rectangle
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(textureRect);

    // Set the position of the sprite
    sprite.setPosition(position);
    // Set the scale of the sprite
    sprite.setScale(scale);

    return sprite;;
}


sf::Sprite
SpriteFactory::createGhost(GhostType type, const int alternative, const int posX, const int posY, const int gridSize) {
    const int offset_top_x = 1;
    const int offset_top_y = 4;
    const int offset_fear_y = 554;
    const int size = 35;
    const int separator = 15;

    int margin = 10;
    double scaleFactor = gridSize / static_cast<double>(size + margin);

    int x;
    switch (type) {
        case GhostType::Blinky:
            x = offset_top_x;
            break;
        case GhostType::Pinky:
        case GhostType::Fear:
            x = offset_top_x + size + separator;
            break;
        case GhostType::Inky:
            x = offset_top_x + 2 * (size + separator);
            break;
        case GhostType::Clyde:
            x = offset_top_x + 3 * (size + separator);
            break;
        default:
            break;
    };
    int y;
    switch (type) {
        case GhostType::Fear:
            y = offset_fear_y + alternative * (size + separator);
            break;
        default:
            y = offset_top_y + alternative * (size + separator);
            break;
    }
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX + margin / 2, posY + margin / 2),
                        sf::Vector2f(scaleFactor, scaleFactor));
}

sf::Sprite SpriteFactory::createPacMan(const int alternative, const int posX, const int posY, const int gridSize) {
    const int offset_top_x = 853;
    const int offset_top_y = 5;
    const int size = 33;
    const int separator = 17;

    int margin = 10;
    double scaleFactor = gridSize / static_cast<double>(size + margin);

    int x = offset_top_x;
    int y = offset_top_y + alternative * (size + separator);
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX + margin / 2, posY + margin / 2),
                        sf::Vector2f(scaleFactor, scaleFactor));
}


sf::Sprite SpriteFactory::createFruit(const int alternative, const int posX, const int posY, const int gridSize) {
    const int offset_top_x = 601;
    const int offset_top_y = 3;
    const int size = 36;
    const int separator = 14;
    int margin = 20;

    int x = offset_top_x;
    int y = offset_top_y + alternative * (size + separator);

    double scaleFactor = gridSize / static_cast<double>(size + margin);
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX + margin / 2, posY + margin / 2),
                        sf::Vector2f(scaleFactor, scaleFactor));
}

sf::Sprite SpriteFactory::createCoin(const int posX, const int posY, const int gridSize) {
    const int offset_top_x = 411;
    const int offset_top_y = 313;
    const int size = 16;
    int margin = 50;

    int x = offset_top_x;
    int y = offset_top_y;

    double scaleFactor = gridSize / static_cast<double>(size + margin);
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX + margin / 2, posY + margin / 2),
                        sf::Vector2f(scaleFactor, scaleFactor));
}
