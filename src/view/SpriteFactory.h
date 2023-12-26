#ifndef AP_PROJECT_PAC_MAN_SPRITEFACTORY_H
#define AP_PROJECT_PAC_MAN_SPRITEFACTORY_H

#include <SFML/Graphics.hpp>

class SpriteFactory {
public:
    SpriteFactory();

    ~SpriteFactory() = default;

    sf::Sprite createGhost();

private:
    sf::Texture texture;

    sf::Sprite createSprite(const sf::Vector2f &position, const sf::Vector2f &scale);

};


#endif //AP_PROJECT_PAC_MAN_SPRITEFACTORY_H
