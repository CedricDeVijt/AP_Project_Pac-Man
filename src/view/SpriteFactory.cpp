#include "SpriteFactory.h"

SpriteFactory::SpriteFactory() {
    // Load a texture (replace "your_image.png" with the actual filename)
    if (!texture.loadFromFile("resources/Sprites.png")) {
        throw std::runtime_error("Failed to load texture");
    }
}

sf::Sprite SpriteFactory::createSprite(const sf::Vector2f &position, const sf::Vector2f &scale) {
    // Set up the texture rectangle to select the desired sprite on the sheet
    sf::IntRect textureRect(0, 0, 32, 32);

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

sf::Sprite SpriteFactory::createGhost() {
    // type: red blue,....
    // alternative 0, 1 (gebruikt om te lopen)

    return createSprite(sf::Vector2f(100, 100), sf::Vector2f(10, 10));
}