#include "SpriteFactory.h"
#include "../util/Singleton.h"
#include "Window.h"

// Define the static instance of the singleton
SpriteFactory::SpriteFactory() {
    // Load a texture (replace "your_image.png" with the actual filename)
    if (!texture.loadFromFile("resources/sprites/Sprites.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    if (!levelTexture.loadFromFile("resources/sprites/PacMan_Logo.png")) {
        throw std::runtime_error("Failed to load texture");
    }
}

sf::Sprite SpriteFactory::createSprite(sf::IntRect textureRect, const sf::Vector2f& position,
                                       const sf::Vector2f& scale) const {
    // Create a sprite and set its texture and texture rectangle
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(textureRect);

    // Set the position of the sprite
    sprite.setPosition(position);
    // Set the scale of the sprite
    sprite.setScale(scale);

    return sprite;
}

sf::Sprite SpriteFactory::createGhost(GhostType type, const int alternative, const int posX, const int posY,
                                      const int gridSize) const {
    // offsets for finding the appropriate sprite in the image file
    constexpr int offset_top_x = 1;
    constexpr int offset_top_y = 4;
    constexpr int offset_fear_y = 554;
    constexpr int size = 35;
    constexpr int separator = 15;

    // determine the scale factor using a margin around the image
    constexpr int margin = 10;
    const double scaleFactor = gridSize / (size + margin + 0.0);

    // determine the x-offset for a particular ghost type
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
        x = 0;
    }

    // determine the y-offset for a particular ghost type
    int y;
    switch (type) {
    case GhostType::Fear:
        y = offset_fear_y + alternative * (size + separator);
        break;
    default:
        y = offset_top_y + alternative * (size + separator);
        break;
    }

    // create the sprite
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX + margin / 2, posY + margin / 2),
                        sf::Vector2f(scaleFactor, scaleFactor));
}

sf::Sprite SpriteFactory::createPacMan(const int alternative, const int posX, const int posY,
                                       const int gridSize) const {
    // offsets for finding the appropriate sprite in the image file
    constexpr int offset_top_x = 853;
    constexpr int offset_top_y = 5;
    constexpr int size = 33;
    constexpr int separator = 17;

    // determine the scale factor using a margin around the image
    constexpr int margin = 10;
    const double scaleFactor = gridSize / (size + margin + 0.0);

    // determine the x and y-offset for a particular alternative
    constexpr int x = offset_top_x;
    const int y = offset_top_y + alternative * (size + separator);

    // create the sprite
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX + margin / 2, posY + margin / 2),
                        sf::Vector2f(scaleFactor, scaleFactor));
}

sf::Sprite SpriteFactory::createFruit(const int alternative, const int posX, const int posY, const int gridSize) const {
    // offsets for finding the appropriate sprite in the image file
    constexpr int offset_top_x = 601;
    constexpr int offset_top_y = 3;
    constexpr int size = 36;
    constexpr int separator = 14;
    constexpr int margin = 20;

    // determine the scale factor using a margin around the image
    constexpr int x = offset_top_x;
    const int y = offset_top_y + alternative * (size + separator);
    const double scaleFactor = gridSize / (size + margin + 0.0);

    // create the sprite
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX + margin / 2, posY + margin / 2),
                        sf::Vector2f(scaleFactor, scaleFactor));
}

sf::Sprite SpriteFactory::createCoin(const int posX, const int posY, const int gridSize) const {
    // offsets for finding the appropriate sprite in the image file
    constexpr int offset_top_x = 411;
    constexpr int offset_top_y = 313;
    constexpr int size = 16;

    // determine the scale factor using a margin around the image
    constexpr int margin = 50;
    const double scaleFactor = gridSize / (size + margin + 0.0);

    // determine the x and y-offset
    constexpr int x = offset_top_x;
    constexpr int y = offset_top_y;

    // create the sprite
    return createSprite(sf::IntRect(x, y, size, size), sf::Vector2f(posX + margin / 2, posY + margin / 2),
                        sf::Vector2f(scaleFactor, scaleFactor));
}

sf::Sprite SpriteFactory::createLogo() const {
    // get the sprite
    sf::Sprite sprite;
    sprite.setTexture(levelTexture);

    // determine origin
    const sf::FloatRect spriteBounds = sprite.getLocalBounds();
    sprite.setOrigin(spriteBounds.width / 2, 0);

    const auto window = Singleton<Window>::getInstance().getWindow();
    // Update the position and scale of the sprite based on window size
    sprite.setPosition(window->getSize().x / 2, 0);
    sprite.setScale(static_cast<float>(window->getSize().x) / spriteBounds.width,
                    static_cast<float>(window->getSize().x) / spriteBounds.width);

    return sprite;
}
