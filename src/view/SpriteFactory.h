#ifndef AP_PROJECT_PAC_MAN_SPRITEFACTORY_H
#define AP_PROJECT_PAC_MAN_SPRITEFACTORY_H

#include <SFML/Graphics.hpp>
#include "../model/Ghost.h"

class SpriteFactory {
private:
    // Private constructor to prevent external instantiation
    SpriteFactory();
    ~SpriteFactory() = default;
    sf::Texture texture;
    sf::Sprite createSprite(sf::IntRect textureRect, const sf::Vector2f &position, const sf::Vector2f &scale);

public:
    // Static method to get the instance of the singleton
    static SpriteFactory& getInstance();

    sf::Sprite createGhost(GhostType type, const int alternative, const int posX, const int posY, const sf::Vector2f &scale);
    sf::Sprite createPacMan(int alternative, const int posX, const int posY, const sf::Vector2f &scale);
    sf::Sprite createFruit(int alternative, const int posX, const int posY, const sf::Vector2f &scale);
    sf::Sprite createCoin(const int posX, const int posY, const sf::Vector2f &scale);

    // Prevent copying and assignment
    SpriteFactory(const SpriteFactory&) = delete;
    SpriteFactory& operator=(const SpriteFactory&) = delete;

};


#endif //AP_PROJECT_PAC_MAN_SPRITEFACTORY_H
