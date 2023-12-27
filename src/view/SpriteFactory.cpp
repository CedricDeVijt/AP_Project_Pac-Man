#include "SpriteFactory.h"

SpriteFactory::SpriteFactory() {
    // Load a texture (replace "your_image.png" with the actual filename)
    if (!texture.loadFromFile("resources/Sprites.png")) {
        throw std::runtime_error("Failed to load texture");
    }
}

sf::Sprite SpriteFactory::createSprite(sf::IntRect textureRect, const sf::Vector2f &position, const sf::Vector2f &scale) {
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



sf::Sprite SpriteFactory::createGhost(GhostType type, const int alternative, const int posX, const int posY, const sf::Vector2f &scale) {
    const int offset_top_x=1;
    const int offset_top_y=4;
    const int size=35;
    const int separator=15;

    int x;
    switch (type) {
        case GhostType::Blinky:
            x = offset_top_x;
            break;
        case GhostType::Pinky:
            x = offset_top_x + size + separator;
            break;
        case GhostType::Inky:
            x = offset_top_x + 2*(size + separator);
            break;
        case GhostType::Clyde:
            x = offset_top_x + 3*(size + separator);
            break;
        default:
            break;
    };
    int y = offset_top_y + alternative * (size + separator);
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX, posY), scale);
}

sf::Sprite SpriteFactory::createPacMan(const int alternative, const int posX, const int posY, const sf::Vector2f &scale) {
    const int offset_top_x=853;
    const int offset_top_y=5;
    const int size=33;
    const int separator=17;

    int x = offset_top_x;
    int y = offset_top_y + alternative * (size + separator);
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX, posY), scale);
}