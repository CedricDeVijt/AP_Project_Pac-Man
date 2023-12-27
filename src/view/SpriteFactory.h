#ifndef AP_PROJECT_PAC_MAN_SPRITEFACTORY_H
#define AP_PROJECT_PAC_MAN_SPRITEFACTORY_H

#include <SFML/Graphics.hpp>

enum class GhostType {
    Blinky, Pinky, Inky, Clyde
};


class SpriteFactory {
public:
    SpriteFactory();

    ~SpriteFactory() = default;

    sf::Sprite createGhost(GhostType type, const int alternative, const int posX, const int posY, const sf::Vector2f &scale);
    sf::Sprite createPacMan(int alternative, const int posX, const int posY, const sf::Vector2f &scale);

private:
    sf::Texture texture;

    sf::Sprite createSprite(sf::IntRect textureRect, const sf::Vector2f &position, const sf::Vector2f &scale);

};


#endif //AP_PROJECT_PAC_MAN_SPRITEFACTORY_H
