#ifndef AP_PROJECT_PAC_MAN_SPRITEFACTORY_H
#define AP_PROJECT_PAC_MAN_SPRITEFACTORY_H

#include "../model/Ghost.h"
#include <SFML/Graphics.hpp>

/**
 * @class SpriteFactory
 * @brief Handles the loading and creation of sprites for different game entities.
 */
class SpriteFactory {
private:
    // Private constructor to prevent external instantiation
    SpriteFactory();
    ~SpriteFactory() = default;
    sf::Texture texture, levelTexture;

    /**
     * @brief Creates an SFML sprite with specified properties.
     * @param textureRect The texture rectangle for the sprite.
     * @param position The position of the sprite.
     * @param scale The scale of the sprite.
     * @return The created SFML sprite.
     */
    sf::Sprite createSprite(sf::IntRect textureRect, const sf::Vector2f& position, const sf::Vector2f& scale) const;

public:
    // Static method to get the instance of the singleton
    static SpriteFactory& getInstance();

    /**
     * @brief Creates a ghost sprite based on type, alternative, position, and grid size.
     * @param type The type of the ghost.
     * @param alternative The alternative variant of the ghost.
     * @param posX The X position of the sprite.
     * @param posY The Y position of the sprite.
     * @param gridSize The size of the grid cell.
     * @return The created ghost sprite.
     */
    sf::Sprite createGhost(GhostType type, int alternative, int posX, int posY, int gridSize) const;

    /**
     * @brief Creates a Pac-Man sprite based on alternative, position, and grid size.
     * @param alternative The alternative variant of Pac-Man.
     * @param posX The X position of the sprite.
     * @param posY The Y position of the sprite.
     * @param gridSize The size of the grid cell.
     * @return The created Pac-Man sprite.
     */
    sf::Sprite createPacMan(int alternative, int posX, int posY, int gridSize) const;

    /**
     * @brief Creates a fruit sprite based on alternative, position, and grid size.
     * @param alternative The alternative variant of the fruit.
     * @param posX The X position of the sprite.
     * @param posY The Y position of the sprite.
     * @param gridSize The size of the grid cell.
     * @return The created fruit sprite.
     */
    sf::Sprite createFruit(int alternative, int posX, int posY, int gridSize) const;

    /**
     * @brief Creates a coin sprite based on position and grid size.
     * @param posX The X position of the sprite.
     * @param posY The Y position of the sprite.
     * @param gridSize The size of the grid cell.
     * @return The created coin sprite.
     */
    sf::Sprite createCoin(int posX, int posY, int gridSize) const;

    /**
     * @brief Creates a logo sprite.
     * @return The created logo sprite.
     */
    sf::Sprite createLogo() const;

    // Prevent copying and assignment
    SpriteFactory(const SpriteFactory&) = delete;
    SpriteFactory& operator=(const SpriteFactory&) = delete;
};

#endif // AP_PROJECT_PAC_MAN_SPRITEFACTORY_H
